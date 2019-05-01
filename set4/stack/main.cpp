#include"pila.h"

int main(){
    Pila<int> a;
    Pila<int> b;
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Pila<int> c=a+b;
    c.print();
    return 0;
}    

