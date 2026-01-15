#include"EnigmaMachine.h"
#include<cctype>
using std::string;

EnigmaMachine::EnigmaMachine(const string& w1_w, int w1_p, const string& w2_w, int w2_p, const string& w3_w, int w3_p, const string& r_w, const std::vector<std::pair<char, char>>& p_){
    w1.setWire(w1_w);
    w1.setFlag(25);
    w1.setPos(w1_p);

    w2.setWire(w2_w);
    w2.setFlag(25);
    w2.setPos(w2_p);

    w3.setWire(w3_w);
    w3.setFlag(25);
    w3.setPos(w3_p);

    r.setWire(r_w);
    p.add(p_);
}

char EnigmaMachine::encryptChar(char c){
    bool rotateNext = w1.state();
    if(rotateNext){
        rotateNext = w2.state();
        if(rotateNext) w3.state();
    }

    c = p.swap(c);
    c = w1.forward(c);
    c = w2.forward(c);
    c = w3.forward(c);

    c = r.forward(c);

    c = w3.backward(c);
    c = w2.backward(c);
    c = w1.backward(c);

    c = p.swap(c);

    return c;
}

string EnigmaMachine::encryptMessage(const string& msg){
    string result;
    for(char c : msg){
        if(isalpha(c)) result += encryptChar(c);
        else result += c;
    }
    return result;
}
