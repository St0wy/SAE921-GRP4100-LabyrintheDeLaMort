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
        window.clear(sf::Color::White);

        window.display();
    }
}