#include <iostream>

#include <QApplication>

#include <QThread>
#include <QObject>

#include "LoopWorker.h"
#include "LoopManager.h"

#include <cstdio>

int main(int argc, char** argv) {
    std::cout << "Hello." << std::endl;

    QApplication app (argc, argv);

    // try to do RAII, should be fields
    LoopManager manager;
    QThread thread;

    LoopWorker* loopWorker = new LoopWorker();

    // affinity set
    loopWorker->moveToThread(&thread);
    // lifecycle managed
    QObject::connect(&thread, &QThread::finished, loopWorker, &QObject::deleteLater);
    QObject::connect(&thread, &QThread::started, loopWorker, &LoopWorker::loop);
    QObject::connect(&manager, &LoopManager::stopWorkers, loopWorker, &LoopWorker::stop);
    thread.start();

    // wait on something
    // kill it
    //
    //Worker
    //
    std::cout << "Started thread. Type enter to stop." << std::endl;
    getchar();
    

    
    std::cout << "Starting to wait on thread." << std::endl;

    manager.stopWorkers();

    // this exit is necessary to make sure that you close the event queue
    // but it is not sufficient because you the loop is still in the middle of
    // processing
    //
    // an alternative design for the loop is a recursive function that will
    // queue and requeue itself onto the event queue
    // because then it the `exit` event wouldn't interrupt an ongoing process
    thread.exit();
    thread.wait();

    std::cout << "Finished waiting on thread." << std::endl;

    return app.exec();
}
