#pragma once
#include <SFML/Graphics.hpp>

class Graphics {
public:
    sf::RenderWindow window;
    std::string textBoxString;
    Graphics();

    //constant shapes to draw
    sf::RectangleShape textBack;

    //drawing functions
    void drawConstants();
    void drawGraph(std::vector<int>);
    void drawText();
};

