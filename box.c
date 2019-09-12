/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex2
 * box.c
 * This program reads three positive integers representing the length, width and height of a box, and computes (1) its surface area, and (2) the length of the diagonal between two vertices of the box that are furthest apart.
 * Samuel Paul Christopher
 * C08
 */

#include <stdio.h>
#include <math.h>

int computeSurfaceArea();
double computeDiagonal();

int main(void) {
	int length, width, height;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);

	printf("Surface area = %d\n", computeSurfaceArea(length, width, height));
	printf("Diagonal = %.2f\n", computeDiagonal(length, width, height));


	return 0;
}

// computeSurfaceArea() takes in the length, witdth and height of a box and returns its surface area
int computeSurfaceArea(int length, int width, int height) {
	int surfaceArea = 2 * ((length * height) + (length * width) +(height * width));
	return surfaceArea;
}

// computeDiagonal() takes in the length, width and height of a box and returns the diagonal between two vertices of the box that are furthest apart
double computeDiagonal(int length, int width, int height) {
	// first find the largest, second largest and smallest dimensions
	int largest, second, smallest;
	largest = 0;
	second = 0;
	smallest = 0;

	if (length > largest) {
		largest = length;
		if (width > height) {
			second = width;
			smallest = height;
		} else {
			second = height;
			smallest = width;
		}
	}
	
	if (width > largest) {
		largest = width;
		if (length > height) {
			second = length;
			smallest = height;
		} else {
			second = height;
			smallest = length;
		}
	}

	if (height > largest) {
		largest = height;
		if (length > width) {
			second = length;
			smallest = width;
		} else {
			second = width;
			smallest = length;
		}
	}

	// calculate diagonal by
	// 1. calculate the base diagonal using largest and shortest
	// 2. calculate the diagoanl between the vertices that are furthest apart using the base diagonal and second

	double baseDiagonalSquared, diagonal;

	baseDiagonalSquared = pow(largest, 2) + pow(smallest, 2);
	diagonal = sqrt(baseDiagonalSquared + pow(second, 2));

	return diagonal;
}
