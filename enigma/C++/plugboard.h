#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include<map>
#include<vector>
#include<set>
using std::map;
using std::vector;
using std::pair;
using std::set;

class PlugBoard{
    private:
        map<char, char> wire;

    public:
        PlugBoard();

        void add(const vector<pair<char, char>>& pairs);
        char swap(char c) const;
};

#endif
