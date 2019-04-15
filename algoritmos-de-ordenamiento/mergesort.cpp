#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int i,j;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1+1], R[n2+1];
    for(i=0;i<n1;i++){
        L[i]=arr[i+l];
        //cout<<L[i]<<endl;
    }
    for(j=0;j<n2;j++){
        R[j]=arr[m+j+1];
        //cout<<R[j]<<endl;
    }
    i=0; j=0;
    L[n1]=10000;
    R[n2]=10000;
    for(int k=l;k<=r;k++){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}
