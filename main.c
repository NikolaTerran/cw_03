#include "engine.h"

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
		m1 = mx_set(m1,r,c, (r + c + 0.132));
	}
}

//m1.grid[1] = 3.24;
mx_print(m1);

// last step
	//push(array,fd);

}
