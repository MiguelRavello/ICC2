#include"cola.h"

int main(){
    Cola<int> A;
    vector<int> a={1,2,3,4};
    A.setCola(a);

    Cola<int> B;
    vector<int> b={4,5,6,7};
    cout << A <<endl;
    cout<< B<<endl;
    Cola<int> C;
    return 0;
}
