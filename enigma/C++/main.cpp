#include<iostream>
#include<string>
#include<vector>
#include"EnigmaMachine.h"
using namespace std;

int main(){
    vector<pair<char, char>> plugs;
    string w[5] = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "AJDKSIRUXBLHWTMCQGZNPYFVOE", "BDFHJLCPRTXVZNYEIWGAKMUSQO", "ESOVPZJAYQUIRHXLNFTGKDCMWB", "VZBRGITYUPSDNHLXAWMJQOFECK"};
    string r = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    int w1, w2, w3;
    int f1, f2, f3;

    cout << "ENIGMA MACHINE\n\n";
    cout << "Enter the weiring of three rotors(0, 1, 2, 3, 4):\n";
    cout << "\trotor 1: ";
    cin >> w1;
    cout << "\trotor 2: ";
    cin >> w2;
    cout << "\trotor 3: ";
    cin >> w3;

    cout << "\nEnter the positions of three rotors(0 ~ 25):\n";
    cout << "\trotor 1: ";
    cin >> f1;
    cout << "\trotor 2: ";
    cin >> f2;
    cout << "\trotor 3: ";
    cin >> f3;

    int cnt;
    cout << "\nHow many plug pairs? ";
    cin >> cnt;

    cout << "Enter plug pairs:\n";
    for(int i = 0; i < cnt; i++){
        string pair;
        cin >> pair;
        plugs.push_back({pair[0], pair[1]});
    }

    cin.ignore();
    EnigmaMachine eng(w[w1], f1, w[w2], f2, w[w3], f3, r, plugs);

    cout << "\nEnter the plaintext:\n";
    string msg;
    getline(cin, msg);
    cout << "\nCiphertext:\n" << eng.encryptMessage(msg) << "\n\n";

    system("pause");
    return 0;
}