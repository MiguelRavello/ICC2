#ifndef PILA_H
#define PILA_H

#include<iostream>
#include<vector>

using namespace std;

template<class T>
class Pila{
private:
    vector<T> m_item;
    //friend Pila<T> operator+<>(const Pila &s1, const Pila &s2);
public:
    Pila(){}
    Pila(const Pila &m);
    ~Pila(){}
    void push(const T &item);
    void pop();
    bool empty() const;
    T top();

    friend Pila<T> operator+(const Pila &s1, const Pila &s2){
	    Pila<T> result=s1;
        for(int i=0 ; i<s2.m_item.size() ; i++)
            result.m_item.push_back(s2.m_item[i]);
        return result;
    }
    void print(){
        for(int i=0 ; i<m_item.size() ; i++)
            cout<<m_item[i]<<" ";
    }
};

template<class T>
Pila<T>::Pila(const Pila &m){
    for(int i=0; i<m.m_item.size();i++){
        this->m_item.push_back(m.m_item[i]);
    }
}

template<class T>
void Pila<T>::push(const T &item){ m_item.push_back(item);}

template<class T>
void Pila<T>::pop(){  m_item.pop_back();}

template<class T>
bool Pila<T>::empty() const{   return m_item.empty();}

template<class T>
T Pila<T>::top(){
    T last=m_item.back();
    return last;
}
 
/* 
template<class T>
Pila<T> operator+(const Pila &s1, const Pila &s2){
    Pila<T> result=s1;
    for(int i=0;i<s2.m_item.size();i++)
        result.m_item.push_back(s2.m_item[i]);
    return result;
}
*/
#endif
