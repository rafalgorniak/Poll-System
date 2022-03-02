#ifndef PROJEKT_DATASTORAGE_H
#define PROJEKT_DATASTORAGE_H
#include <iostream>
#include <vector>
#include <sstream>

class DataStorage
{
public:
    void SaveToFile(std::string path, std::vector<float> values, std::vector<std::string> names);
    std::vector<float> readValues(std::string path);
    std::vector<std::string> readNames(std::string path);
};


#endif //PROJEKT_DATASTORAGE_H
