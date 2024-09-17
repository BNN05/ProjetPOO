#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class C_TerrainLoader
{
public:
    C_TerrainLoader();

    vector<vector<string>> LoadMap(const string& filename);
    void parseLineInitial(const string& line, vector<string>& row);
    void replaceOWithMapData(const string& filename);
    void PrintMapData();

private:
    vector<vector<string>> data;
};
