#include "engine.h"

void mx_print(struct Matrix mx){
	int i,j;
	for(i = 0; i < mx.row; i++){
		
		printf("[  ");
		for(j = 0; j < mx.col; j++){
			printf("%0.3f  ",mx.grid[i * mx.col + j]);
		}
		printf("]\n");
	}
}

struct Matrix mx_init(int row, int col){
	struct Matrix mx;
	mx.row = row;
	mx.col = col;
	mx.grid = (double *) malloc (row * col * sizeof(double));
	int i, j;
	double ini = 0.0;
	i = row;
	j = col;
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			mx.grid[i * col + j] = ini;
		}
	}
	return mx;
}

double mx_get(struct Matrix mx, int row, int col){
	int i, j;
	for(i = 0; i <= mx.row; i++){
		for(j = 0; j <= mx.col; j++){
			if(i == row && j == col){
				return mx.grid[i * mx.col + col];
			}
		}
	}
}

struct Matrix mx_set(struct Matrix mx, int row, int col, double val){/*
	int f = fork();
	if(!f){*/
		int i, j;/*
		if( row > mx.row || col > mx.row || row < 0 || col < 0){
			printf("invalid matrix assignment\n");
			exit(0);
		}*/
		for(i = 0; i <= row; i++){
			for(j = 0; j <= col; j++){	
				if(j == col && i == row){
					mx.grid[i * mx.col + j] = val;
				}
			}
		}
	//}
	return mx;
}

struct Matrix mx_mult(struct Matrix m1, struct Matrix m2){
	struct Matrix m3;
	m3 = mx_init(m1.row,m2.col);
	int i,j,k,l,c;
	double s = 0;
	c = 0;
	for(i = 0; i < m1.row; i++){
		for(j = 0; j < m2.col; j++){
			for(k = 0; k < m1.col; k++){
				for(l = 0; k < m2.col; k++){
				 	s += mx_get(m1,i,k) * mx_get(m2,j,l);
				}
			}
			m3.grid[c] = s;
			c++;
			s = 0.0;
		}
	}
	return m3;
}

void mx_destroy(struct Matrix m1){
	
	
}
