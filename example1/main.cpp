#include <iostream>

#include <QApplication>

#include <QThread>
#include <QObject>

#include "LoopWorker.h"

int main(int argc, char** argv) {
    std::cout << "Hello." << std::endl;

    QApplication app (argc, argv);

    // try to do RAII
    QThread thread;
    LoopWorker* loopWorker = new LoopWorker();

    // affinity gone
    loopWorker->moveToThread(&thread);
    QObject::connect(&thread, &QThread::finished, loopWorker, &QObject::deleteLater);
    QObject::connect(&thread, &QThread::started, loopWorker, &LoopWorker::loop);
    thread.start();

    // wait on something
    // kill it
    
    std::cout << "Starting to wait on thread." << std::endl;

    thread.exit();
    thread.wait();

    std::cout << "Finished waiting on thread." << std::endl;

    return app.exec();
}
