#include "message.h"
#include "ui_message.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>

#include "connect.h"

//新消息数量
int messages_n ;

//假设也就这几个消息
QString  words[10];

//获取消息信息
void get_messages()
{
    //test
    messages_n=2;
    words[1]="hello";
    words[0]="bye";

};


message::message(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
}

message::~message()
{
    delete ui;
}

//返回主界面
void message::on_pushButton_clicked()
{
    this->close();
}

//阅读下一消息
void message::on_pushButton_2_clicked()
{
   //在第一次触发时
    static int flag=1;
    if(flag==1)
    {
        get_messages();
        flag=0;
    }

    //ui->textBrowser_2->append("abcd");
    //ui->textBrowser_3->append("efg");


    if(messages_n < 0)
    {
        QMessageBox::about(NULL, "message!", " no more message!");
        this->close();
    }
    else
    {
        //清空现有框
        ui->textBrowser_2->clear();
        ui->textBrowser_3->clear();

        //载入下一条留言
        ui->textBrowser_2->append("他人留言");
        QString temp;
        temp.sprintf("message_n=%d",messages_n);
        ui->textBrowser_2->append(temp);
        ui->textBrowser_2->append(words[messages_n]);
        ui->textBrowser_3->append("你的回复");
    }

    messages_n--;
}

//消息回复
void message::on_pushButton_3_clicked()
{
    //获取文本框中语句
    QString temp =ui->textEdit->toPlainText();

    //发给数据库


    //显示回复提示
    QMessageBox::about(NULL, "message!", "已回复");

     void on_pushButton_2_clicked();





}
