#include "LoopWorker.h"
#include <iostream>
#include <QCoreApplication>

#include <thread>
#include <chrono>

LoopWorker::LoopWorker() : quit(false) {
    std::cout << "LoopWorker constructed." << std::endl;
}

LoopWorker::~LoopWorker() {
    std::cout << "LoopWorker destructed." << std::endl;
}

void LoopWorker::loop() {
    while (!quit) {
        std::cout << "Looping..." << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // we need to make sure to yield to check if we're trying to
        // close
        std::cout << "Checking events..." << std::endl;
        QCoreApplication::processEvents();
    }
}

void LoopWorker::stop() {
    quit = true;
}

