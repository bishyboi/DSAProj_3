#include "HashMap.h"

HashMap::HashMap(int cap)
{
    capacity = cap;
    size = 0;
    container.reserve(cap);
}

// hash function of the structure
int HashMap::hash(std::string language)
{
    int hash = 0;
    // string folding length two
    for (int i = 0; i < language.size(); i += 2)
    {
        if (i == language.size() - 1)
        {
            hash += int(language[i]);
        }
        else
        {
            hash += std::stoi(std::to_string(int(language[i])) + std::to_string(int(language[i + 1])));
        }
    }
    hash = hash % capacity;
    return hash;
}

void HashMap::insert(song newSong)
{
    // rehash if out of space
    int hashNum;
    if (size == capacity)
    {
        std::vector<std::vector<song>> temp = container;
        container.clear();
        capacity *= 2;
        container.reserve(capacity);
        // reinsert all data back into new hash map
        for (int i = 0; i < temp.size(); i++)
        {
            if (!temp[i].empty())
            {
                hashNum = hash(temp[i][0].language);
                container[hashNum] = temp[i];
            }
        }
    }
    hashNum = hash(newSong.language);

    bool placed = false;
    while (!placed)
    {
        if (container[hashNum].empty())
        {
            container[hashNum].emplace_back(newSong);
            placed = true;
        }
        else if (container[hashNum][0].language == newSong.language)
        {
            container[hashNum].emplace_back(newSong);
            placed = true;
        }
        else
        {
            // linear collision policy
            hashNum++;
            hashNum = hashNum % capacity;
        }
    }
    size++;
}

std::vector<song> *HashMap::search(std::string language)
{
    int hashNum = hash(language);

    while (true)
    {
        if (container[hashNum].empty())
        {
            // collision policy says doesnt exist
            return nullptr;
        }
        if (container[hashNum][0].language == language)
        {
            return &container[hashNum];
        }
        else
        {
            // linear collision policy
            hashNum++;
            hashNum = hashNum % capacity;
        }
    }
}

void HashMap::get_csv(const std::string &filename)
{
    // data for storing words
    std::vector<std::string> row;
    std::string entry;

    // open in the file and read each line
    std::string line;
    std::fstream file(filename, std::ios::in);
    if (file.is_open())
    {
        getline(file, line);
        while (!file.eof())
        {
            row.clear();
            getline(file, line);

            // break up the line into words
            std::stringstream s(line);
            while (getline(s, entry, ','))
            {
                row.emplace_back(entry);
            }
            // make a song object with data
            song temp;
            temp.ExpLyrics = std::stoi(row[0]);
            temp.language = row[1];
            temp.year = std::stoi(row[2]);

            // add data to data structure
            this->insert(temp);
        }
    }
}