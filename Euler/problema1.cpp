#include<iostream>
using namespace std;

int multiplo3(int n){
	int acc=0;
	int i;
	for(i=1;3*i<n;i++)
		acc+=3*i;
	cout<<i<<endl;
	return acc;
}

int multiplo5(int n){
	int acc=0;
	int i;
	for(i=1;5*i<n;i++)
		acc+=5*i;
	cout<<i<<endl;
	return acc;
}

int multiplo15(int n){
	int acc=0;
	int i;
	for(i=1;15*i<n;i++)
		acc+=15*i;
	cout<<i<<endl;
	return acc;
}


int main(){
	int c=multiplo3(1000)+multiplo5(1000)-multiplo15(1000);
	cout<<c<<endl;
	return 0;
}
