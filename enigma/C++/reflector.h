#ifndef REFLECTOR_H
#define REFLECTOR_H

#include<string>
using std::string;

class Reflector{
    private:
        string wire;

    public:
        Reflector();
        Reflector(const string& w);

        void setWire(const string& w);
        string getWire();

        char forward(char c);
        char backward(char c);
};

#endif
