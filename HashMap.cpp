#include <cmath>
#include "HashMap.h"
HashMap::HashMap(int cap) {
    capacity = cap;
    size = 0;
    container.resize(cap);
}

//hash function of the structure
int HashMap::hash(std::string language) {
    int hash = 0;
    //string folding length two
    for (int i = 0; i < language.size(); i += 2) {
        if (i == language.size()-1) {
            hash += int(language[i]);
        }
        else {
            hash += std::stoi(std::to_string(int(language[i])) + std::to_string(int(language[i+1])));
        }
    }
    hash = hash % capacity;
    return hash;
}

void HashMap::insert(song newSong) {
    //rehash if out of space
    int hashNum;
    if(size == capacity) {
        std::vector<std::vector<song>> temp = container;
        container.clear();
        capacity *= 2;
        container.resize(capacity);
        //reinsert all data back into new hash map
        for(int i = 0; i < temp.size(); i ++) {
            if(!temp[i].empty()) {
                hashNum = hash(temp[i][0].language);
                container[hashNum] = temp[i];
            }
        }
    }
    
    hashNum = hash(newSong.language);

    bool placed = false;
    while (!placed) {
        if(container[hashNum].empty()) {
            container[hashNum].push_back(newSong);
            placed = true;
        }
        else if(container[hashNum][0].language == newSong.language) {
            container[hashNum].push_back(newSong);
            placed = true;
        } else{
            //linear collision policy
            hashNum++;
            hashNum = hashNum % capacity;
        }
    }
    size++;
}

std::vector<song>* HashMap::search(std::string language) {
    int hashNum = hash(language);

    while(true) {
        if(container[hashNum].empty()) {
            //collision policy says doesnt exist
            return nullptr;
        }
        if (container[hashNum][0].language == language) {
            return &container[hashNum];
        }
        else {
            //linear collision policy
            hashNum++;
            hashNum = hashNum % capacity;
        }
    }
}

std::tuple<std::vector<double>,std::string> HashMap::Algo(std::string language) {
    //start timer
    auto start = std::chrono::high_resolution_clock::now();

    //pull out the list of that language
    std::vector<song>* langList = search(language);

    //create data holders
    std::vector<double> result;
    result.resize((END_YEAR - START_YEAR)+1);

    std::vector<int> tally;
    tally.resize((END_YEAR - START_YEAR)+1);

    //add the data onto the lists
    for(int i = 0; i < langList->size(); i++) {
        int index = (*langList)[i].year - START_YEAR;
        result[index] += (*langList)[i].ExpLyrics;
        tally[index]++;
    }

    //average the data for each year and round to int
    for(int i = 0; i < result.size(); i++) {
        if ( tally[i] == 0) {
            result[i] = -1;
        }
        else {
            result[i] = result[i] / tally[i];
        }
    }

    //stop timer
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    return std::make_tuple(result, std::to_string(duration.count()));
}