#pragma once
#include "ui_ToDo.h"
#include <QMainWindow>

class ToDo : public QMainWindow {
    Q_OBJECT
    
public:
    ToDo(QWidget* parent = nullptr);
    ~ToDo();

private:
    Ui_ToDo* ui;
};