//
// Created by ufabi on 27.08.2023.
//

#include <utility>

#include "headers/Processes/Process.h"

Process::Process(std::vector<Account> &accounts) : accounts(accounts) {}

Process::~Process()
= default;