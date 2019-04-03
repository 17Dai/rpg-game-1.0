#include "world.h"
#include "icon.h"
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(2);
    this->_player.setPosY(2);

    this->Ghost.initObj("ghost");
    this->Ghost.setPosX(9);
    this->Ghost.setPosY(5);

    FILE*fp;
    fp=fopen("C:\\Users\\daishiqi\\Desktop\\map.txt","r");
    if(fp==NULL){
        cout<<"读入地图文件失败"<<endl;
        return;
    }
    RPGObj obj;
    char objName[30]={0};
    int xx;
    int yy;
    while(fscanf(fp,"%s%d%d",objName,&xx,&yy)!=EOF){
        obj.initObj(objName);
        obj.setPosX(xx);
        obj.setPosY(yy);
        this->_objs.push_back(obj);
    }

}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    this->_player.show(painter);
    this->Ghost.show(painter);
}

void World::handlePlayerMove(int direction, int steps){
    this->_player.move(direction, steps);
    vector<RPGObj>::iterator it;

    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        bool X=(_player.getPosX()>(*it).getPosX()-_player.getWidth()&&_player.getPosX()<(*it).getPosX()+(*it).getWidth());
        bool Y=((*it).getPosY()<_player.getPosY()+_player.getHeight()&&_player.getPosY()<(*it).getPosY()+(*it).getHeight());
        if(X&&Y){
             if((*it).canEat()){
                   _objs.erase(it);
                   break;
             }
             else if((*it).canCover()!=true){
                 this->_player.move(-direction,steps);
             }
        }

    }
}
void World::setGhostX(int x){
    Ghost.setPosX(x);
}
void World::setGhostY(int y){
    Ghost.setPosY(y);
}

