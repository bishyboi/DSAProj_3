#include "Heap.h"

Heap::Heap(int capacity_) 
{
    capacity = capacity_;
    list = new node[capacity];
    size = 0;
}

void Heap::insert(song s){
    bool emplaced = false; //Boolean to see if a song was emplaced in a list.
    for (int i = 0; i < size; i++) {
        if (s.year == list[i].year) { //if a given year exist, emplace the song data at the given node and stop the loop
            list[i].songList.push_back(s);
            emplaced = true;
        }
        if (emplaced)
        {
            break;
        }
    }
    if (!emplaced) //if a song has not been emplaced, make a new node for that year
    {
        node tempNode;
        tempNode.year = s.year;
        tempNode.songList.push_back(s);
        list[size] = tempNode;
        size++;
    }
    if (size > 1)
    {
        heapifyUp(size - 1);
    }
}

void Heap::print()
{
    for (int i = 0; i < size; i++) {
        cout << "Song data for: " << list[i].year << endl;
        for (unsigned int j = 0; j < list[i].songList.size(); j++) {
            cout << list[i].songList[j].language << " " << list[i].songList[j].ExpLyrics << endl;
        }
    }
}

void Heap::heapifyUp(int index)
{
    int parent = (index - 1) / 2;
    if (list[index].year > list[parent].year) {
        swap(list[index], list[parent]);
        heapifyUp(parent);
    }
}