#include"cola.h"

int main(){
    vector<int> a= {1,2,3,4};
    Cola<int> A;
    A.setCola(a);
    vector<int> b= {3,4,5,6,7};
    Cola<int> B;
    B.setCola(b);
    cout<<A<<endl;
    cout<<B<<endl;
    Cola<int> C;
    C=A+B;
    cout<<C<<endl;
    cout<<"........................"<<endl;
    vector<int> p= {1,2,3,4,5};
    Cola<int> X;
    X.setCola(p);
    vector<int> q= {4,5,6,7};
    Cola<int> Y;
    Y.setCola(q);
    Cola<int> Z;
    cout<<X<<endl;
    cout<<Y<<endl;
    Z=X-Y;
    cout<<Z<<endl;
    return 0;
}
