#pragma once
#include <vector>
#include "song.h"
#include <chrono>
#include <tuple>

#define START_YEAR 1950
#define END_YEAR 2020

class HashMap {
private:
    std::vector<std::vector<song>> container;
    int hash(std::string language);
    int capacity;
    int size;
public:
    HashMap(int cap);
    std::vector<song>* search(std::string language);
    void insert(song newSong);
    std::tuple<std::vector<int>,std::string> Algo(std::string language);
};
