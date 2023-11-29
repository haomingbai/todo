#pragma once
#include "ui_ToDo.h"
#include <QMainWindow>
//#include"list.h"

class ToDo : public QMainWindow {
    Q_OBJECT

public:
    ToDo(QWidget* parent = nullptr);
    ~ToDo();

private slots:
    void AddItem();
    void ChangeUrgency();
    void ChangeImportance();
    void DeleteItem();
//    void on_modify_importance_clicked();

private:
    Ui_ToDo* ui;

};
