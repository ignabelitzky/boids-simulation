#ifndef _PARAMS_H_
#define _PARAMS_H_

namespace Config {
    const int WINDOW_WIDTH = 1920;
    const int WINDOW_HEIGHT = 1080;
    const int NUM_BOIDS = 800;
    const float FPS = 60.0f;
    const int BOID_RADIUS = 10;
    const float MAX_SPEED = 4.0f;
    const float MAX_FORCE = 0.5f;
    const float MAX_VELOCITY = 3.0f;
    const float MAX_ACCELERATION = 1.0f;
    const float PERCEPTION_RADIUS = 60.0f;
    const float MIN_DISTANCE = 0.001f;
}
#endif