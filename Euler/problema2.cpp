#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long int64;
vector<int64> acc;

int fib(int n){
	if(n==0 || n==1)
		return 1;
	return fib(n-1)+fib(n-2);
}

int64 fiboiterativo(int64 n){
    int64 r=(pow((1+sqrt(5))/2,n) - pow((1-sqrt(5))/2,n))/sqrt(5);
    return r;
}

void fibonacci(int64 n){
	if(n==0)
		acc.push_back(1);
	else{
		int64 x=fiboiterativo(n);
		acc.push_back(x);
		fibonacci(n-1);
	}
}

int main(){
 	fibonacci(33);
	int64 temp=0;
	for (vector<int64>::iterator it = acc.begin(); it != acc.end(); it++){
		if(*it & 1 == 1)
			continue;
		else{
			temp+=*it;
		}
	}
	cout << temp << endl;
	return 0;
}
