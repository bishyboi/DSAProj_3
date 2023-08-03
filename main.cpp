#include <fstream>
#include <iostream>
#include <sstream>
#include "Graphics.h"
#include "HashMap.h"

int main()
{

    //make the data structures
    HashMap map(200);

    //data for storing words
    std::vector<std::string> row;
    std::string entry;

    //open in the file and read each line
    std::string line;
    std::fstream file("output_extra_clean/output_extra_clean.csv",std::ios::in);
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

    std::vector<int> fakeData = {1,2,3,4,5,6,7,255,1000,1001,10000000};
    //GUI loop
    Graphics GUI;
    while(GUI.window.isOpen()) {

        GUI.eventHandling();

        //set up and render frame
        GUI.window.clear();
        GUI.drawConstants();
        GUI.drawGraph(fakeData);
        GUI.window.display();
    }
}