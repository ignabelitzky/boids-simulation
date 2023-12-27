#ifndef UTILS_H_
#define UTILS_H_

#include "boid.h"

int generate_random_int(int min, int max);

float generate_random_float(float min, float max);

float calculate_distance(std::pair<float, float> fstPosition, std::pair<float, float> sndPosition);

void initialise_boids(std::vector<Boid>& boids);

float magnitude(const std::pair<float, float>& v);

std::pair<float, float> setMag(const std::pair<float, float>& v, float newMagnitude);

std::pair<float, float> limit(const std::pair<float, float>& v, float maxMagnitude);

#endif
