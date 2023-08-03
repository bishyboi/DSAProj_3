#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include "song.h"

class HashMap
{
private:
    std::vector<std::vector<song>> container;
    int hash(std::string language);
    int capacity;
    int size;

public:
    HashMap(int cap);
    std::vector<song> *search(std::string language);
    void insert(song newSong);
    void get_csv(const std::string &filename);
};
