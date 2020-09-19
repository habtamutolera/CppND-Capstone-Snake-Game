#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <vector>

class Record {
    public:
    Record(std::string fileName);
    void AddRecord(std::string name, int score);
    void ReadRecord();
    void PrintRecord();
    void WriteRecord(std::string name, int score);

    private:
    std::string _fileName;
    std::vector<std::pair<std::string, int >> _record;

};
#endif