#include <SFML/Graphics.hpp>

constexpr int WINDOW_WIDTH = 900;
constexpr int WINDOW_HEIGHT = 600;
constexpr int FRAMERATE = 60;
constexpr char WINDOW_NAME[] = "Labyrinthe de la mort";

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Close);

    // Basic Setup of the window
    // Vertical sync, framerate
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(FRAMERATE);

    sf::Texture hero;
    hero.loadFromFile("data/hero.png");

    sf::Sprite sprite;
    sprite.setTexture(hero);

    sf::Vector2f hero_sprite_center(hero.getSize());
    hero_sprite_center /= 2.0f;
    sprite.setOrigin(hero_sprite_center);

    sf::Vector2f window_center(window.getSize());
    window_center /= 2.0f;
    sprite.setPosition(window_center);

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

        window.draw(sprite);

        window.display();

    }
}