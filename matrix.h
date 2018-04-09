#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
using namespace std;

template<class T>
class Matrix {
public:
	T **m_matrix;
	int m_row;
	int m_col;
public:
	Matrix():m_row(0),m_col(0){}
	Matrix(int,int);
    Matrix(const Matrix &m);
    ~Matrix(){
        for(int i=0;i<m_row;i++)        
            delete[] m_matrix[i];
        delete[] m_matrix;
    }

    friend ostream& operator<<(ostream& out,Matrix &o){
        for(int i=0;i<o.m_row;i++){
            for(int j=0;j<o.m_col;j++){
                out<<o.m_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        return out;
    }
    Matrix<T> operator* (const Matrix &o);
    void operator= (const Matrix &o);
    void inicializar();
    void imprimir();
};

template<class T>
Matrix<T>::Matrix(int fila,int col):m_row(fila),m_col(col){
    m_matrix = new T*[m_row];
    for(int i=0;i<m_row;i++){
        m_matrix[i]=new T[m_col];
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix &m):m_row(m.m_row),m_col(m.m_col){
    m_matrix = new T*[m_row];
    for(int k=0;k<m_row;k++){
        m_matrix[k]=new T[m_col];
    }
    for (int i=0; i < m_row; i++){
        for (int j=0; j < m_col; j++){
            *(*(m_matrix + i) + j)=*(*(m.m_matrix + i) + j);
        }
    }
}
template<class T>
void Matrix<T>::inicializar(){
    cout<<"ingrese los valores de la matrix: "<<endl;
    int elem;
    for (int i=0; i < m_row; i++){
        for (int j=0; j < m_col; j++){
            cout << "\nRow " << (i+1) << " Col " << (j+1) << " :";
            cin >> elem; 
            m_matrix[i][j]=elem;
        }
    }
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix &o){
    Matrix rpta(m_row,o.m_col);
    T total=0;
    for(int i=0;i<m_row;++i){
        for(int j=0;j<o.m_col;++j){
            for(int z=0;z<m_col;++z){
                total += m_matrix[i][z] * o.m_matrix[z][j];
            }
            rpta.m_matrix[i][j] =total;
            total=0;
        }
    }
    return rpta;
}

template<class T>
void Matrix<T>::operator=(const Matrix &o){
    m_row=o.m_row;
    m_col=o.m_col;
    m_matrix=new T*[m_row];
    for(int k=0;k<m_row;k++){
        m_matrix[k]=new T[m_col];
    }
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            *(*(m_matrix + i) + j)=*(*(o.m_matrix + i) + j);
        }
    }
}

template<class T>
void Matrix<T>::imprimir(){
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            cout<<m_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

#endif

