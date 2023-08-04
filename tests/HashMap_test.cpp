#include "../HashMap.h"
#include "../HashMap.cpp"
#include "../song.h"
#include <vector>
#include <iostream>

void get_csv_test()
{
    std::cout << "Initializing map..." << std::endl;
    HashMap map (1000);

    std::cout << "Map initialized." << std::endl;

    auto data = map.search("spanish");

    for(auto song: *data)
    {
        std::cout<< "# of Explicit Lyrics: " << song.ExpLyrics << std::endl;
    }
}

void insert_test()
{
    HashMap map(10);

    song temp;
    temp.ExpLyrics = 3;
    temp.language = "spanish";
    temp.year = 2003;

    map.insert(temp);
}

void algo_test()
{
    HashMap map(10000);

    map.Algo("english");
}

int main()
{
    algo_test();
    //get_csv_test();
    return 0;
}