#ifndef CPP_LEARNING_CONSOLECONTROL_H
#define CPP_LEARNING_CONSOLECONTROL_H


class ConsoleControl {
public:
    ConsoleControl() = default;
    ~ConsoleControl() = default;

    static void clearConsole();

    static void pause();

    static void sleep(int seconds);
};


#endif //CPP_LEARNING_CONSOLECONTROL_H
