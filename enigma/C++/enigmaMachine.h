#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H

#include<string>
#include<vector>
#include"rotor.h"
#include"Reflector.h"
#include"PlugBoard.h"
using std::string;
using std::vector;

class EnigmaMachine{
    private:
        rotor w1, w2, w3;
        Reflector r;
        PlugBoard p;

    public:
        EnigmaMachine(const string& w1_w, int w1_f, const string& w2_w, int w2_f, const string& w3_w, int w3_f, const string& r_w, const vector<pair<char, char>>& p_);

        char encryptChar(char c);
        string encryptMessage(const string& msg);
};

#endif
