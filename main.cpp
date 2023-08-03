#include <fstream>
#include <iostream>
#include <sstream>
#include "Graphics.h"
#include "HashMap.h"
#include <tuple>

int main()
{

    //make the data structures
    HashMap map(200);

    //data for storing words
    std::vector<std::string> row;
    std::string entry;

    //open in the file and read each line
    std::string line;
    std::fstream file("output_extra_clean/output_extra_clean1950.csv",std::ios::in);
    if(file.is_open()) {
        getline(file, line);
        while(!file.eof()) {
            row.clear();
            getline(file, line);

            //break up the line into words
            std::stringstream s(line);
            while(getline(s,entry,',')) {
                row.emplace_back(entry);
            }
            //make a song object with data
            song temp;
            temp.ExpLyrics = std::stoi(row[0]);
            temp.language = row[1];
            temp.year = std::stoi(row[2]);

            //add data to data structure
            map.insert(temp);
        }

    }

    //graphing data
    std::vector<int> Data = {0};
    long long dataTime1 = 0;

    //GUI loop
    Graphics GUI;
    while(GUI.window.isOpen()) {

        sf::Event event;

        //event handeling
        while(GUI.window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                GUI.window.close();

            if(event.type == sf::Event::MouseButtonPressed ) {
                //if mouse hits language button go into edit mode
                if(!GUI.acceptingText) {
                    if(GUI.textBack.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(GUI.window)))) {
                        GUI.acceptingText = true;
                        GUI.textBoxString = "";
                    }
                }
            }

            if (event.type == sf::Event::TextEntered && GUI.acceptingText) {
                //make sure character is english letter
                if ((event.text.unicode < 123 && event.text.unicode > 64) || event.text.unicode == 32) {
                    GUI.textBoxString.push_back(static_cast<char>(event.text.unicode));
                }
            }
            if(event.type == sf::Event::KeyPressed && GUI.acceptingText) {
                if(event.key.code == sf::Keyboard::BackSpace) {
                    if(!GUI.textBoxString.empty()) {
                        GUI.textBoxString.pop_back();
                    }
                }
                //if string is entered run algo on that language
                if(event.key.code == sf::Keyboard::Enter) {
                    auto temp = (map.Algo(GUI.textBoxString));
                    Data = std::get<0>(temp);
                    dataTime1 = std::get<1>(temp);
                    GUI.acceptingText = false;
                }
            }
        }

        //set up and render frame
        GUI.window.clear();
        GUI.drawConstants(dataTime1, 0);
        GUI.drawGraph(Data);
        GUI.window.display();
    }
}