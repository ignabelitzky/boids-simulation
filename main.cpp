#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "utils.h"
#include "boid.h"
#include "params.h"
#include "slider.h"

void update(std::vector<Boid>& flock) {
    for(size_t i = 0; i < flock.size(); ++i) {
        flock[i].edges();
        flock[i].flock(flock);
        flock[i].update();
    }
}

void render(sf::RenderWindow& window, sf::Sprite& background, std::vector<Boid>& flock, std::vector<sf::CircleShape>& fishes, std::vector<Slider>& sliders, std::vector<sf::Text>& texts) {
    // Clear the window
    window.clear(sf::Color::Blue);

    window.draw(background);
    
    for(int i = 0; i < Config::NUM_BOIDS; ++i) {
        float angle = std::atan2(flock[i].getVelocity().second, flock[i].getVelocity().first) * 180.0f / M_PI;
        fishes[i].setPosition(flock.at(i).getPosition().first, flock.at(i).getPosition().second);
        fishes[i].setRotation(angle);
        window.draw(fishes[i]);
    }

    for(size_t i = 0; i < sliders.size(); ++i)
        sliders[i].draw(window);

    for(size_t i = 0; i < texts.size(); ++i)
        window.draw(texts[i]);
    
    window.display();
}

int main() {
    const sf::Time TimePerFrame = sf::seconds(1.0f / Config::FPS);

    sf::Texture texture;
    if(!texture.loadFromFile("./resources/images/fish.png")) {
        std::cout << "Error loading fish image!" << std::endl;
    }

    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("./resources/images/sea.jpg")) {
        std::cout << "Error loading background image!" << std::endl;
    }

    sf::Sprite backgroundImage(backgroundTexture);

    sf::Font font;
    if(!font.loadFromFile("./resources/fonts/arial/arial_bold.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }

    // Initialise boids
    std::vector<Boid> flock;
    std::vector<sf::CircleShape> fishes;
    std::vector<Slider> sliders;
    std::vector<sf::Text> texts;
    initialise_boids(flock);
    initialise_fishes(fishes, texture);
    initialise_sliders(flock, sliders);
    initialise_texts(font, texts);

    sf::RenderWindow window(sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), "Boids Simulation by Ignacio Belitzky");
    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;

    sf::Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(windowSize.y) / backgroundTexture.getSize().y;
    backgroundImage.setScale(scaleX, scaleY);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            for(size_t i = 0; i < sliders.size(); ++i)
                sliders[i].handleEvent(event);
        }

        // Calculate elapsed time since the las frame
        sf::Time deltaTime = clock.restart();
        elapsedTime += deltaTime;
        while(elapsedTime >= TimePerFrame) {
            elapsedTime -= TimePerFrame;
            update(flock);
        }
        // Render at every iteration
        render(window, backgroundImage, flock, fishes, sliders, texts);
    }
    return 0;
}
