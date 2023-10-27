#include <stdio.h>
#include <math.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define UP 2
#define DOWN 3
#define LEFT 4
#define RIGHT 5
#define FRONT 6
#define BACK 7

double mag (double x,double y,double z);
int close_to(double tolerance, double point, double value);

int main() {
	int t, printed, timing, falling, k = 1000, last_print;
	double time_start, time_stop, ax, ay, az, msec;
	int b[6];
	
	printf("Benjamin Muslic\n");
	printf("muslicb@iastate.edu");
	printed = FALSE, falling == FALSE;
	last_print = 0;
	while(TRUE) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b[0], &b[1], &b[2], &b[3], &b[4], &b[5] );
		if(printed == FALSE) {
			printf("Atomic batteries to power, turbines to speed. Roger. Let's go!");
			printed = TRUE;
		}
		if(last_print == 0) {
			last_print = t;
		}
		if(close_to(3, last_print+k, t) == TRUE) {
			if(falling == FALSE) {	
				printf(".");
			} else {
				printf("!");
			}
			last_print = t;
		}
		
		if((close_to(0.1, 2, ax) == TRUE || close_to(0.1, 2, ay) == TRUE || close_to(0.1, 2, az) == TRUE) && close_to(0.001, 1, mag(ax, ay, az)) == FALSE) {
			if(falling == FALSE) {
				printf("\n Holy levitation Batman! we are flying! ");
				time_start = t;
			}
			
			falling = TRUE;
		} else {
			if(falling == TRUE) {
			double diff;
			diff = (-1)*(time_stop - time_start)/1000.0;
			printf("\n Holy Hang Time Batman! We flew %lf meters in %lf seconds.", (double)(0.0 + (mag(ax,ay,az)*diff) + (1.0/2.0) * (-9.8) * diff * diff), diff);
			break;
			}
			time_stop = t;
			falling = FALSE;
		}
		
		
		
		fflush(stdout);
	}
	return 0;
}



double mag(double x,double y,double z) {
	return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}

int close_to(double tolerance, double point, double value) {
	int close;
	
	if(value > point - tolerance && value < point + tolerance) {
		close = TRUE;
	} else {
		close = FALSE;
	}
	
	return close;
}
	