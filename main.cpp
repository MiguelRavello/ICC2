#include"matrix.h"

int main(){
    Matrix<double> A(3,3);
    A.inicializar();
    cout<<A<<endl;
    double arr[]={4,-3,4}; //coeficientes del vector B
    vector<double> rpta;
    rpta=A.elim_gauss(arr);
    cout<<"matrix::aumentada escalonada"<<endl;
    cout<<A<<endl;
    cout<<"vector solucion"<<endl;
    for(vector<double>::iterator it=rpta.begin();it!=rpta.end();it++)
        cout<<*it<<" "<<endl;
    return 0;
}
