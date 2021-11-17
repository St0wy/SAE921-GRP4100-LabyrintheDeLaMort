#include <SFML/Graphics.hpp>
#include "Hero.h"

constexpr int WINDOW_WIDTH = 900;
constexpr int WINDOW_HEIGHT = 600;
constexpr int FRAMERATE = 60;
constexpr char WINDOW_NAME[] = "Labyrinthe de la mort";

int main()
{
    std::default_random_engine gen;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Close);

    // Basic Setup of the window
    // Vertical sync, framerate
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(FRAMERATE);

    Hero hero(gen);
    hero.set_texture("data/hero.png");

    sf::Vector2f window_center(window.getSize());
    window_center /= 2.0f;
    hero.get_sprite().setPosition(window_center);

    while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis
        // la précédente itération
        sf::Event event{};

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                // évènement "fermeture demandée" : on ferme la fenêtre
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        // Graphical Region
        window.clear(sf::Color::Black);

        sf::Sprite& sprite = hero.get_sprite();
        window.draw(sprite);

        window.display();

    }
}