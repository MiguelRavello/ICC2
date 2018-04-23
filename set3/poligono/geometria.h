#ifndef GEOMETRIA_H
#define GEOMETRIA_H

#include<iostream>

using namespace std;

class punto{
private:
    int m_x;
    int m_y;
public:
    punto(int a=0,int b=0):m_x(a),m_y(b){}
    int getX() const {return m_x;}
    int getY() const {return m_y;}
    void setX(const int nx){    m_x=nx;}
    void setY(const int ny){    m_y=ny;}
};

class puntoArr{
private:
    int m_size;
    punto *m_puntos;
    void resize(int size);
public:
    puntoArr();
    puntoArr(const punto xs[],const int len);
    puntoArr(const puntoArr &other);
    ~puntoArr();

    void clear();
    int getSize() const{return m_size;}
    void push_back(const punto &p);
    void insert(const int pos,const punto &p);
    void remove(const int pos);
    punto *get(const int pos);
    const punto *get(const int pos) const;
};

class poligono{
protected:
    static int m_np;
    puntoArr m_lista;
public:
    poligono(const puntoArr &xs);
    poligono(const punto puntos[],const int len);
    virtual double area() const=0;
    static int getNP(){return m_np;}
    int getNumLados() const {return m_lista.getSize();}
    const puntoArr *getpuntos() const {return &m_lista;}
    ~poligono() {--m_np;}
};

#endif
