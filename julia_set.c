#include <complex.h> 
#include <stdio.h> 
#include <tgmath.h> 
#include <graphics.h> 
  
#define X 1000
#define Y 1000
#define ROWS 1000
#define COLUMNS 1000
  
// To recursively find the end value 
// of the passed point till the pixel 
// goes out of the bounded region 
// or the maximum depth is reached. 
int julia_point(float x, float y, 
                int r, int depth, 
                int max, 
                double _Complex c, 
                double _Complex z, int** matriz) 
{ 
    if (cabs(z) > r) { 
        // putpixel(x, y, 
        //          WHITE);
				 matriz[(int)x][(int)y] = 15;
        depth = 0; 
    } 
    if (sqrt(pow((x - X / 2), 2) 
             + pow((y - Y / 2), 2)) 
        > Y / 2) { 
        // putpixel(x, y, 0); 
		matriz[(int)x][(int)y] = 0;
    } 
    if (depth < max / 4) { 
        return 0; 
    } 
    julia_point(x, y, r, 
                depth - 1, max, 
                c, cpow(z, 2) + c, matriz); 
} 
  
// To select the points in a Julia set. 
void juliaset(int depth, double _Complex c, int r, int detail, int** matriz) 
{ 
    for (float x = X / 2 - Y / 2; x < X / 2 + Y / 2; x += detail) { 
        for (float y = 0; y < Y; y += detail) { 
            julia_point(x, y, r, 
                        depth, depth, c, 
                        (2 * r * (x - X / 2) / Y) 
                            + (2 * r * (y - Y / 2) / Y) 
                                  * _Complex_I, matriz); 
        } 
    } 
} 

int main() {
	// initwindow(X, Y); 
	int** matriz = (int**)malloc(ROWS * sizeof(int**));
	for(int i = 0; i < ROWS; i++) {
		matriz[i] = (int*)malloc(COLUMNS * sizeof(int*));
	}

	int gd = 9, gm = 2, colors;
	// int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
	// initgraph(&gd, &gm, ""); 
    int depth = 50, r = 2, detail = 1; 
  
    // Initial value for Julia 
    // set taken by my personal preference. 
    double _Complex c = -0.267 - 0.611 * _Complex_I; 

	juliaset(depth, c, r, detail, matriz); 
	
	// getch();

	// closegraph();
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}