#include "C_TerrainLoader.h"

C_TerrainLoader::C_TerrainLoader()
{
}

vector<vector<string>> C_TerrainLoader::LoadMap(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Map file " << filename << " does not exist" << endl;
        return data; // Return empty map data
    }

    string line;
    while (getline(file, line))
    {
        vector<string> row;
        parseLineInitial(line, row);
        data.push_back(row);
    }

    file.close();
    replaceOWithMapData(filename);
    return data; // Return loaded map data
}

void C_TerrainLoader::parseLineInitial(const string& line, vector<string>& row)
{
    stringstream ss(line);
    string cell;
    while (getline(ss, cell, ','))
    {
        if (cell == "x")
            row.push_back("x");
        else if (cell.empty())
            row.push_back("o"); // Replace empty cells with "o"
        else
            row.push_back(cell); // Replace other characters
    }
}

void C_TerrainLoader::replaceOWithMapData(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Map file " << filename << " does not exist" << endl;
        return;
    }

    string line;
    size_t rowIndex = 0;
    while (getline(file, line) && rowIndex < data.size())
    {
        stringstream ss(line);
        string cell;
        size_t colIndex = 0;
        while (getline(ss, cell, ','))
        {
            if (colIndex < data[rowIndex].size() && !cell.empty() && data[rowIndex][colIndex] == "o")
                data[rowIndex][colIndex] = cell.empty() ? "o" : cell;
            colIndex++;
        }
        rowIndex++;
    }

    file.close();
}

void C_TerrainLoader::PrintMapData()
{
    for (const auto& row : data) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}
