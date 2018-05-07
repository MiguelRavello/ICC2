#ifndef COLA_H
#define COLA_H

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Nodo{
private:
    T m_key;
public:
    Nodo<T> *m_next;
    Nodo(const T val=0):m_key(val), m_next(NULL) {}
    Nodo(const Nodo<T> *o):m_key(o->m_key), m_next(o->m_next) {}
    void setKey(const T val) {   m_key=val};
    T getKey() {    return m_key;}
};

template<class T>
class Cola {
private:
    int m_size;
public:
    Nodo<T> *m_head;
    Nodo<T> *m_cola;
    Cola():m_head(NULL), m_cola(NULL) {}
    Cola(const Cola &m);
    void setCola(vector<T> xs);
    void push(const T);
    void pop_head();
    friend ostream& operator<<(ostream& out, Cola &o);
    int getLen(){   return m_size;}
    bool empty();
    T top();

    Cola<T> operator+(const Cola &o);
    Cola<T> operator-(const Cola &o);
};

template<class T>
Cola<T>::Cola(const Cola &m){
    Nodo<T> *xs;
    xs=m.m_head;
    while(xs!=NULL){
        this->push(xs->getKey());
        xs=xs->m_next;
    }
    delete xs;
}

template<class T>
ostream& operator<<(ostream& out, Cola &o){
    Nodo<T> *xs;
    xs=m_head;
    while(xs!=NULL){
        out<<xs->getKey()<<"->";
        xs=xs->m_next;
    }
    delete xs;
}

template<class T>
void Cola<T>::push(const T val){
    Nodo<T> *xs=new Nodo<T>(val);
    if(m_head==NULL){
        m_head=xs;
        m_cola=xs;
    }
    else{
        Nodo<T>* prev, *cur;
        prev=m_head;
        cur=m_head->m_next;
        while(cur!=NULL){
            prev=cur;
            cur=cur->m_next;
        }
        prev->m_next=xs;
        m_cola=xs;
        delete cur;
    }
}

template<class T>
void Cola<T>::setCola(vector<T> xs){
    for(vector<T>::iterator it=xs.begin();it!=xs.end();it++)
        this->push(*it);
}

template<class T>::pop_head(){
    Nodo<T>* prev, *cur;
    prev=m_head;
    cur=prev->m_head;
    if(prev==NULL){
        ;
    }
    else{
        m_head=cur;
        delete prev;
    }
}

template<class T>
bool Cola<T>::empty(){
    if(m_head==NULL)
        return true;
    return false;
}

template<class T>
T Cola<T>::top(){
    return m_head->getKey();
}
#endif
