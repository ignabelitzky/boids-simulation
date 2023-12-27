#include <random>
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