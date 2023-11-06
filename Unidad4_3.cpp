#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 600), "3");

    sf::Texture redPointTexture;
    redPointTexture.loadFromFile("rcircle.png");

    sf::Texture bluePointTexture;
    bluePointTexture.loadFromFile("rcircleb.png");
    sf::Sprite puntoAzul(bluePointTexture);

    int x = 0, y = 0;
    std::vector<sf::Sprite> puntosRojos;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (puntoAzul.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    sf::Sprite puntoRojo(redPointTexture);
                    x += 128;
                    if (x > 1025) {
                        x = 0;
                        y += 128;
                    }
                    puntoRojo.setPosition(x, y);
                    puntosRojos.push_back(puntoRojo);
                }
            }
        }

        window.clear();

        puntoAzul.setPosition(0, 0);
        window.draw(puntoAzul);
        for (const sf::Sprite& puntoRojo : puntosRojos) {
            window.draw(puntoRojo);
        }

        window.display();
    }
}
