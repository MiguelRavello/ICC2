#include"cajero.h"

int main(){
    Cajero *b50 = new Billete50();
    Cajero *b20 = new Billete20();
    Cajero *b10 = new Billete10();
    Cajero *b5  = new Billete5();
//    Cajero *b5 = NULL;  // el ultimo handler

    b50->setNext(b20);
    b20->setNext(b10);
    b10->setNext(b5);

    try{
        b50->devuelveBilletes(23);
    } catch(const char* msg){
        cerr << msg << endl;
    }

    delete b50;
    delete b20;
    delete b10;
    delete b5;

    return 0;
}
