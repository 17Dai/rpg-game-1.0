#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"
#include<QTimer>
#include <map>
#include <iostream>
#include<QPainter>
#include"rpgobj.h"
using namespace std;

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveGhost()));
    timer->start(500);
    _game.initWorld("C:\\Users\\daishiqi\\Desktop\\map.txt");//TODO 应该是输入有效的地图文件
}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    this->_game.show(pa);
    pa->end();
    delete pa;
}

void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,-1,2,-2 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(2,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(-2,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(-1,1);
    }
    this->repaint();
}
void MW1::moveGhost(){
    static int i=1;
    static int g=1;
    if(i<10&&g%2!=0){
       _game.setGhostX(i);
       _game.setGhostY(i+1);
       i++;
    }
    if(i==10||i==1){
        g++;
    }
    if(i<=10&&g%2==0){
        _game.setGhostX(i-1);
        _game.setGhostY(i+1);
        i--;
    }

    this->repaint();
}
