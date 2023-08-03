#pragma once
#include <vector>
#include "song.cpp"
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

};
