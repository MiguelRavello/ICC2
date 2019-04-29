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
    punto d(-2,-2);
    
    /***************static_cast******************/
    cout<<"***************static_cast******************"<<endl;
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
    cout<<"***************dynamic_cast******************"<<endl;
    /*El dynamic_cast se usa en el tiempo de ejecución para encontrar el lanzamiento correcto down-cast. */
    /* Se necesita por lo menos una clase virtual como base */
    /* Si el cast funciona retorna un valor new_type */
    /* si fall retorna un NULL */
    /* Este operador sólo puede usarse con objetos polimórficos */
    rectangulo *rec;
    rectangulo r2(a,d);
    rec=&r2;
    /*poligono *poli=dynamic_cast<poligono*>(rec);
    triangulo *tri=dynamic_cast<triangulo*>(poli);
    cout<<typeid(rec).name()<<endl;
    cout<<typeid(poli).name()<<endl;
    cout<<typeid(tri).name()<<endl;
    rec->soy();
    poli->soy();
    tri->soy();
    */
    try {
        triangulo *tn=dynamic_cast<triangulo*>(rec);
        tn->soy();
    }
    catch(std::bad_cast){
        cout<<"puntero nulo"<<endl;
    }
    return 0;
}
