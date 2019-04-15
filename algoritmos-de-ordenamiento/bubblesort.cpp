#include<iostream>
using namespace std;

template<class T>
void bubble(T *xs,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            T temp=*(xs+j);
            *(xs+j)=*(xs+j+1);
            *(xs+j+1)=temp;
        }
   }
}

int main(){
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble<int>(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}
