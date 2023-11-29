#include "ToDo.h"
#include "ToDo.cpp"
#include<iostream>
#include<fstream>
#include<cstring>
//#include"list.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDate current;
    task test;
    test.body="我今天很开心！ I am happy today!";
    test.deadline.setDate(2022,11,25);
    test.importance=1;

    ToDo w;
    w.show();
    return a.exec();
}
