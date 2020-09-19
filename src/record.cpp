#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "record.h"

bool Compare(std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
    return a.second > b.second;
}

Record::Record(std::string const &fileName): fileName_(fileName)
{
    ReadRecord();
}

void Record::AddRecord(std::string &name, int score) {
    record_.push_back(make_pair(name, score));
}

void Record::ReadRecord() {
    std::ifstream filestream(fileName_);
    std::string name, line;
    int score;
    if (filestream.is_open()) {
        while (std::getline(filestream, line))
        {
            //store in appropriate container and display
            std::istringstream linestream(line);
            linestream >> name >> score;
            record_.push_back(make_pair(name, score));
        }
    }
    else {
        std::cerr << fileName_ << "could not be opened for reading!" << std::endl;
    }
}

void Record::PrintRecord() {
    
    sort(record_.begin(), record_.end(), Compare);
    std::cout << std::left << std::setw(10) << std::setfill(' ') << "Player" << std::setw(10) << std::setfill(' ')<< "Score" << std::endl;
    for(auto const &record : record_) {
        std::ostringstream stream;
        //stream << std::setw(10) << record.first << ' ' << std::setw(10) << record.second;
        std::cout << std::left << std::setw(10) << std::setfill(' ') << record.first << std::setw(10) << std::setfill(' ') << record.second << std::endl;
        //std::cout << stream.str() << std::endl;
    }
}

void Record::WriteRecord(std::string &name, int score) {
    std::ofstream filestream(fileName_);
    AddRecord(name, score);
    if (filestream.is_open()) {
        for (auto const &record: record_)
            filestream << record.first << ' ' << record.second << std::endl;
    } 
    else
    {
        std::cerr << fileName_ << " could not be opened for writing!" << std::endl;
    }
}
 
