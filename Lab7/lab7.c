#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Benjamin Muslic
muslicb@iastate.edu
CPRE185
Section 7
 */

#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {
	


	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg=0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1|| lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}

	int t, b_Left;
	double ax, ay, az, avg_x, avg_y, avg_z, xmin, xmax, ymin, ymax, zmin, zmax;
	int b_triangle, b_X, b_Square, b_Circle;

	for (int i=0; i < lengthofavg; i++) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &b_triangle, &b_X, &b_Square, &b_Circle);
		updatebuffer(x, lengthofavg, ax);
		updatebuffer(y, lengthofavg, ay);
		updatebuffer(z, lengthofavg, az);
	}

	
/* 	if(lengthofavg < 1) {
		printf("Please enter buffer value: ");
		scanf("%d", &lengthofavg);
} */
	do {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &b_triangle, &b_X, &b_Square, &b_Circle );
			updatebuffer(x, lengthofavg, ax);
			updatebuffer(y, lengthofavg, ay);
			updatebuffer(z, lengthofavg, az);

		
		
		avg_x = avg(x, lengthofavg);
		avg_y = avg(y, lengthofavg);
		avg_z = avg(z, lengthofavg);
		
		maxmin(x, lengthofavg, &xmax, &xmin);
		maxmin(y, lengthofavg, &ymax, &ymin);
		maxmin(z, lengthofavg, &zmax, &zmin);
		
		for (int i =0; i<lengthofavg; i++){
			printf("%lf, %lf, %lf\n", x[i], y[i], z[i]);
		}
		
		
		printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", ax, ay, az, avg_x, avg_y, avg_z, xmin, xmax, ymin, ymax, zmin, zmax);
		fflush(stdout);
	} 
	while(b_Square != 1);

	return 1;
}

double avg(double buffer[], int num_items) {
	double avg = 0;
	int i;
	for(i = 0; i < num_items; i+=1) {
		avg = avg + buffer[i];
	}
	return avg/(num_items/1.0);
}

void maxmin(double array[], int num_items, double* max, double* min) {
	int i;

	
	for(i = 0; i < num_items; i+=1) {
		if(array[i] > *max) {
			*max = array[i];
		}
		if(array[i] < *min) {
			*min = array[i];
		}
	}
}

void updatebuffer(double buffer[], int length, double new_item) {
	//double nbuf[MAXPOINTS];
	int i;
	for(i = 0; i < length-1; i+=1) {
		buffer[i] = buffer[i+1];
	}
	buffer[length-1] = new_item;
}

