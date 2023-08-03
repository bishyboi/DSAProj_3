#include <fstream>
#include <iostream>
#include "Graphics.h"
#include "HashMap.h"

int main()
{

    HashMap map(200);
    std::string line;
    std::fstream file("wasabi_songs.csv/wasabi_songs.csv",std::ios::in);
    if(file.is_open()) {
        getline(file, line);
        std::cout << line;
        getline(file, line);
        getline(file, line);
        getline(file, line);
        getline(file, line);
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