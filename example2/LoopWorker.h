#pragma once

#include <QObject>

class LoopWorker : public QObject {
    Q_OBJECT

public:
    LoopWorker();
    ~LoopWorker();
private:
    // not atomic, because it should only be accessed within the same
    // thread by slots
    bool quit;

public slots:
    void loop();
    void stop();
};

