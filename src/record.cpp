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

Record::Record(std::string fileName): _fileName(fileName)
{
    ReadRecord();
}

void Record::AddRecord(std::string name, int score) {
    _record.push_back(make_pair(name, score));
}

void Record::ReadRecord() {
    std::ifstream filestream(_fileName);
    std::string name, line;
    int score;
    if (filestream.is_open()) {
        while (std::getline(filestream, line))
        {
            //store in appropriate container and display
            std::istringstream linestream(line);
            linestream >> name >> score;
            _record.push_back(make_pair(name, score));
        }
    }
    else {
        std::cerr << _fileName << "could not be opened for reading!" << std::endl;
    }
}

void Record::PrintRecord() {
    
    sort(_record.begin(), _record.end(), Compare);
    std::cout << std::left << std::setw(10) << std::setfill(' ') << "Player" << std::setw(10) << std::setfill(' ')<< "Score" << std::endl;
    for(auto &record : _record) {
        std::ostringstream stream;
        //stream << std::setw(10) << record.first << ' ' << std::setw(10) << record.second;
        std::cout << std::left << std::setw(10) << std::setfill(' ') << record.first << std::setw(10) << std::setfill(' ') << record.second << std::endl;
        //std::cout << stream.str() << std::endl;
    }
}

void Record::WriteRecord(std::string name, int score) {
    std::ofstream filestream(_fileName);
    AddRecord(name, score);
    if (filestream.is_open()) {
        for (auto &record: _record)
            filestream << record.first << ' ' << record.second << std::endl;
    } 
    else
    {
        std::cerr << _fileName << " could not be opened for writing!" << std::endl;
    }
}

