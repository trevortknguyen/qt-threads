#include "LoopWorker.h"
#include <iostream>

LoopWorker::LoopWorker() {
    std::cout << "LoopWorker constructed." << std::endl;
}

LoopWorker::~LoopWorker() {
    std::cout << "LoopWorker destructed." << std::endl;
}

void LoopWorker::loop() {
    while (true) {
        std::cout << "Looping..." << std::endl;
    }
}

