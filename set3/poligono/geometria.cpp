#include"geometria.h"

/* ************clase arreglo de puntos *************/

puntoArr::puntoArr():m_size(0){
    m_puntos=new punto[0];
}

puntoArr::puntoArr(const punto xs[],const int len):m_size(len){
    m_puntos=new punto[m_size];
    for(int i=0;i<m_size;i++)
        *(m_puntos+i)=xs[i];
}

//cualquier codigo en la clase puntoArr tiene acceso a variables privadas
puntoArr::puntoArr(const puntoArr &other):m_size(other.m_size){
    m_puntos=new punto[m_size];
    for(int i=0;i<m_size;i++)
        *(m_puntos+i)=other.m_puntos[i];
}

puntoArr::~puntoArr(){
    delete[] m_puntos;
}

void puntoArr::resize(int nuevo){
    punto *xs=new punto[nuevo];
    int minimo=(nuevo>m_size ? m_size : nuevo);
    for(int i=0;i<minimo;i++)
        xs[i]=m_puntos[i];
    delete[] m_puntos;
    m_size=nuevo;
    m_puntos=xs;
}

void puntoArr::clear(){
    resize(0);
}

void puntoArr::push_back(const punto &p){
    resize(m_size+1);
    m_puntos[m_size-1]=p;
}

void puntoArr::insert(const int pos,const punto &p){
    resize(m_size+1);
    for(int i=m_size-1;i>pos;i--)
        m_puntos[i]=m_puntos[i-1];
    m_puntos[pos]=p;
}
/* 12346789 */
/* 1234-6789 se desplaza los elementos hasta la posicion*/
/* 123456789 se agrega el elemento en la posicion deseada*/

void puntoArr::remove(const int pos){
    if(pos>=0 && pos<m_size){
        for(int i=pos;i<m_size-2;i++)
            m_puntos[i]=m_puntos[i+1];
        resize(m_size-1);
    }
}
/* 0123456789 */
/* 012346789- se reasigna los elementos  */
/* 012346789  se redimenciona --m_size */

punto *puntoArr::get(const int pos){
    return (pos>=0 && pos<m_size) ? m_puntos+pos : NULL;
}

const punto *puntoArr::get(const int pos) const{
    return (pos>=0 && pos<m_size) ? m_puntos+pos : NULL;
}

/* puntero constante solo r
   y puntero no constante para wr */

/****************** clase poligono  ************************/
int poligono::m_np=0;  /* numero de poligonos instanciados */

poligono::poligono(const puntoArr &xs): m_lista(xs){
    m_np++;
}

poligono::poligono(const punto puntos[],const int len):m_lista(puntos,len){
    m_np++;
}

/****************** clase rectangulo ********************/
punto global[4];

punto* updateConstructor(const punto &p1,const punto &p2,const punto &p3,const punto &p4 = punto(0,0)  ){
    global[0]=p1;
    global[1]=p2;
    global[2]=p3;
    global[3]=p4;
    return global;
}

rectangulo::rectangulo(const punto &p1,const punto &p2)
    :poligono(updateConstructor( p1 , punto(p1.getX(),p2.getY()) , p2 , punto(p2.getX(),p1.getY()) ) , 4 ) {}

rectangulo::rectangulo(const int a,const int b,const int c, const int d)
    :poligono(updateConstructor( punto(a,b) , punto(c,b) , punto(c,d) , punto(a,d) ) , 4 ) {}

double rectangulo::area() const{
    int altura = m_lista.get(0)->getY() - m_lista.get(2)->getY();
    int base   = m_lista.get(2)->getX() - m_lista.get(0)->getX();
    return abs((double) base * altura );
}

triangulo::triangulo(const punto &p1,const punto &p2,const punto &p3)
    :poligono(updateConstructor( p1, p2, p3), 3) {}

double triangulo::area() const{
    int dx01 = m_lista.get(0)->getX() - m_lista.get(1)->getX(),
        dx12 = m_lista.get(1)->getX() - m_lista.get(2)->getX(),
        dx20 = m_lista.get(2)->getX() - m_lista.get(0)->getX();

    int dy01 = m_lista.get(0)->getY() - m_lista.get(1)->getY(),
        dy12 = m_lista.get(1)->getY() - m_lista.get(2)->getY(),
        dy20 = m_lista.get(2)->getY() - m_lista.get(0)->getY();

    double a = sqrt(dx01*dx01 + dy01*dy01),
           b = sqrt(dx12*dx12 + dy12*dy12),
           c = sqrt(dx20*dx20 + dy20*dy20);

    double s = (a + b + c) / 2;

    return sqrt( s * (s -a) * (s -b) * (s -c) );
}

/***********************5.6*****************/

/* Si el constructor de Punto se hace privado; ps en un inicio 
 * no se podria instanciar desde el main  */

/* Cuando un objeto Poligono es destruido, el contador de poligonos
 * decrece m_np--  */

/* poligono tiene protected: Dado q protege sus datos miembros y 
 * ademas para sus clases derivadas puedan acceder a ellas */

/* Si anulamos getnumSides o Lados de triangulo, rectangulo
 * Si podriamos llamar a getnumSide pq lo usariamos de la clase
 * poligono, pq no es una funcion virtual 
   polyPtr->getNumSides()*/

/******************** 5.7 *****************/
void print(poligono *p) {
    cout << "Su area es " << p->area() << endl;
    cout << "sus puntos son: "<<endl;
    const puntoArr *pa = p->getpuntos();
    for (int i = 0; i < pa ->getSize(); ++i){
        cout << "(" << pa ->get(i) ->getX() << ", " << pa ->get(i) -> getY() << ")"<<endl;
    }
}

int main(){
    punto a(2,2);
    punto b(-1,-1);
    punto c(-1,2);
    
    rectangulo r(a,b);
    triangulo  t(a,b,c);
    cout<<"rectangulo"<<endl;
    print(&r);
    cout<<"triangulo"<<endl;
    print(&t);
    return 0;
}


