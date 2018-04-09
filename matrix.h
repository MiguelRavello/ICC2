#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
using namespace std;

typedef int nat_t;

class Matrix {
public:
	nat_t **m_matrix;
	nat_t m_row;
	nat_t m_col;
public:
	Matrix():m_row(0),m_col(0){}
	Matrix(nat_t fila,nat_t columna):m_row(fila),m_col(columna){
		m_matrix = new nat_t*[m_row];
		for(int k=0;k<m_row;k++)
			m_matrix[k]=new nat_t[m_col];
	}
    void inicializar(){
        cout<<"ingrese los valores de la matrix: "<<endl;
        for (int i=0; i < m_row; i++){
            for (int j=0; j < m_col; j++){
                cout << "\nRow " << (i+1) << " Col " << (j+1) << " :";
                cin >> *(*(m_matrix + i) + j);
            }
        }
    }
	Matrix(Matrix &o):m_row(o.m_row),m_col(o.m_col){
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
	friend Matrix operator*(Matrix &m,Matrix &n){
		Matrix rpta(m.m_row,n.m_col);
		nat_t total=0;
		for(int i=0;i<m.m_row;++i){
            		for(int j=0;j<n.m_col;++j){
                		for(int z=0;z<m.m_col;++z){
                    			total += m.m_matrix[i][z] * n.m_matrix[z][j];
                		}
				rpta[i][j]=total;
				total=0;
            		}
        	}
        	return rpta;
	}
    void imprimir(){
        for(int i=0;i<m_row;i++){
            for(int j=0;j<m_col;j++){
                cout<<this->m_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};


#endif

