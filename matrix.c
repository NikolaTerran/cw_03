void display(struct Matrix m1){
	

}

struct Matrix mx_init(int row, int col){
	struct Matrix mx;
	mx.row = row;
	mx.col = col;
	mx.grid = (double *)malloc(row * col * sizeof(int));
	int i, j , ini;
	i = row;
	j = col;
	ini = 0;
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			mx.grid[i * col + j] = ini;
		}
	}
	return mx;
}

struct Matrix assign(struct Matrix mx, int row, int col, int val){
	int f = fork();
	if(!f){
		if( row >= mx.row || col >= mx.row || row < 0 || col < 0){
			printf("invalid matrix assignment\n");
			exit(0);
		}
		for(i = 0; i != row; i++){
			for(j = 0; j != col; j++){
				if(j == col){
					mx.grid[i * col + j] = val;
				}
			}
		}
	}
	return mx;
}

void mx_destroy(struct Matrix m1){
	
	
}
