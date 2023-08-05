#include <valarray>
#include <iostream>
#include "Graphics.h"
Graphics::Graphics() {
    window.create(sf::VideoMode(900,600),"Group project");
    textBoxString = "Enter Language";

    textBack.setSize(sf::Vector2f(200,20));
    textBack.setFillColor(sf::Color::White);
    textBack.setPosition(sf::Vector2f(875/2-(textBack.getSize().x/2),30));

    //set up texts
    font.loadFromFile( "fonts/times.ttf");

    textLang.setFont(font);
    textLang.setCharacterSize(18);
    textLang.setFillColor(sf::Color::Red);
    textLang.setPosition(textBack.getPosition().x + 5,textBack.getPosition().y - 3);


    for(int i = 0; i <= END_YEAR - START_YEAR; i++) {
        xLabels.emplace_back(sf::Text());
        xLabels[i].setString(std::to_string((START_YEAR+i)%100));
        if(xLabels[i].getString().getSize() < 2) {
            xLabels[i].setString("0" + xLabels[i].getString());
        }
        xLabels[i].setFont(font);
        xLabels[i].setFillColor(sf::Color::White);
        xLabels[i].setCharacterSize(12);
        xLabels[i].setPosition(i*(850/(END_YEAR - START_YEAR)) + 25,550);
        xLabels[i].setRotation(315.f);
    }

    for(int i = 0; i < 11; i++) {
        yLabels.emplace_back(sf::Text());
        yLabels[i].setString("0");
        yLabels[i].setFillColor(sf::Color::White);
        yLabels[i].setFont(font);
        yLabels[i].setPosition(0, 82 + (i* 45));
        yLabels[i].setCharacterSize(12);
    }

    for(int i = 0; i < 2; i++) {
        axisBars.emplace_back(sf::RectangleShape());
        axisBars[i].setPosition(25,540);
        axisBars[i].setRotation(i* 270);
        axisBars[i].setFillColor(sf::Color::White);
        axisBars[i].setSize(sf::Vector2f(845 - (i*390),3));
    }

    timer1.setFont(font);
    timer1.setFillColor(sf::Color::White);
    timer1.setCharacterSize(18);
    timer1.setPosition(sf::Vector2f(textBack.getSize().x + textBack.getPosition().x + 10,textBack.getPosition().y - 10));

    timer2.setFont(font);
    timer2.setFillColor(sf::Color::White);
    timer2.setCharacterSize(18);
    timer2.setPosition(sf::Vector2f(textBack.getSize().x + textBack.getPosition().x + 10,textBack.getPosition().y + 10));
}

void Graphics::drawConstants(std::string time1, std::string time2) {
    window.draw(textBack);

    textLang.setString(textBoxString);
    window.draw(textLang);

    std::string string1 = timer1.getString();
    string1 = string1 + time1;
    timer1.setString(string1);

    std::string string2 = timer2.getString();
    string2 = string2 + time2;
    timer2.setString(string2);

    window.draw(timer1);
    window.draw(timer2);

    timer1.setString("Hash map's time (micro s): ");
    timer2.setString("Heap's time (micro s): ");

    for(int i = 0; i < xLabels.size(); i++) {
        window.draw(xLabels[i]);
    }
    for(int i = 0; i < yLabels.size(); i++){
        window.draw(yLabels[i]);
    }
    for(int i = 0; i < axisBars.size(); i++) {
        window.draw(axisBars[i]);
    }


}

void Graphics::drawGraph(std::vector<double> data) {
    //clear old data
    graphBars.clear();
    dataLabels.clear();

    //y axis scaling
    float largestBar = 0;
    for(int i = 0; i < data.size(); i++) {
        if (data[i] > largestBar)
            largestBar = data[i];
    }

    largestBar = std::pow(10.0,std::ceil(std::log10(largestBar)));

    for(int i = 0; i < 11; i++) {
        yLabels[i].setString(std::to_string(int((largestBar/10)*(10-i))));
    }

    //make bars for graph
    for(int i = 0; i < data.size(); i++) {
        graphBars.emplace_back(sf::RectangleShape());
        graphBars[i].setFillColor(sf::Color::Cyan);
        graphBars[i].setPosition(i*(850/(END_YEAR - START_YEAR)) +28 + (850/(END_YEAR - START_YEAR)),540);
        if(data[i] != -1) {
            graphBars[i].setSize(sf::Vector2f(850 / (END_YEAR - START_YEAR), 450 * (data[i] / largestBar)));
        }
        graphBars[i].setRotation(180);
    }

    //draw bars for graph
    for(int i = 0;i < graphBars.size(); i++) {
        window.draw(graphBars[i]);
    }

    //set up data labels
    for(int i = 0; i < data.size(); i++) {
        dataLabels.emplace_back(sf::Text());
        if(data[i] != -1) {
            dataLabels[i].setString(std::to_string(data[i]).substr(0, 3));
        }
        else {
            dataLabels[i].setString("Null");
        }
        dataLabels[i].setFont(font);
        dataLabels[i].setFillColor(sf::Color::White);
        dataLabels[i].setCharacterSize(12);
        dataLabels[i].setRotation(270);
        dataLabels[i].setPosition(sf::Vector2f(graphBars[i].getPosition().x-(850/(END_YEAR - START_YEAR) + 2),535 - graphBars[i].getSize().y));
    }

    //draw data labels for graph
    for(int i = 0; i < dataLabels.size(); i++) {
        window.draw(dataLabels[i]);
    }
}