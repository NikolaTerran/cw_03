#include "engine.h"

void line_helper(int array[][500][3], int x1, int y1, int x2, int y2, int x3, int y3, int octants, int color[], double m){
	
	double slope;

	while(x3 != x2 && y3 != y2){
		slope = ((double)y1 - (double)y3)/((double)x3 - (double)x1);
		switch(octants){
			case 1: 
					if(slope > m){
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 ++;
						//y3 --;
					}else{
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 ++;
						y3 --;
					}		
			break;
			case 2: //up right
					if(slope > m){
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 ++;
						y3 --;
					}else{
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						//x3 ++;
						y3 --;
					}		
			break;
			case 3: //up left
					if(slope < m){
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 --;
						y3 --;
					}else{
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						//x3 --;
						y3 --;
					}
			break;
			case 4: //left up
					if(slope < m){
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						
						x3 --;
					}else{
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
			
				array[y1][x1][0] = color[0];
				array[y1][x1][1] = color[1];
				array[y1][x1][2] = color[2];
			if((x2 - x1) == 0){
				if(y1 <= y2){
					while(y1 != y2){
						array[y1][x1][0] = color[0];
						array[y1][x1][1] = color[1];
						array[y1][x1][2] = color[2];
						
						y1 ++;
					}
				}else{
					while(y1 != y2){
						array[y1][x1][0] = color[0];
						array[y1][x1][1] = color[1];
						array[y1][x1][2] = color[2];
						
						y1 --;
					}
				}
			}else if((y2 - y1) == 0){
				if(x1 <= x2){
					while(x1 != x2){
						array[y1][x1][0] = color[0];
						array[y1][x1][1] = color[1];
						array[y1][x1][2] = color[2];
						
						x1 ++;
					}
				}else{
					while(x1 != x2){
						array[y1][x1][0] = color[0];
						array[y1][x1][1] = color[1];
						array[y1][x1][2] = color[2];
						
						x1 --;
					}
				}
			}else{ 
									if(y2 <= y1){
										if(x2 >= x1){
											if( m <= 1 ){
												 line_helper(array,x1 - 1,y1 + 1,x2,y2,x1,y1,1,color,m);
											}else{
												 line_helper(array,x1 - 1,y1 + 1,x2,y2,x1,y1,2,color,m);
											}
										}else{
											if( m <= -1 ){
												 line_helper(array,x1 + 1,y1 + 1,x2,y2,x1,y1,3,color,m);
											}else{
												 line_helper(array,x1 + 1,y1 + 1,x2,y2,x1,y1,4,color,m);
											}
										}
									}else{
									   if(x2 < x1){
											if( m <= 1 ){
												 line_helper(array,x2 - 1,y2 + 1,x1,y1,x2,y2,1,color,m);
											}else{
												 line_helper(array,x2 - 1,y2 + 1,x1,y1,x2,y2,2,color,m);
											}
										}else{
											if( m <= -1 ){
												 line_helper(array,x2 + 1,y2 + 1,x1,y1,x2,y2,3,color,m);
											}else{
												 line_helper(array,x2 + 1,y2 + 1,x1,y1,x2,y2,4,color,m);
											}
										}
									}
			}
	}
}
