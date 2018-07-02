#ifndef CAJERO_H
#define CAJERO_H

#include<iostream>
//#include<cmath>
using namespace std;

class Cajero{
protected:
    Cajero *m_next;
public:
    Cajero():m_next(NULL){}
    virtual void devuelveBilletes(int valor)=0;
    void setNext(Cajero *siguiente){    m_next=siguiente;}
};

class Billete50 : public Cajero{
public:
    void devuelveBilletes(int valor){
        if(valor%5==0 || valor%10==0){
            int resto = valor%50;
            int nbilletes = valor/50;
            if(nbilletes>0)
                cout<<nbilletes<<" x50 soles"<<endl;
            if(resto>0){
                if(m_next!=NULL)
                    m_next->devuelveBilletes(resto);
                else
                    cout<<"soy el ultimo handler"<<endl;
            }
        }
        else
            throw "valor no valido";
    }
};

class Billete20 : public Cajero{
public:
    void devuelveBilletes(int valor){
        int resto = valor%20;
        int nbilletes = valor/20;
        if(nbilletes>0)
            cout<<nbilletes<<" x20 soles"<<endl;
        if(resto>0){
            if(m_next!=NULL)
                m_next->devuelveBilletes(resto);
            else
                cout<<"soy el ultimo handler"<<endl;
        }
    }
};

class Billete10 : public Cajero{
public:
    void devuelveBilletes(int valor){
        int resto = valor%10;
        int nbilletes = valor/10;
        if(nbilletes>0)
            cout<<nbilletes<<" x10 soles"<<endl;
        if(resto>0){
            if(m_next!=NULL)
                m_next->devuelveBilletes(resto);
            else
                cout<<"soy el ultimo handler"<<endl;
        }
    }
};

class Billete5 : public Cajero{
public:
    void devuelveBilletes(int valor){
        int resto = valor%5;
        int nbilletes = valor/5;
        if(nbilletes>0)
            cout<<nbilletes<<" x5 soles"<<endl;
        if(resto>0){
            if(m_next!=NULL)
                m_next->devuelveBilletes(resto);
            else
                cout<<"soy el ultimo"<<endl;
        }
    }
};

#endif
