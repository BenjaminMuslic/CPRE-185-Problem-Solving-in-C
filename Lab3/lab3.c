/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */

double mag(double a, double b, double c);
	int minutes(int time);
	int seconds(int time);
	int millis(int time);


int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double  ax, ay, az;     


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az); 

/* CODE SECTION 0 */
	//	double t2;
	//	t2=t / 1000.0;

    //    printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", t2, ax, ay, az);

/* CODE SECTION 1 */
 //printf("At %d ms, the acceleration's magnitude was: %lf\n", 
	//t, mag(ax, ay, az));  
            
/* CODE SECTION 2 */
       printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
       minutes(t), seconds(t), millis(t), mag(ax,ay,az)); 

    }

return 0;
}

/* Put your functions here */

double mag(double a, double b, double c) { 
		double a2 = pow(a, 2);
		double b2 = pow(b, 2);
		double c2 = pow(c, 2);
		
		return sqrt(a2 + b2 + c2);
		
	
	}


	int minutes(int time) {
		return time / 60000;
	}

	int seconds(int time) {
		int msLeft = time % 60000;
		return msLeft / 1000;
	}
	
	int millis(int time) {
		int msLeft = time % 60000;
		return time % 1000;
	}
