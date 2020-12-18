#include "LoopManager.h"
#include <iostream>
#include <QCoreApplication>

LoopManager::LoopManager() {
    std::cout << "LoopManager constructed." << std::endl;
}

LoopManager::~LoopManager() {
    std::cout << "LoopManager destructed." << std::endl;
}
