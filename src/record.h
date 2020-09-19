#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <vector>

class Record {
    public:
    Record(std::string const &fileName);
    void AddRecord(std::string &name, int score);
    void ReadRecord();
    void PrintRecord();
    void WriteRecord(std::string &name, int score);

    private:
    std::string fileName_;
    std::vector<std::pair<std::string, int >> record_;

};
#endif