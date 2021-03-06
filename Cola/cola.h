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
    void setKey(const T val) {
        m_key=val;}
    T getKey() {
        return this->m_key;
    }
};

template<class T>
class Cola {
private:
    int m_size;
public:
    Nodo<T> *m_head;
    Nodo<T> *m_cola;
    Cola():m_head(NULL), m_cola(NULL), m_size(0) {}
    Cola(const Cola &m);
    void setCola(vector<T> xs);
    void push(const T);
    void pop_head();
    friend ostream& operator<<(ostream& out, Cola &o){
	    Nodo<T> *xs;
        xs=o.m_head;
        while(xs!=NULL){
            out<<xs->getKey()<<"->";
            xs=xs->m_next;
        }
        delete xs;
        return out;
    }
    int getLen(){   return m_size;}
    bool empty();
    T top();
    void xOR(const T); //para la resta
    void sOR(const T); // para la suma

    void operator=(const Cola &o);
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
void Cola<T>::operator=(const Cola &o){
    Nodo<T> *xs;
    xs=o.m_head;
    while(xs!=NULL){
        this->push(xs->getKey());
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
        m_size++;
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
        m_size++;
        delete cur;
    }
}

template<class T>
void Cola<T>::setCola(vector<T> xs){
    for(int i=0;i<xs.size();i++)
        this->push(xs[i]);
}

template<class T>
void Cola<T>::pop_head(){
    Nodo<T>* prev, *cur;
    prev=m_head;
    cur=m_head->m_next;
    if(prev==NULL){
        ;
    }
    else{
        m_head=cur;
        delete prev;
        if(m_head==NULL)
            m_cola=NULL;
        else
            m_size--;
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

template<class T>
void Cola<T>::xOR(const T e){
    Nodo<T> *prev, *cur, *victima;
    prev=this->m_head;
    cur=this->m_head->m_next;
    if(prev->getKey()==e){
        m_head=cur;
        delete prev;
    }
    else{
        while(cur!=NULL){
            if(cur->getKey()==e){
                prev->m_next=cur->m_next;
                victima=cur;
                delete victima;
                break;
            }
            prev=cur;
            cur=cur->m_next;
        }
    }
}

template<class T>
void Cola<T>::sOR(const T e){
    Nodo<T> *xs;
    xs=this->m_head;
    bool v=false;
    while(xs!=NULL){
        if(e==xs->getKey()){
            v=true;
            break;
        }
        else
            xs=xs->m_next;
    }
    if(v)
        ;
    else
        this->push(e);
}
 
template<class T>
Cola<T> Cola<T>::operator-(const Cola &o){
    Cola<T> rpta;
    Nodo<T> *xs;
	xs=this->m_head;
	while(xs!=NULL){
		rpta.push(xs->getKey());
		xs=xs->m_next;
	}
    xs=o.m_head;
    while(xs!=NULL){
        rpta.xOR(xs->getKey());
        xs=xs->m_next;
    }
    return rpta;

}

template<class T>
Cola<T> Cola<T>::operator+(const Cola &o){
    Cola<T> rpta; // No me reconoce el constructor copia Cola<T> r=*this;
    Nodo<T> *xs;
    xs=this->m_head;
    while(xs!=NULL){
        rpta.push(xs->getKey());
        xs=xs->m_next;
    }
    xs=o.m_head;
    while(xs!=NULL){
        rpta.sOR(xs->getKey());
        xs=xs->m_next;
    }
    return rpta;
}

#endif
