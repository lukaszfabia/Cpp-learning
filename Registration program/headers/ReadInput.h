//
// Created by ufabi on 25.08.2023.
//

#ifndef CPP_LEARNING_READINPUT_H
#define CPP_LEARNING_READINPUT_H

#include <string>

using namespace std;


class ReadInput {
public:
    ReadInput();

    ~ReadInput();

    static string readString(unsigned int amount);

    [[maybe_unused]] static double readDouble(unsigned int amount);
    static int readInt(unsigned int amount);
    static void print(const string& output);
};


#endif //CPP_LEARNING_READINPUT_H
