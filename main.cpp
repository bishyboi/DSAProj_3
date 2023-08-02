#include "Graphics.h"

struct song {
    std::string language;
    int ExpLyrics;
    int year;
};

int main()
{

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