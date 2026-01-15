#include "rotor.h"
using std::string;

rotor::rotor() : wire("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), flag(0), pos(0){}
rotor::rotor(const std::string& w, int f, int p) : wire(w), flag(f), pos(p % 26){}

void rotor::setWire(const string& w){wire = w;}
void rotor::setFlag(int f){flag = f;}
void rotor::setPos(int p){pos = p % 26;}

string rotor::getWire(){return wire;}
int rotor::getFlag(){return flag;}
int rotor::getPos(){return pos;}

char rotor::forward(char c){
    char t = c - 'A' + pos;
    char wired = wire[t] - 'A';
    char out = (wired - pos + 26) % 26;
    return out + 'A';
}
char rotor::backward(char c){
    char idx = wire.find(((c - 'A' + 26 - pos) % 26) + 'A');
    char out = (idx + pos) % 26;
    return out + 'A';
}

bool rotor::state(){
    pos = (pos + 1) % 26;
    return pos == flag;
}
