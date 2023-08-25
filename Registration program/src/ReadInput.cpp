//
// Created by ufabi on 25.08.2023.
//

#include "headers/ReadInput.h"
#include <iostream>

using namespace std;

ReadInput::ReadInput() = default;

ReadInput::~ReadInput() = default;

string ReadInput::readString(unsigned int amount) {
    string input;
    for (int i=0; i<amount; i++){
        cin>>input;
    }
    return input;
}

double ReadInput::readDouble(unsigned int amount) {
    return stod(readString(amount));
}

int ReadInput::readInt(unsigned int amount) {
    return stoi(readString(amount));
}

void ReadInput::print(const string& output) {
    cout<<output;
}
