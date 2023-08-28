#include "headers/System.h"
#include "headers/Tools/ReadInput.h"
#include "headers/Menu/MenuManager.h"

System::System() {
    this->accounts = vector<Account>();
}

System::~System() = default;

void System::home() {
    auto *menuManager=new MenuManager(accounts);
    menuManager->build();
}