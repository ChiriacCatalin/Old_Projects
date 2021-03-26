#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <string>
class Button
{
    public:
        Button(std::string path,float x, float y,float x_dim, float y_dim);
        void draw(sf::RenderWindow &window);
        sf::Vector2f getPosition();
        void SetPath(std::string cale);
        void setPosition(float x,float y);
        sf::RectangleShape getForma();
        void setColor(sf::Color color);
        void setDrawn(bool value);
        bool getDrawn();
    private:
        sf::Texture texture;
        sf::RectangleShape forma;
        bool isDrawn=false;

};

#endif // BUTTON_H
