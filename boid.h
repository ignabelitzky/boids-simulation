#ifndef _BOID_H_
#define _BOID_H_

#include <vector>
#include <utility>

class Boid {
    private:
        std::pair<float, float> position;
        std::pair<float, float> velocity;
        std::pair<float, float> acceleration;
        float maxSpeed;
        float maxForce;
    public:
        Boid();
        Boid(const std::pair<float, float>& initialPosition, const std::pair<float, float>& initialVelocity, const std::pair<float, float>& initialAcceleration);
        ~Boid();

        // Getter methods
        std::pair<float, float> getPosition() const;
        std::pair<float, float> getVelocity() const;
        std::pair<float, float> getAcceleration() const;

        // Setter methods
        void setPosition(const std::pair<float, float>& newPosition);
        void setVelocity(const std::pair<float, float>& newVelocity);
        void setAcceleration(const std::pair<float, float>& newAcceleration);

        void update();
        std::pair<float, float> align(std::vector<Boid>& boids);
        void flock(std::vector<Boid>& boids);
        void edges();
};

#endif