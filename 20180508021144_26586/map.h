#ifndef MAP_H
#define MAP_H
#include"rpgobj.h"
#include<vector>

class Map:public RPGObj
{
public:
    Map();
    ~Map();
    void CreatObj(string type,int xx,int yy);
    void CreateMap();
protected:
    vector<RPGObj>_objs;
};

#endif // MAP_H
