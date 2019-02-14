#include "engine.h"


void db(char * say,double a){
	printf("%s:%f\n",say,a);
}

int* sys_random(int size){
	int *buffer;
	buffer = malloc(sizeof(int) * size );
	
	printf("initiating...this may take several minites\n");
	
	FILE* file = fopen("/dev/urandom", "r");
	fread(buffer, sizeof(int), size ,file);
	
	//close(file);
	//printf("wut\n");
	return buffer;
}

void line_helper(int array[][500][3], int x1, int y1, int x2, int y2, int x3, int y3, int octants, int color[], double m){
	
	double slope;

	while(x3 != x2 && y3 != y2){
		slope = ((double)y1 - (double)y3)/((double)x3 - (double)x1);
		switch(octants){
			case 1: 
					if(slope > m){
						//db("slope",slope);
					    //db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 ++;
						//y3 --;
					}else{
					    //db("slope",slope);
					    //db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 ++;
						y3 --;
					}		
			break;
			case 2: //up right
					if(slope > m){
						db("slope",slope);
						//db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 ++;
						y3 --;
					}else{
						db("slope",slope);
						//db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						//x3 ++;
						y3 --;
					}		
			break;
			case 3: //up left
					if(slope < m){
						db("slope",slope);
						//db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 --;
						y3 --;
					}else{
						db("slope",slope);
						//db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						//x3 --;
						y3 --;
					}
			break;
			case 4: //left up
					if(slope < m){
						db("slope",slope);
						//db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						
						x3 --;
					}else{
						db("slope",slope);
						//db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						y3 --;
						x3 --;
					}
			break;
		}
	}
}

int drawLine(int array[][500][3], int x1 , int y1, int x2, int y2, int color[]){
	if(x2 == x1 && y2 == y1){
				array[y1][x1][0] = color[0];
				array[y1][x1][1] = color[1];
				array[y1][x1][2] = color[2];
	}else{
				//{double m = 1;}
			double m = ((double)y1 - (double)y2) / ((double)x2 - (double)x1);
			db("m",m);
			
				array[y1][x1][0] = color[0];
				array[y1][x1][1] = color[1];
				array[y1][x1][2] = color[2];
			
				if(y2 <= y1){
					if(x2 >= x1){
						if( m <= 1 ){
							 line_helper(array,x1,y1,x2,y2,x1 + 1,y1 - 1,1,color,m);
						}else{
							 line_helper(array,x1,y1,x2,y2,x1 + 1,y1 - 1,2,color,m);
						}
					}else{
						if( m <= -1 ){
							 line_helper(array,x1,y1,x2,y2,x1 - 1,y1 - 1,3,color,m);
						}else{
							 line_helper(array,x1,y1,x2,y2,x1 - 1,y1 - 1,4,color,m);
						}
					}
				}else{
				   if(x2 < x1){
						if( m <= 1 ){
							 line_helper(array,x2,y2,x1,y1,x2 + 1,y2 - 1,1,color,m);
						}else{
							 line_helper(array,x2,y2,x1,y1,x2 + 1,y2 - 1,2,color,m);
						}
					}else{
						if( m <= -1 ){
							 line_helper(array,x2,y2,x1,y1,x2 - 1,y2 - 1,3,color,m);
						}else{
							 line_helper(array,x2,y2,x1,y1,x2 - 1,y2 - 1,4,color,m);
						}
					}
				}
	}
}

void initialize(int array[][500][3], int color[]){

	//char line[20];
	int i, j;
	
	//snprintf(line, sizeof(line), "P3 500 500 255\n");
	//write (file, line, strlen(line));
	
	for(i=0; i < 500; i ++){
		for(j=0; j < 500; j++){
			array[i][j][0] = color[0];
			array[i][j][1] = color[1];
			array[i][j][2] = color[2];
		}		 
	}
}

void push(int array[][500][3],int file){
	char line[20];
	int i,j;

	snprintf(line, sizeof(line), "P3 500 500 255\n");
	write (file, line, strlen(line));
	for(i=0; i < 500; i ++){
			for(j=0; j < 500; j++){
				snprintf(line, sizeof(line), "%d %d %d\n", array[i][j][0], array[i][j][1], array[i][j][2]);
				write(file, line, strlen(line));
			}		 
		}
}


int main(){

// important variables
/*
int fd, i, j , k;
int rgb[3];

// getting the file setup

int array[500][500][3];

fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);

rgb[0] = 255;
rgb[1] = 255;
rgb[2] = 255;

initialize(array,rgb);
*/

// randomly drawing stuff

/*
rgb[0] = 255;
rgb[1] = 0;
rgb[2] = 0;

srand(time(NULL));
i = 0;
while(i < 100){
int x_1 = rand() % 500;
int y_1 = rand() % 500;
int x_2 = rand() % 500;
int y_2 = rand() % 500;
rgb[0] = rand() % 255;
rgb[1] = rand() % 255;
rgb[2] = rand() % 255;

drawLine(array, x_1, y_1, x_2, y_2, rgb);
i++;
}
*/
// matrix stuff
struct Matrix m1;
m1 = mx_init(4,10);
int r,c;
for(r = 0; r < m1.row; r++){
	for(c = 0; c < m1.col; c++){
		m1 = mx_assign(m1,r,c, 1);
	}
}
mx_print(m1);

// last step
	//push(array,fd);

}
