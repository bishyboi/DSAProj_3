#include "Heap.h"

Heap::Heap(int capacity_)
{
    capacity = capacity_;
    list = new node[capacity];
    size = 0;
}

void Heap::insert(song s)
{
    bool emplaced = false; // Boolean to see if a song was emplaced in a list.
    for (int i = 0; i < size; i++)
    {
        if (s.year == list[i].year)
        { // if a given year exist, emplace the song data at the given node and stop the loop
            list[i].songList.push_back(s);
            emplaced = true;
        }
        if (emplaced)
        {
            break;
        }
    }
    if (!emplaced) // if a song has not been emplaced, make a new node for that year
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
    for (int i = 0; i < size; i++)
    {
        std::cout << "Song data for: " << list[i].year << std::endl;
        for (unsigned int j = 0; j < list[i].songList.size(); j++)
        {
            std::cout << list[i].songList[j].language << " " << list[i].songList[j].ExpLyrics << std::endl;
        }
    }
}

void Heap::heapifyUp(int index)
{
    int parent = (index - 1) / 2;
    if (list[index].year > list[parent].year)
    {
        std::swap(list[index], list[parent]);
        heapifyUp(parent);
    }
}

std::string Heap::algo(const std::string &language)
{
    auto start = std::chrono::high_resolution_clock::now();

    // pull out the list of that language

    // create data holders
    std::vector<int> result;
    result.resize((END_YEAR - START_YEAR) + 1);

    std::vector<int> tally;
    tally.resize((END_YEAR - START_YEAR) + 1);

    for (int i = 0; i < this->size; i++)
    {
        for (auto song : this->list[i].songList)
        {
            if (song.language == language)
            {
                result[i] += song.ExpLyrics;
            }

            tally[i]++;
        }
    }

    // average the data for each year and round to int
    for (int i = 0; i < result.size(); i++)
    {
        if (tally[i] == 0)
        {
            result[i] = -1;
        }
        else
        {
            result[i] = result[i] / tally[i];
        }
    }

    // stop timer
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    return std::to_string(duration.count());
}