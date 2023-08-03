#include <fstream>
#include <iostream>
#include <sstream>
#include "Graphics.h"
#include "HashMap.h"

int main()
{
    // make the data structures
    HashMap map(200);

    map.get_csv("output_extra_clean/output_extra_clean.csv");

    std::vector<int> fakeData = {1, 2, 3, 4, 5, 6, 7, 255, 1000, 1001, 10000000};

    // GUI loop
    Graphics GUI;
    while (GUI.window.isOpen())
    {

        GUI.eventHandling();

        // set up and render frame
        GUI.window.clear();
        GUI.drawConstants();
        GUI.drawGraph(fakeData);
        GUI.window.display();
    }
}