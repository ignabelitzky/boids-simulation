#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "utils.h"
#include "boid.h"
#include "params.h"

void update(std::vector<Boid>& flock) {
    for(size_t i = 0; i < flock.size(); ++i) {
        flock[i].edges();
        flock[i].flock(flock);
        flock[i].update();
    }
}

void render(sf::RenderWindow& window, std::vector<Boid>& flock) {
    // Clear the window
    window.clear();
    for(int i = 0; i < Config::NUM_BOIDS; ++i) {
        sf::CircleShape circle(Config::BOID_RADIUS);
        circle.setFillColor(sf::Color::Red);
        circle.setOrigin(circle.getRadius(), circle.getRadius());
        circle.setPosition(flock.at(i).getPosition().first, flock.at(i).getPosition().second);
        window.draw(circle);
    }
    window.display();
}

int main() {
    const sf::Time TimePerFrame = sf::seconds(1.0f / Config::FPS);

    // Initialise boids
    std::vector<Boid> flock;
    initialise_boids(flock);

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML Window");
    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // Calculate elapsed time since the las frame
        sf::Time deltaTime = clock.restart();
        elapsedTime += deltaTime;
        while(elapsedTime >= TimePerFrame) {
            elapsedTime -= TimePerFrame;
            update(flock);
        }
        // Render at every iteration
        render(window, flock);
    }
    return 0;
}
