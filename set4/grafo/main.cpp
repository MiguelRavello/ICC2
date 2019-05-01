#include"grafo.h"
#include"grafo.cpp"

int main(){
    vector<int> A={1,1,1,5,5,4};
    vector<int> B={2,3,4,4,2,2};
    Grafo p(A,B);
    cout<<p.numOutgoing(1)<<endl;
    vector<int> show=p.adjacent(1);
    for(int i =0;i<show.size();i++)
        cout<<show[i];
    return 0;
}
