#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <vector>

class Record {
    public:
    Record(std::string const &fileName);
    void PrintRecord();
    void WriteRecord(std::string &name, int score);

    private:
    std::string fileName_;
    std::vector<std::pair<std::string, int >> record_;
    void AddRecord(std::string &name, int score);
    void ReadRecord();
    static bool CompareRecord(std::pair<std::string, int> const &a, std::pair<std::string, int> const &b);

};
#endif