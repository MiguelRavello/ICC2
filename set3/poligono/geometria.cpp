#include"geometria.h"

/* ************clase arreglo de puntos *************/

puntoArr::puntoArr():m_size(0){
    m_puntos=new punto[0];
}

puntoArr::puntoArr(const punto xs[],const int len):m_size(len){
    m_puntos=new punto[m_size];
    for(int i=0;i<m_size;i++)
        *(m_puntos+i)=xs[i];
}

//cualquier codigo en la clase puntoArr tiene acceso a variables privadas
puntoArr::puntoArr(const puntoArr &other):m_size(other.m_size){
    m_puntos=new punto[m_size];
    for(int i=0;i<m_size;i++)
        *(m_puntos+i)=other.m_puntos[i];
}

puntoArr::~puntoArr(){
    delete[] m_puntos;
}

void puntoArr::resize(int nuevo){
    punto *xs=new punto[nuevo];
    int minimo=(nuevo>m_size ? m_size : nuevo);
    for(int i=0;i<minimo;i++)
        xs[i]=m_puntos[i];
    delete[] m_puntos;
    m_size=nuevo;
    m_puntos=xs;
}

void puntoArr::clear(){
    resize(0);
}

void puntoArr::push_back(const punto &p){
    resize(m_size+1);
    m_puntos[m_size-1]=p;
}

void puntoArr::insert(const int pos,const punto &p){
    resize(m_size+1);
    for(int i=m_size-1;i>pos;i--)
        m_puntos[i]=m_puntos[i-1];
    m_puntos[pos]=p;
}

void puntoArr::remove(const int pos){
    if(pos>=0 && pos<m_size){
        for(int i=pos;i<m_size-2;i++)
            m_puntos[i]=m_puntos[i+1];
        resize(m_size-1);
    }
}

punto *puntoArr::get(const int pos){
    return (pos>=0 && pos<m_size) ? m_puntos+pos : NULL;
}

const punto *puntoArr::get(const int pos) const{
    return (pos>=0 && pos<m_size) ? m_puntos+pos : NULL;
}

/* puntero constante solo r
   y puntero no constante para wr */

/****************** clase poligono  ************************/
//int poligono::n=0;
poligono::poligono(const puntoArr &xs): m_lista(xs){
    m_np++;
}

poligono::poligono(const punto puntos[],const int len):m_lista(puntos,len){
    m_np++;
}

