#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#define START_YEAR 1950
#define END_YEAR 2008

class Graphics
{
private:
    bool acceptingText = false;
    std::string textBoxString;

    // constant shapes to draw
    sf::RectangleShape textBack;
    sf::Font font;
    sf::Text textLang;

    // lists of objects
    std::vector<sf::Text> xLabels;
    std::vector<sf::Text> yLabels;
    std::vector<sf::RectangleShape> axisBars;
    std::vector<sf::RectangleShape> graphBars;
    std::vector<sf::Text> dataLabels;

    // timers
    sf::Text timer1;
    sf::Text timer2;

public:
    sf::RenderWindow window;
    Graphics();

    // drawing functions
    void drawConstants();
    void drawGraph(std::vector<int> data);
    void eventHandling();
};
