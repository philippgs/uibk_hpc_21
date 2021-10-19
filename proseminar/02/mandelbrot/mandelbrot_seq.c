#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Include that allows to print result as an image
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Default size of image
#define X 3840
#define Y 2160
#define MAX_ITER 10000

void calc_mandelbrot(uint8_t image[Y][X]) {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	const float left = -2.5, right = 1;
	const float bottom = -1, top = 1;
	int iter_count;

	for(int y_pixel = 0; y_pixel < Y; y_pixel++) {
		// scale y pixel into mandelbrot coordinate system
		const float cy = (y_pixel / (float)Y) * (top - bottom) + bottom;
		for(int x_pixel = 0; x_pixel < X; x_pixel++) {
			// scale x pixel into mandelbrot coordinate system
			const float cx = (x_pixel / (float)X) * (right - left) + left;
			float x = 0;
			float y = 0;
			iter_count = 0;

			/**
			 * Check if the distance from the origin becomes greater than 2
			 * and if the iteration does not exceed our maximum.
			 */
			while((x * x + y * y <= 2 * 2) && (iter_count < MAX_ITER)) {
				float x_tmp = x * x - y * y + cx;
				y = 2 * x * y + cy;
				x = x_tmp;
				iter_count += 1;
			}
			// Normalize iteration and write it to pixel position
			image[y_pixel][x_pixel] = fabs((iter_count / (float)MAX_ITER) * UINT8_MAX);
		}
	}
	gettimeofday(&end, NULL);
	double elapsed_time = (end.tv_sec + end.tv_usec * 1e-6) - (start.tv_sec + start.tv_usec * 1e-6);
	printf("Mandelbrot set calculation took: %f seconds.\n", elapsed_time);
}

int main() {
	uint8_t image[Y][X];

	calc_mandelbrot(image);

	const int channel_nr = 1, stride_bytes = 0;
	stbi_write_png("mandelbrot_seq.png", X, Y, channel_nr, image, stride_bytes);
	return EXIT_SUCCESS;
}
