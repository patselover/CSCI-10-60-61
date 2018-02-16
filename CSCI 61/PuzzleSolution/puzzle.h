#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include <unordered_map>
#include <string>

class puzzle
{
public:
    puzzle(const char *name, const char *dictname);
    void solve();

private:
    std::vector<std::vector<char> > data;
    std::unordered_map<std::string, int> dict;
};

#endif // PUZZLE_H
