#include"listae.h"

int main(){
    vector<int> a= {4,3,2,1,5,6,7};
    ListaE<int> A;
    A.setLista(a);
    vector<int> b= {7,6,4,3,2,1,0};
    ListaE<int> B;
    B.setLista(b);
    cout<<"lista B"<<endl;
    cout<<B<<endl;
    B.insertar(5,5);
    cout<<B<<endl;
    cout<<"lista A"<<endl;
    cout<<A<<endl;
    A.pop_nodo(2);
    cout<<A<<endl;
    A.pop_inicio();
    cout<<A<<endl;
    A.pop_inicio();
    cout<<A<<endl;

    return 0;
}
