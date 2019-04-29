#include<iostream>
#include"../set3/poligono/geometria.h"
#include"../set3/poligono/geometria.cpp"
#include<typeinfo>
using namespace std;

#define min(x,y) (x<y ? x:y)

template<class T>
T minimo(const T a,const T b){
    return a<b ? a:b;
}



int main(){
    punto a(2,2);
    punto b(-1,-1);
    punto c(-1,2);
    
    /***************static_cast******************/
    rectangulo r(a,b);
    poligono *p1=static_cast<poligono *>(&r);    //casteamos de r a p1
    triangulo *tp=static_cast<triangulo *>(p1);  // casteamos de p1 a tp
    
    cout<<typeid(r).name()<<endl;
    cout<<typeid(p1).name()<<endl;
    cout<<typeid(tp).name()<<endl;

    r.soy();
    p1->soy();
    tp->soy();

    /***************dynamic_cast****************/

    return 0;
}
