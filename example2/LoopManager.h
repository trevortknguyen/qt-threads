#pragma once

#include <QObject>

class LoopManager : public QObject {
    Q_OBJECT

public:
    LoopManager();
    ~LoopManager();

signals:
    void stopWorkers();
};

