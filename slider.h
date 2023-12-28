#ifndef _SLIDER_H_
#define _SLIDER_H_

#include <SFML/Graphics.hpp>
#include <functional>
#include "boid.h"

class Slider {
    private:
        sf::RectangleShape slider;
        sf::CircleShape knob;
        float minValue;
        float maxValue;
        float value;
        bool dragging;
        std::vector<Boid>& boids;
        std::function<void(float, std::vector<Boid>&)> valueChangedCallback;
    public:
        Slider(float minValue, float maxValue, float defaultValue, sf::Vector2f position, float width, std::vector<Boid>& boids);
        float getValue() const;
        void setValueChangedCallback(std::function<void(float, std::vector<Boid>&)> callback);
        void handleEvent(sf::Event event);
        void updateKnobPosition();
        void draw(sf::RenderWindow& window) const;
};

#endif