#ifndef _BOID_H_
#define _BOID_H_

#include <vector>
#include <utility>

class Boid {
    private:
        std::pair<float, float> position;
        std::pair<float, float> velocity;
        std::pair<float, float> acceleration;
        float perceptionRadius;
        float alignSpeed;
        float alignForce;
        float cohesionSpeed;
        float cohesionForce;
        float separationSpeed;
        float separationForce;
        float updateSpeed;
    public:
        Boid(const std::pair<float, float>& initialPosition, const std::pair<float, float>& initialVelocity, const std::pair<float, float>& initialAcceleration);
        ~Boid();

        // Getter methods
        std::pair<float, float> getPosition() const;
        std::pair<float, float> getVelocity() const;
        std::pair<float, float> getAcceleration() const;
        float getPerceptionRadius() const;
        float getAlignSpeed() const;
        float getAlignForce() const;
        float getCohesionSpeed() const;
        float getCohesionForce() const;
        float getSeparationSpeed() const;
        float getSeparationForce() const;

        // Setter methods
        void setPosition(const std::pair<float, float>& newPosition);
        void setVelocity(const std::pair<float, float>& newVelocity);
        void setAcceleration(const std::pair<float, float>& newAcceleration);
        void setPerceptionRadius(float radius);
        void setAlignSpeed(float speed);
        void setAlignForce(float force);
        void setCohesionSpeed(float speed);
        void setCohesionForce(float force);
        void setSeparationSpeed(float speed);
        void setSeparationForce(float force);


        void update();
        std::pair<float, float> align(std::vector<Boid>& boids);
        std::pair<float, float> cohesion(std::vector<Boid>& boids);
        std::pair<float, float> separation(std::vector<Boid>& boids);
        void flock(std::vector<Boid>& boids);
        void edges();
};

#endif