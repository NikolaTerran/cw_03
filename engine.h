#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
///////////////////line/////////////////////////////
int drawLine(int array[][500][3], int x1, int y1, int x2, int y2, int color[]);
void line_helper(int array[][500][3], int x1, int y1, int x2, int y2, int x3, int y3, int octants, int color[], double m);


/////////////////////matrix//////////////////////////

struct Matrix{
	double * grid;
	int row;
	int col;
};

void mx_print(struct Matrix m1);
struct Matrix mx_iden(struct Matrix m1);
struct Matrix mx_init(int row, int col);
struct Matrix mx_assign(struct Matrix mx, int row, int col, int val);
void mx_destroy(struct Matrix m1);

////////////////////general//////////////////////////
void initialize(int array[][500][3], int color[]);
void push(int array[][500][3],int file);
