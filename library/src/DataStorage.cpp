#include "DataStorage.h"
#include <fstream>

std::vector<float> DataStorage::readValues(std::string path) {
    std::ifstream file;
    file.open(path);
    std::vector<float> values;
    std::string s;
    float v;

    if(file.is_open()){
        while(s!= "_START_VALUES_"){
            getline(file,s);
        }
        while (true) {
            file >> s;
            if(s == "_END_VALUES_") break;
            v = std::stof(s);
            values.push_back(v);
        }
    }
    file.close();
    return values;
}

std::vector<std::string> DataStorage::readNames(std::string path) {
    std::ifstream file;
    file.open(path);
    std::vector<std::string> names;
    std::string s;

    if(file.is_open()){
        while(s!= "_START_NAMES_"){
            getline(file,s);
        }
        while (true) {
            getline(file,s);
            if(s == "_END_NAMES_") break;
            names.push_back(s);
        }
    }
    file.close();
    return names;
}

void DataStorage::SaveToFile(std::string path, std::vector<float> values, std::vector<std::string> names) {

    std::ofstream file;
    file.open(path);
    file << "_START_NAMES_\n";
    for(std::string name : names)
    {
        file << name << "\n";
    }
    file << "_END_NAMES_\n";
    file << "_START_VALUES_\n";
    for(float value : values)
    {
        file << value << "\n";
    }
    file << "_END_VALUES_\n";
    file.close();
}
