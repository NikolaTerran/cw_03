#include "engine.h"

int main(){

printf("Create a matrix of size 4 x 4, call it m1\n");
struct Matrix m1;
m1 = mx_init(4,4);

printf("Populate m1 with some numbers\n");
int r,c;

for(r = 0; r < m1.row; r++){
	for(c = 0; c < m1.col; c++){
		m1 = mx_set(m1,r,c, (r * m1.col + c));
	}
}

printf("Print m1\n");
mx_print(m1);


printf("Create a identity matrix of m1, call it m2\n");
struct Matrix m2;
m2 = mx_iden(m1,0);

printf("Print m2\n");
mx_print(m2);


printf("Create a matix of size 4 x 2, call it m3\n");
struct Matrix m3;
m3 = mx_init(4,2);

printf("Populate m3 with some numbers\n");

for(r = 0; r < m3.row; r++){
	for(c = 0; c < m3.col; c++){
		m3 = mx_set(m3,r,c, (r * m3.col + c));
	}
}

printf("Print m3\n");
mx_print(m3);

printf("Add m3 to m1, call the resulting matrix m4\n");
struct Matrix m4 = mx_addc(m1,m3);

printf("Print m4\n");
mx_print(m4);

printf("Print the result of m1 multiplies m3\n");
mx_printf(mx_mult(m1,m3));

printf("Print the result of m1 multiplies its identity matrix\n");
mx_printf(mx_mult(m1,m2));

printf("Create a 4 elements double array, add it to m4, then print the result\n");
double ok[4];
ok[0] = 1.23;
ok[1] = 2.67;
ok[2] = 0.15;
ok[3] = 65;

mx_print(mx_qac(m4, ok, 4));
printf("Print the result of m4 without leftmost column\n");
mx_printf(mx_rmc(m4));

struct Matrix edge;
edge.row = 7;
//edge = addedge(edge,0,0,0,500,500,0,255000000);
//edge = addedge(edge,0,500,0,500,0,0,255000000);
// last step
/*
edge = addpoint(edge,0,0,0,255000000);
edge = addpoint(edge,0,500,0,255000000);
edge = addpoint(edge,500,0,0,255000000);
edge = addpoint(edge,500,500,0,255000000);
*/

edge = addedge(edge,20,120,			000,
				480,021,	000,	000,255,000);
edge = addedge(edge,480,021,			000,
				490,045,	000,	000,000,255);
edge = addedge(edge,490,045,			000,
	                	470,077,	000,	255,000,000);
edge = addedge(edge,470,077,			000,
				460,100,	000,	000,255,000);
edge = addedge(edge,460,100,			000,
				400,140,	000,	000,000,255);
edge = addedge(edge,400,140,			000,
	                	350,200,	000,	255,000,000);
edge = addedge(edge,350,200,			000,
				300,250,	000,	000,255,000);
edge = addedge(edge,300,250,			000,
				250,300,	000,	000,000,255);
edge = addedge(edge,250,300,			000,
	                	200,350,	000,	255,000,000);
edge = addedge(edge,200,350,			000,
				100,480,	000,	000,255,000);
edge = addedge(edge,100,480,			000,
				020,120,	000,	000,000,255);

/*
edge = addedge(edge,000,000,		000,
			    500,500,	000,	000,255,000);

edge = addedge(edge,500,000,		000,
			    000,500,	000,	000,000,255);


edge = addedge(edge,000,000,		000,
	                    000,500,	000,	255,000,000);

edge = addedge(edge,000,000,		000,
			    500,000,	000,	000,255,000);
/*		    
edge = addedge(edge,000,500,		000,
			    500,500,	000,	000,000,255);
*/
/*
edge = addedge(edge,500,000,		000,
	                    500,500,	000,	255,000,000);
*/
	                    
/*
edge = addedge(edge,000,000,			000,
							500,000,	000,	000,255,000);
edge = addedge(edge,500,000,			000,
							500,500,	000,	000,000,255);
edge = addedge(edge,000,500,			000,
	                		500,500,	000,	255,000,000);
/*

edge = addedge(edge,000,000,			000,
	                		000,499,	000,	255,000,000);
edge = addedge(edge,000,499,			000,
							499,000,	000,	000,255,000);
edge = addedge(edge,000,000,			000,
							499,499,	000,	000,000,255);
edge = addedge(edge,000,000,			000,
	                		000,499,	000,	255,000,000);
edge = addedge(edge,000,499,			000,
							499,000,	000,	000,255,000);
edge = addedge(edge,000,000,			000,
							499,499,	000,	000,000,255);
edge = addedge(edge,000,000,			000,
	                		000,499,	000,	255,000,000);
edge = addedge(edge,000,499,			000,
							499,000,	000,	000,255,000);
edge = addedge(edge,000,000,			000,
							499,499,	000,	000,000,255);
edge = addedge(edge,000,000,			000,
	                		000,499,	000,	255,000,000);

*/

mx_export(edge);

}
