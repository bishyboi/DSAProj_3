#include "Graphics.h"
Graphics::Graphics() {
    window.create(sf::VideoMode(1200,800),"Group project");
    textBoxString = "Enter Language";

    textBack.setSize(sf::Vector2f(150,20));
    textBack.setFillColor(sf::Color::White);
    textBack.setPosition(sf::Vector2f(window.getSize().x/2-(150/2),50));
}

void Graphics::drawConstants() {
    window.draw(textBack);
}