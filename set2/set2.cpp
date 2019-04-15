#include<iostream>
#include<cmath>
#include<cstdlib> //rand()
#include<ctime> //time()
using namespace std;

/* problema 3.1 */
/* Se declara el prototipo de la funcion, para informar al compilador
 * que existe, y luego definir el cuerpo de la funcion en cualquier lugar */
void printNum(int);

/* problema 3.2 */
/* void printNum() { std::cout << number; };
 * agregandole int n, para el argumento */
void printN2(int n){cout<<n<<endl;}; //con o sin ; tmb funciona
/* Una segunda forma es con la variable global*/
int N=8081;
void printNglobal(){cout<<N<<endl;}

/* problema 3.3 */
/* Necesita el paso por referencia */
void dobleN(int &n){n*=2;}

/* problema 3.4 */
int dif(const int x,const int y){
    return abs(x-y); //solo faltaba el return
}

/* problema 3.5 */
int sum(const int x,const int y,const int z){ ///falto agregar un tercer elemento
    return x+y+z;
}

/* proeblema 3.6 */
const int ARRAY_LEN = 10;

/* problema 4.1 */
/* suma de dos enteros y dos doubles*/
template<class T>
T suma(T x,T y){
    return x+y;
}

/* problema 4.3 y 4.4*/
/* suma de dos a cuatro enteros */
int suma4(int a,int b,int c=0,int d=0){
    return a+b+c+d;
}

/* problema 4.5 */
/* suma de los elementos del arreglo */
int sumArr(int *xs,int len){
    int r=0;
    for(int i=0;i<len;i++){
        r+=xs[i];
    }
    return r;
}

/* problema 4.6 */
/* Suma de elementos del arreglo en modo recursivo */
int sumaRec(int *xs, int len){
    if(len==0)
        return 0;
    return xs[len-1]+sumaRec(xs,len-1);
}

/* problema 5.2 */
int dart(const int n){
    int dardo=0;
    for(int i=0;i<n;i++){
        double x=rand()/(double)RAND_MAX , y=rand()/(double)RAND_MAX;
        if(sqrt(x*x+y*y)<1)
            dardo++;
    }
    return dardo;
}

/* problema 5.3 */
double computePi(int (*f)(const int),const int n){
    srand(time(0));
    int dardo=f(n);
    cout<<dardo<<endl;
    return dardo/static_cast<double>(n)*4;
}

/* problema 6.1 */
void imprimir(int *xs,const int n){
    for(int i=0;i<n;i++){
        cout<<xs[i];
        if(i<n-1)
            cout<<", ";
    }
}

/* problema 6.2 */
/* invierte el arreglo; recorriendo el arreglo como el palindromo */
void reversa(int *xs,const int n){
    for(int i=0;i<n/2;i++){
        int temp=xs[i];
        int indice_final=n-i-1;
        xs[i]=xs[indice_final];
        xs[indice_final]=temp;
    }
}

/* problema 6.3 */
void transpuesta(int **xs, int **ys, const int largo, const int ancho){
    for(int i=0;i<largo;i++){
        for(int j=0;j<ancho;j++){
            ys[j][i]=xs[i][j];
        }
    }
}
/* problema 6.4 */
/* puntero invalido por deslocalizacion */

/* problema 6.5 */
void reversePtr(int *xs, const int n){
    for(int i=0;i<n/2;i++){
        int temp=*(xs+i);
        int indice=n-i-1;
        *(xs+i)=*(xs+indice);
        *(xs+indice)=temp;
    }
}

/* problema 7.1 */
int longitud(char *xs){
    int i=0;
    for(;*xs!='\0';xs++){
        i++;
    }
    return i;
}
/* problema 7.2 */
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void swapPtr(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void swapDoble(int **x,int **y){
    int *temp=*x;
    *x=*y;
    *y=temp;
}


int main(){
    cout<<" ****** problema 2  ******* "<<endl;
    cout<<" imprimira: 2 246 6 8 10 "<<endl;

    cout<<" ****** problema 3.1  ***** "<<endl;
    printNum(35);

    cout<<" ****** problema 3.2  ***** "<<endl;
    int n=35;
    printN2(n);
    cout<<"con variable global"<<endl;
    printNglobal();
    cout<<" ****** problema 3.3  ***** "<<endl;
    dobleN(n);
    cout<<n<<endl;

    cout<<" ****** problema 3.4  ***** "<<endl;
    cout<<dif(24,1238)<<endl;

    cout<<" ****** problema 3.5  ***** "<<endl;
    cout<<sum(1,2,3)<<endl;

    cout<<" ****** problema 3.6  ***** "<<endl;
    int arr[ARRAY_LEN] = {10};
    /* inicializa el arreglo al arr[0]=10 y el resto con 0*/
    //int tam=sizeof(arr)/sizeof(arr[0]);
    //for(int i=0;i<tam;i++)
    //    cout<<arr[i]<<endl;
    int *xptr=arr;
    int *yptr=arr + ARRAY_LEN - 1; //falto agregar * a yptr
    cout<<*xptr<<" "<<*yptr<<endl;

    cout<<" ****** problema 4.1 ****** "<<endl;
    cout<<suma<int>(3,2)<<" "<<suma<float>(3.5,2.8)<<endl;

    cout<<" ****** problema 4.2  ***** "<<endl;
    cout<<"en suma(1, 1.0)es error sintaxis dado q no son del mismo tipo a menos q sean casteados"<<endl;

    cout<<" ****** problema 5.1  ***** "<<endl;
    /* valores aleatorios entre 0 y 1 */
    double x=rand()/(double)(RAND_MAX);
    double y=rand()/(double)(RAND_MAX);
    cout<<x<<"\n"<<y<<endl;
    cout<<"************* problema 5.3 *******"<<endl;
    double pi=computePi(dart,5000000);
    cout<<"pi: "<<pi<<endl;
    cout<<"problema 7.5"<<endl;
    string temporal = "Never odd or even";
    char *oddOrEven=&temporal[0];
    char *abc=&oddOrEven[5];
    abc -=2;
    cout<<*abc<<endl;
    char **puntero=&abc;
    cout<<puntero<<endl;
    cout<<**puntero<<endl;
    abc++;
    cout<< abc - oddOrEven <<endl;
    return 0;
}

/* problema 3.1 */
void printNum(int n){cout<<n<<endl;}
