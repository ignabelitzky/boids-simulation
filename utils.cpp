#include <random>
#include <iostream>
#include "utils.h"
#include "params.h"

int generate_random_int(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

float generate_random_float(float min, float max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(gen);
}

float calculate_distance(std::pair<float, float> fstPosition, std::pair<float, float> sndPosition) {
    return std::sqrt(std::pow(sndPosition.first - fstPosition.first, 2) + std::pow(sndPosition.second - fstPosition.second, 2));
}

void changeAlignSpeed(float value, std::vector<Boid>& boids) {
    for(size_t i = 0; i < boids.size(); ++i) {
        boids[i].setAlignSpeed(value);
    }
}

void changeCohesionSpeed(float value, std::vector<Boid>& boids) {
    for(size_t i = 0; i < boids.size(); ++i) {
        boids[i].setCohesionSpeed(value);
    }
}

void changeSeparationSpeed(float value, std::vector<Boid>& boids) {
    for(size_t i = 0; i < boids.size(); ++i) {
        boids[i].setSeparationSpeed(value);
    }
}

void changeAlignForce(float value, std::vector<Boid>& boids) {
    for(size_t i = 0; i < boids.size(); ++i) {
        boids[i].setAlignForce(value);
    }
}

void changeCohesionForce(float value, std::vector<Boid>& boids) {
    for(size_t i = 0; i < boids.size(); ++i) {
        boids[i].setCohesionForce(value);
    }
}

void changeSeparationForce(float value, std::vector<Boid>& boids) {
    for(size_t i = 0; i < boids.size(); ++i) {
        boids[i].setSeparationForce(value);
    }
}

void initialise_boids(std::vector<Boid>& flock) {
    for(int i = 0; i < Config::NUM_BOIDS; ++i) {
        float xPosition = generate_random_float(0.0f, static_cast<float>(Config::WINDOW_WIDTH));
        float yPosition = generate_random_float(0.0f, static_cast<float>(Config::WINDOW_HEIGHT));
        std::pair<float, float> pos = std::make_pair(xPosition, yPosition);
        float xVelocity = generate_random_float(-Config::MAX_VELOCITY, Config::MAX_VELOCITY);
        float yVelocity = generate_random_float(-Config::MAX_VELOCITY, Config::MAX_VELOCITY);
        std::pair<float, float> vel = std::make_pair(xVelocity, yVelocity);
        float xAcceleration = generate_random_float(-Config::MAX_ACCELERATION, Config::MAX_ACCELERATION);
        float yAcceleration = generate_random_float(-Config::MAX_ACCELERATION, Config::MAX_ACCELERATION);
        std::pair<float, float> acc = std::make_pair(xAcceleration, yAcceleration);
        Boid boid(pos, vel, acc);
        flock.push_back(boid);
    }
}

void initialise_fishes(std::vector<sf::CircleShape>& fishes, sf::Texture& texture) {
    for(int i = 0; i < Config::NUM_BOIDS; ++i) {
        sf::CircleShape circle(Config::BOID_RADIUS);
        circle.setOrigin(circle.getRadius(), circle.getRadius());
        circle.setTexture(&texture);
        fishes.push_back(circle);
    }
}

void initialise_sliders(std::vector<Boid>& boids, std::vector<Slider>& sliders) {
    Slider alignSpeedSlider(1, 10, 3, sf::Vector2f(20, 50), 200, boids);
    alignSpeedSlider.setValueChangedCallback(changeAlignSpeed);
    sliders.push_back(alignSpeedSlider);

    Slider cohesionSpeedSlider(1, 10, 3, sf::Vector2f(20, 150), 200, boids);
    cohesionSpeedSlider.setValueChangedCallback(changeCohesionSpeed);
    sliders.push_back(cohesionSpeedSlider);

    Slider separationSpeedSlider(1, 10, 3, sf::Vector2f(20, 250), 200, boids);
    separationSpeedSlider.setValueChangedCallback(changeSeparationSpeed);
    sliders.push_back(separationSpeedSlider);

    Slider alignForceSlider(0.1f, 1.0f, 0.5f, sf::Vector2f(240, 50), 200, boids);
    alignForceSlider.setValueChangedCallback(changeAlignForce);
    sliders.push_back(alignForceSlider);

    Slider cohesionForceSlider(0.1f, 1.0f, 0.5f, sf::Vector2f(240, 150), 200, boids);
    cohesionForceSlider.setValueChangedCallback(changeCohesionForce);
    sliders.push_back(cohesionForceSlider);

    Slider separationForceSlider(0.1f, 1.0f, 0.5, sf::Vector2f(240, 250), 200, boids);
    separationForceSlider.setValueChangedCallback(changeSeparationForce);
    sliders.push_back(separationForceSlider);
}

void initialise_texts(sf::Font& font, std::vector<sf::Text>& texts) {
    sf::Text alignSpeedText("Align Speed", font, 20);
    alignSpeedText.setFillColor(sf::Color::White);
    alignSpeedText.setPosition(20, 10);

    sf::Text cohesionSpeedText("Cohesion Speed", font, 20);
    cohesionSpeedText.setFillColor(sf::Color::White);
    cohesionSpeedText.setPosition(20, 110);

    sf::Text separationSpeedText("Separation Speed", font, 20);
    separationSpeedText.setFillColor(sf::Color::White);
    separationSpeedText.setPosition(20, 210);

    sf::Text alignForceText("Align Force", font, 20);
    alignForceText.setFillColor(sf::Color::White);
    alignForceText.setPosition(240, 10);

    sf::Text cohesionForceText("Cohesion Force", font, 20);
    cohesionForceText.setFillColor(sf::Color::White);
    cohesionForceText.setPosition(240, 110);

    sf::Text separationForceText("Separation Force", font, 20);
    separationForceText.setFillColor(sf::Color::White);
    separationForceText.setPosition(240, 210);

    texts.push_back(alignSpeedText);
    texts.push_back(cohesionSpeedText);
    texts.push_back(separationSpeedText);
    texts.push_back(alignForceText);
    texts.push_back(cohesionForceText);
    texts.push_back(separationForceText);
}

float magnitude(const std::pair<float, float>& v) {
    return std::sqrt(v.first * v.first + v.second * v.second);
}

std::pair<float, float> setMag(const std::pair<float, float>& v, float newMagnitude) {
    float mag = magnitude(v);
    if(mag != 0) {
        float scaleFactor = newMagnitude / mag;
        return std::make_pair(v.first * scaleFactor, v.second * scaleFactor);
    } else {
        return v;
    }
}

std::pair<float, float> limit(const std::pair<float, float>& v, float maxMagnitude) {
    float mag = magnitude(v);
    if(mag > maxMagnitude) {
        float scaleFactor = maxMagnitude / mag;
        return std::make_pair(v.first * scaleFactor, v.second * scaleFactor);
    } else {
        return v;
    }
}

std::pair<float, float>& operator+=(std::pair<float, float>& pair1, const std::pair<float, float>& pair2) {
    pair1.first += pair2.first;
    pair1.second += pair2.second;
    return pair1;
}