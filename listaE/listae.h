#ifndef LISTAE_H
#define LISTAE_H

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
    void setKey(const T val) {
        m_key=val;}
    T getKey() {
        return this->m_key;
    }
};

template<class T>
class ListaE{
private:
    Nodo<T> *m_inicio; //head
    Nodo<T> *m_fin;  // cola
    int m_size;
public:
    ListaE():m_inicio(NULL),m_fin(NULL), m_size(0){}
    void setLista(const vector<T> xs);
    void insertarInicio(const T);
    void insertar(const T,const int);
    void pop_inicio();
    void pop_nodo(const int);

    Nodo<T>* getHead() const{ return m_inicio;}
    Nodo<T>* getCola() const{ return m_fin;}
    Nodo<T>* getNodo(const int) const;
    int getLen() const{   return m_size;}

    friend ostream& operator<<(ostream& out,const ListaE<T> &o){
	    Nodo<T> *xs;
        xs=o.m_inicio;
        while(xs!=NULL){
            out<<xs->getKey()<<"->";
            xs=xs->m_next;
        }
        delete xs;
        return out;
    }
};

template<class T>
void ListaE<T>::setLista(const vector<T> xs){
    for(int i=0;i<xs.size();i++)
        this->insertarInicio(xs[i]);
}

template<class T>
void ListaE<T>::insertarInicio(const T val){
    Nodo<T> *xs=new Nodo<T>(val);
    if(m_inicio==NULL){
        m_inicio=xs;
        m_fin=xs;
        m_size++;
    }
    else{
       xs->m_next=m_inicio;
       m_inicio=xs;
       m_size++;
    }
}

template<class T>
void ListaE<T>::insertar(const T val,const int pos){
    Nodo<T> *xs = new Nodo<T>(val);
    Nodo<T> *prev, *cur;
    prev=m_inicio;
    cur=m_inicio->m_next;
    int i=1;
    if(pos==0)
        this->insertarInicio(val);
    else{
        while(cur!=NULL){
            if(i==pos){
                prev->m_next=xs;
                xs->m_next=cur;
                m_size++;
               break;
            }
            prev=cur;
            cur=cur->m_next;
            i++;
        }
    }
}

template<class T>
Nodo<T>* ListaE<T>::getNodo(const int pos) const{
    if(pos>=0 && pos<m_size){
        Nodo<T> *xs;
        xs=m_inicio;
        int i=0;
        while(xs!=NULL){
            if(i==pos){
                break;
            }
            xs=xs->m_next;
        }
        return xs;
    }
}

template<class T>
void ListaE<T>::pop_inicio(){
    Nodo<T> *prev,*cur;
    prev=m_inicio;
    cur=m_inicio->m_next;
    if(prev==NULL)
        ;
    else{
        m_inicio=cur;
        delete prev;
        if(m_inicio==NULL)
            m_fin=NULL;
        else
            m_size--;
    }
}

template<class T>
void ListaE<T>::pop_nodo(const int pos){
    Nodo<T> *prev, *cur;
    prev=m_inicio;
    cur=m_inicio->m_next;
    int i=1;
    if(pos==0)
        this->pop_inicio();
    else{
        while(cur!=NULL){
            if(i==pos){
                prev->m_next=cur->m_next;
                delete cur;
                m_size--;
                if(i == m_size-1)
                    m_fin==prev;
            }
            prev=cur;
            cur=cur->m_next;
            i++;
        }
    }
}

#endif
