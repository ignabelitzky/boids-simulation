#include "boid.h"
#include "utils.h"
#include "params.h"

Boid::Boid() {

}

Boid::Boid(const std::pair<float, float>& initialPosition, const std::pair<float ,float>& initialVelocity, const std::pair<float, float>& initialAcceleration) :
    position(initialPosition), velocity(initialVelocity), acceleration(initialAcceleration) {
        maxSpeed = 4.0f;
        maxForce = 2.0f;
}

Boid::~Boid() {

}

std::pair<float, float> Boid::getPosition() const {
    return position;
}

std::pair<float, float> Boid::getVelocity() const {
    return velocity;
}

std::pair<float, float> Boid::getAcceleration() const {
    return acceleration;
}

void Boid::setPosition(const std::pair<float, float>& newPosition) {
    position = newPosition;
}

void Boid::setVelocity(const std::pair<float, float>& newVelocity) {
    velocity = newVelocity;
}

void Boid::setAcceleration(const std::pair<float, float>& newAcceleration) {
    acceleration = newAcceleration;
}

void Boid::update() {
    position.first += velocity.first;
    position.second += velocity.second;
    velocity.first += acceleration.first;
    velocity.second += acceleration.second;
}

std::pair<float, float> Boid::align(std::vector<Boid>& boids) {
    float perceptionRadius = 50.0f;
    std::pair<float, float> steering(0.0f, 0.0f);
    int total = 0;
    for(size_t i = 0; i < boids.size(); ++i) {
        float distance = calculate_distance(position, boids[i].getPosition());
        if(distance > 0.05 && distance < perceptionRadius) {
            steering.first += boids[i].getVelocity().first;
            steering.second += boids[i].getVelocity().second;
            ++total;
        }
    }
    if(total > 0) {
        steering.first /= total;
        steering.second /= total;
        steering = setMag(steering, maxSpeed);
        steering.first -= velocity.first;
        steering.second -= velocity.second;
        steering = limit(steering, maxForce);
    }
    return steering;
}

void Boid::flock(std::vector<Boid>& boids) {
    std::pair<float, float> alignment = align(boids);
    acceleration.first = alignment.first;
    acceleration.second = alignment.second;
}

void Boid::edges() {
    if(position.first > Config::WINDOW_WIDTH) {
        position.first = 0.0f;
    } else if(position.first < 0.0f) {
        position.first = Config::WINDOW_WIDTH;
    }
    if(position.second > Config::WINDOW_HEIGHT) {
        position.second = 0.0f;
    } else if(position.second < 0.0f) {
        position.second = Config::WINDOW_HEIGHT;
    }
}