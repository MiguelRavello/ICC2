#include<iostream>
using namespace std;

template<class T>
void insertion(T *xs,int n){
    T key;
    int i;
    for(int j=1;j<n;j++){
        key=*(xs+j);
        i=j-1;
        while(i>-1 && *(xs+i)>key){
            *(xs+i+1)=*(xs+i);
            i--;
        }
        *(xs+i+1)=key;
    }
}
int main(){
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertion<int>(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}
