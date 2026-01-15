#ifndef rotor_H
#define rotor_H

#include<string>
using std::string;

class rotor{
    private:
        string wire;
        int flag;
        int pos;

    public:
        rotor();
        rotor(const string& w, int f, int p = 0);

        void setWire(const string& w);
        void setFlag(int f);
        void setPos(int p);

        std::string getWire();
        int getFlag();
        int getPos();

        char forward(char c);
        char backward(char c);

        bool state();
};

#endif
