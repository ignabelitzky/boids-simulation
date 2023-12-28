#include <iostream>
#include "slider.h"
#include "params.h"

Slider::Slider(float minValue, float maxValue, float defaultValue, sf::Vector2f position, float width, std::vector<Boid>& boids) :
    minValue(minValue), maxValue(maxValue), value(defaultValue), dragging(false), boids(boids) {
        slider.setPosition(position);
        slider.setSize(sf::Vector2f(width, 10));
        slider.setFillColor(sf::Color::White);

        knob.setRadius(10);
        knob.setFillColor(sf::Color::Red);

        updateKnobPosition();
}

float Slider::getValue() const {
    return value;
}

void Slider::setValueChangedCallback(std::function<void(float, std::vector<Boid>&)> callback) {
    valueChangedCallback = callback;
}

void Slider::handleEvent(sf::Event event) {
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        if(knob.getGlobalBounds().contains(mousePos)) {
            dragging = true;
        }
    } else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        dragging = false;
    } else if(event.type == sf::Event::MouseMoved && dragging) {
        float mouseX = static_cast<float>(event.mouseMove.x);
        float position = std::max(slider.getPosition().x, std::min(slider.getPosition().x + slider.getSize().x, mouseX));
        value = minValue + (position - slider.getPosition().x) / slider.getSize().x * (maxValue - minValue);
        updateKnobPosition();
        if(valueChangedCallback) {
            valueChangedCallback(value, boids);
        }
    }
}

void Slider::updateKnobPosition() {
    float percentage = (value - minValue) / (maxValue - minValue);
    float knobPosition = slider.getPosition().x + percentage * slider.getSize().x;
    knob.setPosition(knobPosition - knob.getRadius(), slider.getPosition().y - knob.getRadius());
}

void Slider::draw(sf::RenderWindow& window) const {
    window.draw(slider);
    window.draw(knob);
}

