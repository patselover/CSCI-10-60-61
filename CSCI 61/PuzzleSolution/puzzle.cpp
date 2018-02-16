#include "puzzle.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <unordered_map>

puzzle::puzzle(const char *name, const char *dictname)
{
    std::ifstream is(name);
    if (is.fail())
    {
        std::cout << "Can't open puzzle!" << std::endl;
        exit(2);
    }

    std::string line;
    std::size_t width;

    while (getline(is, line))
    {
        std::stringstream ss(line);
        std::vector<char> row;
        char c;
        while (ss >> c)
            row.push_back(tolower(c));
        if (data.size() == 0)
            width = row.size();
        else if (row.size() != width)
        {
            std::cout << "Corrupted puzzle!" << std::endl;
            exit(3);
        }
        data.push_back(row);
    }

    std::ifstream ds(dictname);
    if (ds.fail())
    {
        std::cout << "Can't open dictionary!" << std::endl;
        exit(2);
    }


    std::string word;
    while (ds >> word)
        dict[word] = 1;

}

void puzzle::solve()
{
    if (data.size() == 0)
        return;

    int width = data[0].size();
    int height = data.size();

    for (int r = 0; r < height; ++r)
        for (int c = 0; c < width; ++c)
             for (int dx = -1; dx <= 1; ++dx)
                for (int dy = -1; dy <= 1; ++dy)
                {
                    if (dx == 0 && dy == 0)
                        continue;

                    std::string s;
                    s += data[r][c];

                    for (int r1 = r + dy, c1 = c+dx;
                        r1 >= 0 && r1 < height && c1 >= 0 && c1 < width;
                        r1 += dy, c1 += dx)
                    {
                        s += data[r1][c1];
                        if (dict[s] == 1 && s.size() >= 6)
                            std::cout << s << ":" << "(" << r << ", " << c << ") (" << r1 << ", " << c1 << ")" << std::endl;
                    }
                }

   std::cout << width << ", " << height << std::endl;

}
