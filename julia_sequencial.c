#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 1000
#define COLUMNS 1000

void array_to_file(int* array)
{
	FILE* out = fopen("result_sequencial.txt", "w");

	int i = 0;
	for (i = 0; i < ROWS * COLUMNS; i++) {
		fprintf(out, "%d ", array[i]);
	}

	fclose(out);
}


int main(int argc, char** argv) {
	int iterations = atoi(argv[1]);
	float cx = atof(argv[2]);
	float cy = atof(argv[3]);

	float zx, zy;
	float temp;

	int counter = 0;
	int color;
	int* colors = malloc(ROWS * COLUMNS * sizeof(int));

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			zx = (float)(i + 1 - ROWS / 2) / (ROWS / 4);
			zy = (float)(j + 1 - COLUMNS / 2) / (COLUMNS / 4);

			color = 0;
			
			while ((float)zx * zx + zy * zy <= 16.00 && color <= iterations) {
				temp = (float)zx * zx - zy * zy;
				zy = (float)2 * zx * zy + cy;
				zx = (float)temp + cx;
				color++;
			}

			colors[counter] = color;
			counter++;
		}
	}
	array_to_file(colors);
}