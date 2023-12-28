#ifndef UTILS_H_
#define UTILS_H_

#include <SFML/Graphics.hpp>
#include <string>
#include "boid.h"
#include "slider.h"

int generate_random_int(int min, int max);

float generate_random_float(float min, float max);

float calculate_distance(std::pair<float, float> fstPosition, std::pair<float, float> sndPosition);

void changeAlignSpeed(float value, std::vector<Boid>& boids);

void changeCohesionSpeed(float value, std::vector<Boid>& boids);

void changeSeparationSpeed(float value, std::vector<Boid>& boids);

void changeAlignForce(float value, std::vector<Boid>& boids);

void changeCohesionForce(float value, std::vector<Boid>& boids);

void changeSeparationForce(float value, std::vector<Boid>& boids);

void initialise_boids(std::vector<Boid>& boids);

void initialise_fishes(std::vector<sf::CircleShape>& fishes, sf::Texture& texture);

void initialise_sliders(std::vector<Boid>& boids, std::vector<Slider>& sliders);

float magnitude(const std::pair<float, float>& v);

std::pair<float, float> setMag(const std::pair<float, float>& v, float newMagnitude);

std::pair<float, float> limit(const std::pair<float, float>& v, float maxMagnitude);

std::pair<float, float>& operator+=(std::pair<float, float>& pair1, const std::pair<float, float>& pair2);

#endif
