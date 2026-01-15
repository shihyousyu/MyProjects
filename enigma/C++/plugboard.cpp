#include"PlugBoard.h"
#include<iostream>
#include<map>
#include<vector>
#include<set>
using std::map;
using std::vector;
using std::pair;
using std::set;
using std::cout;

PlugBoard::PlugBoard(){}

void PlugBoard::add(const vector<pair<char, char>>& pairs){
    set<char> used;
    for(auto& i : pairs){
        if(used.count(i.first) != 0 || used.count(i.second) != 0) cout << "conflict\n";
        else{
            wire[i.first] = i.second;
            wire[i.second] = i.first;
            used.insert(i.first);
            used.insert(i.second);
        }
    }
}

char PlugBoard::swap(char c) const{
    auto it = wire.find(c);
    if (it != wire.end()) return it->second;
    return c;
}
