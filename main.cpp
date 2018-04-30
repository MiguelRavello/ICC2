#include"matrix.h"

int main(){
    Matrix<double> A(3,3);
    vector<vector<double> > matriz = {{10, -7, 1},
                                     {7, 1, -11},
                                     {2, 3, -1}};
    A.setMatrix(matriz);
    cout<<"matriz A: "<<endl;
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
