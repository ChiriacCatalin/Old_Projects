#include "Button.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Button::Button(std::string path,float x, float y,float x_dim, float y_dim)
{
    texture.loadFromFile(path);
    forma.setTexture(&texture);
    forma.setPosition(x,y);
    forma.setSize(sf::Vector2f(x_dim,y_dim));
}
void Button::SetPath(std::string cale)
{
    texture.loadFromFile(cale);
    forma.setTexture(&texture);
}
void Button::draw(sf::RenderWindow &window)
{
    window.draw(forma);
}
sf::Vector2f Button::getPosition()
{
    return forma.getPosition();
}
void Button::setPosition(float x, float y)
{
    forma.setPosition(x,y);
}
sf::RectangleShape Button::getForma()
{
    return forma;
}
void Button::setColor(sf::Color color)
{
    forma.setFillColor(color);
}
void Button::setDrawn(bool value)
{
    isDrawn=value;
}
bool Button::getDrawn()
{
    return isDrawn;
}

