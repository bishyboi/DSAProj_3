#include "Graphics.h"

int main()
{

    std::vector<int> fakeData = {200,300,550,44,23,200,999,0};
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