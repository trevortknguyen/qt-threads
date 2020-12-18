#pragma once

#include <QObject>

class LoopWorker : public QObject {
    Q_OBJECT

public:
    LoopWorker();
    ~LoopWorker();

public slots:
    void loop();
};

