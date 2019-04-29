#include<iostream>
#include<string>

using namespace std;

const string vocales = "aeiou"; //recordar q el fin de linea \0;

string pigLatin(const string xs){
    if(xs.size()==0)
        return xs;
    if(xs.find("qu")==0){ // find==posicion inicial
        //question -> estion +-+ qu + ay
        return xs.substr(2,xs.size()-2) + "-" + xs.substr(0,2)+"ay";
    }
    else if(vocales.find(xs[0]) != string::npos ){ //empieza con vocal
        return xs+"way";
    }
    else{ //happy  -> appy + hay
        return xs.substr(1,xs.size()-1)+"-"+xs[0]+"ay";
    }
}

int main(){
    string xs="question";
    cout<<pigLatin(xs)<<endl;
    return 0;
}
