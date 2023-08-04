#pragma once
#include <iostream>
#include <vector>
#include "song.h"
#include <chrono>
#include <tuple>

//Max Heap
class Heap {
    struct node
    {
        int year = 0;
        std::vector<song> songList;
    };

    int capacity; //capacity of the heap
    int size; //current size of the heap
    node* list; //heap data structure
public:
    Heap(int capacity_);
    void insert(song s);
    void print(); //for debugging and testing
    void heapifyUp(int index); //helper function to do the heap work;
};