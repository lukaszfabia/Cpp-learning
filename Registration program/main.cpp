#include "headers/System.h"

using namespace std;

int main() {
    auto *system = new System();
    system->home();

    delete system;

    return 0;
}