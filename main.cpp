#include "Graphics.h"

int main()
{
    Graphics GUI;

    while(GUI.window.isOpen()) {
        sf::Event event;

        //event handeling
        while(GUI.window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                GUI.window.close();
        }

        GUI.window.clear();
        GUI.drawConstants();
        GUI.window.display();
    }
}