#include<iostream>
using namespace std;



int main(){
    cout<<"*********** problema 2.1  ***************"<<endl;
    cout<<"en la linea 20 falto poner un semicolon ;"<<endl;
    cout<<"y el punto  mypoint es constante, por lo q no se puede modificar"<<endl;

    cout<<"*********** problema 2.2  ***************"<<endl;
    cout<<"en la linea 11 la funcion, el seteo es declarado constante, pero pretende hacer una asignacion"<<endl;
    /*The idea of const functions is not allow them to modify the object on which they are called. 
    It is recommended practice to make as many functions const as possible so that accidental 
    changes to objects are avoided.
    int getValue() const {return value;}*/
    cout<<"*********** problema 2.3  ***************"<<endl;
    cout<<"En la linea 16 el objeto p, esta llamando a sus miembros dato siendo privados"<<endl;

    cout<<"*********** problema 2.4  ***************"<<endl;
    cout<<"En la linea 13 SetX debe estar como void Point::SetX..."<<endl;

    cout<<"*********** problema 2.5  ***************"<<endl;
    cout<<"En la linea 20 es delete[] nums "<<endl;

    cout<<"*********** problema 2.6  ***************"<<endl;
    cout<<"Solo falta liberar el espacio de memoria de p"<<endl;
    return 0;
}
