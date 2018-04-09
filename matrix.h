#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
using namespace std;

class Matrix {
public:
	int **m_matrix;
	int m_row;
	int m_col;
public:
	Matrix():m_row(0),m_col(0){}
	Matrix(int fila,int columna):m_row(fila),m_col(columna){
		m_matrix = new int*[m_row];
		for(int k=0;k<m_row;k++)
			m_matrix[k]=new int[m_col];
	}
    void inicializar(){
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
	Matrix(const Matrix &o):m_row(o.m_row),m_col(o.m_col){
		for (int i=0; i < m_row; i++){
			for (int j=0; j < m_col; j++){
				*(*(m_matrix + i) + j)=*(*(o.m_matrix + i) + j);
			}
		}
	}
	~Matrix(){
		for(int i=0;i<m_row;i++)	
			delete[] m_matrix[i];
		delete[] m_matrix;
	}
	Matrix operator*(const Matrix &n){
		Matrix rpta(m_row,n.m_col);
		int total=0;
		for(int i=0;i<m_row;++i){
            		for(int j=0;j<n.m_col;++j){
                		for(int z=0;z<m_col;++z){
                    			total += m_matrix[i][z] * n.m_matrix[z][j];
                		}
				rpta.m_matrix[i][j] =total;
				total=0;
            		}
        	}
        	return rpta;
	}
    void imprimir(){
        for(int i=0;i<m_row;i++){
            for(int j=0;j<m_col;j++){
                cout<<m_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};


#endif

