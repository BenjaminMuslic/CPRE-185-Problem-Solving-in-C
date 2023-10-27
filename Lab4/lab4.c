/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define UP 2
#define DOWN 3
#define LEFT 4
#define RIGHT 5
#define FRONT 6
#define BACK 7

int numButtons(int b[6]);
double mag(double x,double y,double z);
int close_to(double tolerance, double point, double value);

int main(void) {
	/* b2 is the "UP" button */
	int t, b1, b2, b3, b4, b5, s, printed;
	double ax, ay, az, ox, oy, oz; 	

	b2 = 0;
	printed = FALSE;
	ox = ax, oy = ay, oz = az;
	while (b2 < 1) {
		if(printed == FALSE) {
			ox = ax, oy = ay, oz = az;
		}
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );	

		
		if(close_to(0.01, 1, az) == TRUE) {
			if(printed != UP && close_to(0.01, 1, mag(ax, ay, az))){
				printf("UPSY DAISY!\n");
				printed=UP;
			}
			ox = ax, oy = ay, oz = az;
		} else if (close_to(0.01, -1, az) == TRUE) {
			if(printed != DOWN && close_to(0.01, 1, mag(ax, ay, az)) ){
				printf("DOWNSY DOWNSY!\n");
				printed=DOWN;
			}
			ox = ax, oy = ay, oz = az;
		} else if (close_to(0.01, 1, ax) == TRUE) {
			if(printed != LEFT && close_to(0.01, 1, mag(ax, ay, az))) {
				printf("LEFTY LOOSEY!\n");
				printed=LEFT;
			}
			ox = ax, oy = ay, oz = az;
		} else if (close_to(0.01, -1, ax) == TRUE) {
			if(printed != RIGHT && close_to(0.01, 1, mag(ax, ay, az))){
				printf("RIGHTY TIGHTY!\n");
				printed=RIGHT;
			}
			ox = ax, oy = ay, oz = az;
		} else if (close_to(0.01, 1, ay) == TRUE) {
			if(printed != FRONT && close_to(0.01, 1, mag(ax, ay, az))) {
				printf("FRONTWARD!\n");
				printed=FRONT;
			}
			ox = ax, oy = ay, oz = az;
			
		} else if (close_to(0.01, -1, ay) == TRUE) {
			if(printed != BACK && close_to(0.01, 1, mag(ax, ay, az)))  {
				printf("BACKWARD!\n");
				printed=BACK;
			}
			ox = ax, oy = ay, oz = az;
		}
		

		
		
	}


    return 0;
}
int numButtons(int b[6]) {
	int cnt = 0, i;
	
	/* we skip b[5] which is the slider, which is read for giggles, but not "pressed" */
	for(i = 0; i < 5; i+=1) {
		if(b[i] > 0) {
			cnt+=1;
		}
	}
	
	return cnt;
}

double mag(double x,double y,double z) {
	return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}

int minutes(int t) {
	return t / 1000 / 60;
}

int seconds(int t) {
	return t / 1000;
}

int millis(int t) {
	return t;
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
