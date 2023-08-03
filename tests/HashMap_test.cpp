#include "../HashMap.h"
#include "../HashMap.cpp"
#include "../song.h"
#include <vector>
#include <iostream>

int main()
{
    std::cout << "Initializing map..." << std::endl;
    HashMap map (1000);

    std::cout << "Map initialized." << std::endl;
    map.get_csv("../output_extra_clean/output_extra_clean100.csv");

    auto data = map.search("spanish");

    for(auto song: *data)
    {
        std::cout<< "# of Explicit Lyrics: " << song.ExpLyrics << std::endl;
    }
    return 0;
}