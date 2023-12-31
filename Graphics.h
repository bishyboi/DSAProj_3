#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#define START_YEAR 1950
#define END_YEAR 2020

class Graphics {
private:

    //objects for axis label
    sf::Text xAxis;
    sf::Text yAxis;


    //constant shapes to draw
    sf::Font font;
    sf::Text textLang;

    //lists of objects
    std::vector<sf::Text> xLabels;
    std::vector<sf::Text> yLabels;
    std::vector<sf::RectangleShape> axisBars;
    std::vector<sf::RectangleShape> graphBars;
    std::vector<sf::Text> dataLabels;

    //timers
    sf::Text timer1;
    sf::Text timer2;

    //algorithm function
public:
    sf::RenderWindow window;
    Graphics();

    //drawing functions
    void drawConstants(std::string time1, std::string time2);
    void drawGraph(std::vector<double> data);

    //event handling data
    bool acceptingText = false;
    std::string textBoxString;
    sf::RectangleShape textBack;


};

