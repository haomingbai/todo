#include "ToDo.h"
//#include"list.h"



ToDo::ToDo(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_ToDo)
{
    ui->setupUi(this);
    //connect(ui->important_unurgent,);
    connect(ui->OK,&QPushButton::clicked,this,&ToDo::AddItem);
    connect(ui->modify_urgency,&QPushButton::clicked,this,&ToDo::ChangeUrgency);
    connect(ui->modify_importance,&QPushButton::clicked,this,&ToDo::ChangeImportance);
    connect(ui->delete_2,&QPushButton::clicked,this,&ToDo::DeleteItem);
}

ToDo::~ToDo()
{
    delete ui; 
}

struct task{
    QString body;
    QDate deadline;
    int importance;
    bool operator == (const task &tsk);
};

//extern int abc;

//imp means important,uni unimportant,unu unurgent,urg urgent.
QList <task> task_set;

QList<task> uni_lst;
QList<task> imp_lst;

bool task::operator == (const task &tsk)
{
    return ((body == tsk.body) && (deadline == tsk.deadline) && (importance == tsk.importance));
}




void ToDo::AddItem(){
    task temp;
    if(ui->task_body->text()!="\0"){
        temp.body=ui->task_body->text();
        temp.deadline=ui->dateEdit->date();
        temp.importance=ui->important_or_not->isChecked();
        ui->task_body->clear();
        ui->important_or_not->setChecked(0);
        task_set.append(temp);
    }
}

/*bool task::operator == (const task &tsk)
{
    return ((body == tsk.body) && (deadline == tsk.deadline) && (importance == tsk.importance));
}
*/

void ToDo::ChangeImportance(){
    int uni_row=-1;
    int imp_row=-1;
    task swp_uni={0},swp_imp{0};
    task test_task={0};
    uni_row=ui->unimportant_task->currentRow();
    imp_row=ui->important_task->currentRow();
    if(uni_row>=0){
        //ui->unimportant_task->takeItem(uni_row);
        swp_uni=uni_lst.at(uni_row);
        uni_lst.removeAt(uni_row);
        //task_set.removeOne(swp_uni);
        for(int i=0;i<task_set.length();i++){
            if(task_set[i]==swp_uni){
                task_set.removeAt(i);
                break;
            }
        }
    }
    if(imp_row>=0){
        //ui->important_task->takeItem(imp_row);
        swp_imp=imp_lst.at(imp_row);
        imp_lst.removeAt(imp_row);
        //task_set.removeOne(swp_imp);
        for(int i=0;i<task_set.length();i++){
            if(task_set[i]==swp_imp){
                task_set.removeAt(i);
                break;
            }
        }
    }
    swp_uni.importance=!swp_uni.importance;
    swp_imp.importance=!swp_imp.importance;
    if(uni_row>=0){
        task_set.append(swp_uni);
        imp_lst.append(swp_uni);
    }
    if(imp_row>=0){
        task_set.append(swp_imp);
        uni_lst.append(swp_imp);
    }
}

void ToDo::ChangeUrgency(){
    int uni_row=-1;
    int imp_row=-1;
    task swp_uni={0},swp_imp{0};
    task test_task={0};
    uni_row=ui->unimportant_task->currentRow();
    imp_row=ui->important_task->currentRow();
    if(uni_row>=0){
        if(uni_lst.at(uni_row).deadline.daysTo(QDate::currentDate())<=3) {
            swp_uni=uni_lst.at(uni_row);
            uni_lst[uni_row].deadline=uni_lst[uni_row].deadline.addDays(3);
            //这里还应该加一段，就是改变表格上字体的颜色
            for(int i=0;i<task_set.length();i++){
                if(task_set[i]==swp_uni) {
                    task_set[i].deadline=task_set[i].deadline.addDays(3);
                    break;
                }
            }
        }
    }
    if(imp_row>=0){
        if(imp_lst.at(imp_row).deadline.daysTo(QDate::currentDate())<=3) {
            swp_imp=imp_lst.at(imp_row);
            imp_lst[imp_row].deadline=imp_lst[imp_row].deadline.addDays(3);
            //这里还应该加一段，就是改变表格上字体的颜色
            for(int i=0;i<task_set.length();i++){
                if(task_set[i]==swp_imp) {
                        task_set[i].deadline=task_set[i].deadline.addDays(3);
                        break;
                    }
            }
        }
    }
    //或者这里刷新一下这个表格
}

void ToDo::DeleteItem(){
    int uni_row=-1;
    int imp_row=-1;
    task swp_uni={0},swp_imp{0};
    task test_task={0};
    uni_row=ui->unimportant_task->currentRow();
    imp_row=ui->important_task->currentRow();
    if(uni_row>=0){
        if(uni_lst.at(uni_row).deadline.daysTo(QDate::currentDate())<=3) {
            swp_uni=uni_lst.at(uni_row);
            uni_lst.removeAt(uni_row);
            //这里还应该加一段，就是改变表格上字体的颜色
            for(int i=0;i<task_set.length();i++){
                    if(task_set[i]==swp_uni) {
                        task_set.removeAt(i);
                        break;
                    }
            }
        }
    }
    if(imp_row>=0){
        if(imp_lst.at(imp_row).deadline.daysTo(QDate::currentDate())<=3) {
            swp_imp=imp_lst.at(imp_row);
            imp_lst.removeAt(imp_row);
            //这里还应该加一段，就是改变表格上字体的颜色
            for(int i=0;i<task_set.length();i++){
                    if(task_set[i]==swp_imp) {
                        task_set.removeAt(i);
                        break;
                    }
            }
        }
    }
}

