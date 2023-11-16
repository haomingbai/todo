#include "ToDo.h"

ToDo::ToDo(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_ToDo)
{
    ui->setupUi(this);
}

ToDo::~ToDo()
{
    delete ui; 
}