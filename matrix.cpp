#include "matrix.h"
#include<cmath>

/****************** Trabajo practico 1**********************/
/****************** problema 1 *****************************/

void cuboRef(int &x){
    x=pow(x,3);
}

int cuboVal(int x){
    return x=pow(x,3);
}

/* ***************** problema 2 *****************************/

int sumArray(int *xs,int n){
    int r = 0;
    for(int i=0;i<n;i++){
        r+=*xs;
        xs++;
    }
    return r;
}

int sumRec(int *xs,int n){
    if(n==0)
        return 0;
    return xs[n-1]+sumRec(xs,n-1);
}

/* ***************** problema 3 *****************************/

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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/* ***************** problema 4 *****************************/
/// archivo matrix.h /////


/* ***************** problema 5*****************************/
int lenArr(char *xs){
    int i=1;
    while(*xs!='\0'){
        i++;
        xs++;
    }
    return i;
}

int lenPtr(char *xs){
    char *ys=xs;
    for(;*xs!='\0';xs++)
        ;
    return (int)(xs-ys);
}

/*  ***************** problema 6 *****************************/

void copiar(char *xs, char *ys){
    int i;
    i=0;
    while((*(xs+i)=*(ys+i))!='\0'){
        i++;
    }
}

void copiarPtr(char *xs,char *ys){
    while(*xs=*ys!='\0'){
        xs++;
        ys++;
    }
}

/*  ***************** problema 7 *****************************/

void concatenar(char *xs, char *ys)
{
    int i, j;
    i=j=0;
    while(*(xs+i)!='\0')
        i++;
    *(xs+i)=*(ys+j);
}

void concatenarPtr(char *xs, char *ys)
{
    for(;*xs!='\0';xs++)
        ;
    *xs=*ys;
}

/*  ***************** problema 8 *****************************/
template<class T>
void swapT(T *xs,int i,int j){
    T temp;
    temp=*(xs+i);
    *(xs+i)=*(xs+j);
    *(xs+j)=temp;
}

template<class T>
void swapPtr(T *xs,int i,int j){
    T *temp=(xs+i);
    (xs+i)=(xs+j);
    (xs+j)=(xs+i);
}
/*  ***************** problema 9 *****************************/

bool palindromo(char *xs){
    int i=0;
    int k=lenPtr(xs);
    cout<<k<<endl;
    int j=k-1;
    while(i < k/2){
        if(*(xs+i)!=*(xs+j)){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

/*  ***************** problema 10 ****************************/

//función exponencial
float expo(float x, int y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x;
    else if(y>0)
        return x*expo(x,y-1);
    else if(y<0)
        return (1/x)*expo(x,y+1);
}

//convertidor de String a numero
float conver(char *xs)
{
    int i, m, j, potencia;  

    float base, n, decimal;
    n=0;
    base=10;
    decimal=0;
    potencia=0;
    for(i=0;*(xs+i)!='.';++i){
        if(*(xs+i)>='0'&& *(xs+i)<='9')
            n=10*n+1.0*(*(xs+i)-'0');
    }
    for(m=1;*(xs+i+m)!='e';m++){
        decimal=(*(xs+i+m)-'0')/(expo(base,m));   
        n+=decimal;
        if(*(xs+i+m)=='\0')
            return n;
    }
    j=1;
    if(*(xs+i+m+j)=='-'){
        for(j=2;*(xs+i+m+j)!='\0';++j){
            if(*(xs+i+m+j)>='0'&& *(xs+i+m+j)<='9') 
                potencia=10*potencia+(*(xs+i+m+j)-'0');
        }
        potencia=(-1)*potencia;
        return n*(expo(base,potencia));
    }
    else if(*(xs+i+m+j)!='-'){
        potencia=0;
        if(*(xs+i+m+j)=='+'){
            for(j=2;*(xs+i+m+j)!='\0';++j){
                if(*(xs+i+m+j)>='0'&& *(xs+i+m+j)<='9') 
                    potencia=10*potencia+(*(xs+i+m+j)-'0');
            }              
            return n*(expo(base,potencia));

        }
        for(j=1;*(xs+i+m+j)!='\0';++j){
            if(*(xs+i+m+j)>='0'&& *(xs+i+m+j)<='9') 
                potencia=10*potencia+(*(xs+i+m+j)-'0');
        }              
        return n*(expo(base,potencia));
    }
}


int main(){
/*  ***************** problema 1 *****************************/
    cout<<"***************** problema 1 ***************"<<endl;	
    int a=2,b=3;
    cuboRef(a);
    int c=cuboVal(b);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
/*  ***************** problema 2 *****************************/
    cout<<"***************** problema 2 ***************"<<endl;	
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);  //// solucion de la 5 para enteros  ////////
    cout<<sumArray(arr,n)<<endl;
    cout<<sumRec(arr,n)<<endl;
/*  ***************** problema 3 *****************************/
    cout<<"**************** problema 3 ****************"<<endl;	
    ///insertion<int>(arr,n);
    //mergeSort(arr,0,n-1);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
/*  ***************** problema 4 *****************************/
    cout<<"**************** problema 4 ****************"<<endl;
    Matrix A(2,3);
    Matrix B(3,2);
    Matrix C;
    A.inicializar();
    B.inicializar();
    C=A*B;
    C.imprimir(); 

/*  ***************** problema 5*****************************/
    cout<<"**************** problema 5 ***************"<<endl;
    char name[]="requiem";
    cout<<lenPtr(name)<<endl;
/*  ***************** problema 6*****************************/





    cout<<"************** problema 10 ****************"<<endl;
    char num_pos[]="123.456e+9";
    char num_neg[]="123.456e-9";
    cout<<conver(num_pos)<<endl;
    cout<<conver(num_neg)<<endl;
    return 0;
}

