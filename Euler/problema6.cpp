#include<iostream>
#include<cmath>
using namespace std;

typedef long int64;

int64 diferencia(int64 n){
    int64 rpta=(n*( pow(n,2)-1 )*(3*n+2))/12;
    return rpta;
}

int main(){
    int64 a=diferencia(100);
    int64 b=diferencia(10);
    cout<<" para n=10 es: "<<b<<endl;
    cout<<"para n=100 es: "<<a<<endl;
    return 0;
}
