#include"listae.h"

int main(){
    vector<int> a= {4,3,2,1,5,6,7};
    ListaE<int> A;
    A.setLista(a);
    vector<int> b= {7,6,4,3,2,1,0};
    ListaE<int> B;
    B.setLista(b);
    cout<<"lista B"<<endl;
    //cout<<B<<endl;
    B.imprimir();
    cout<<endl;
    cout<<"insertando 5 en la posicion 5"<<endl;
    B.insertar(5,5);
    //cout<<B<<endl;
    B.imprimir();
    cout<<endl;
    cout<<"lista A"<<endl;
    //cout<<A<<endl;
    A.imprimir();
    cout<<endl;
    cout<<"borrando el nodo-posicion 2"<<endl;
    A.pop_nodo(2);
    //cout<<A<<endl;
    A.imprimir();
    cout<<endl;
    cout<<"borrando las cabezas"<<endl;
    A.pop_inicio();
    //cout<<A<<endl;
    A.imprimir();
    A.pop_inicio();
    //cout<<A<<endl;
    A.imprimir();
    cout<<endl;
    cout<<"tamaño de A"<<endl;
    cout<<A.getLen()<<endl;
    cout<<"Nodo pos 2"<<endl;
    Nodo<int> *xs;
    xs=A.getNodo(2);
    cout<<xs->getKey()<<endl;
    return 0;
}
