#include "engine.h"

void mx_print(struct Matrix mx){
	int i,j;
	for(i = 0; i < mx.row; i++){
		
		printf("[  ");
		for(j = 0; j < mx.col; j++){
			printf("%.6g  ",mx.grid[i * mx.col + j]);
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

struct Matrix mx_assign(struct Matrix mx, int row, int col, int val){/*
	int f = fork();
	if(!f){*/
		int i, j;/*
		if( row > mx.row || col > mx.row || row < 0 || col < 0){
			printf("invalid matrix assignment\n");
			exit(0);
		}*/
		for(i = 0; i != row; i++){
			for(j = 0; j != col; j++){
				if(j == col){
					mx.grid[i * col + j] = val;
				}
			}
		}
	//}
	return mx;
}

void mx_destroy(struct Matrix m1){
	
	
}
