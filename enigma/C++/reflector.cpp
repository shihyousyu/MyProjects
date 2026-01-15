#include"Reflector.h"
using std::string;

Reflector::Reflector() : wire("ABCDEFGHIJKLMNOPQRSTUVWXYZ"){}
Reflector::Reflector(const string& w) : wire(w){}

void Reflector::setWire(const string& w){wire = w;}

std::string Reflector::getWire(){return wire;}

char Reflector::forward(char c){return wire[c - 'A'];}
char Reflector::backward(char c){return forward(c);}
