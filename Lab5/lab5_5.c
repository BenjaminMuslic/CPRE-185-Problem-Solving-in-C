/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <time.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/
#define FALSE 0
#define TRUE 1
#define UP 2
#define DOWN 3
#define LEFT 4
#define RIGHT 5
#define FRONT 6
#define BACK 7



/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
int closeto(double tol, double point, double val);
double mag(double ax, double ay, double az);

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
	int t, printed, timing, falling, last;
	double tStart, tStop, ax, ay, az;
	
	printf("Benjamin Muslic\n");
	
	printed = FALSE;
	falling = FALSE;
	last = 0;
	printf("Atomic batteries to power, turbines to speed. Roger. Let's go!");
	scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az );
	
	while(closeto(0.1, 1, mag(ax, ay, az))) {
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
		if(last == 20) {
			printf(".");
	
			last = 0;
		}
		last++;
	fflush(stdout);
	}
	
	tStart = t;
	last = 0;
	int preT = t;
	double dist =0;
	double preVel = 0;
	printf("\n Holy levitation Batman! we are flying! ");
	
	while( mag(ax, ay, az)<2.5) {
	scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
	double acc = 9.8*(1-mag(ax,ay,az));
	double deltaT = (t - preT)/1000.0;
	preT = t;
	
	double vel = preVel + acc*deltaT;
	preVel = vel;
	
	dist = dist+ vel*deltaT;
	if(last == 20) {
			printf("!");
			fflush(stdout);
			last = 0;
		}
		last++;
	fflush(stdout); 
	}
	t = t-tStart;
	double d = .5*(9.8)* pow((t/1000.0),2); 
	printf("\n Holy Hang Time Batman! We flew %lf meters in %lf seconds.",d,t/1000.0);
	printf("\n Wind resistance is %lf meters which is %lf %% less" ,dist, 100 - (dist/d)*100);
	

	
return 0;
}
	

/* Put your functions here */
double mag(double ax, double ay, double az) { 
	double x2 = pow(ax, 2);
	double y2 = pow(ay, 2);
	double z2 = pow(az, 2);
		
	return sqrt(x2 + y2 + z2);
		
	
	}
	
int closeto(double tol, double point, double val) {
	int close;
	
	if((val > point - tol) && (val < point + tol)) {
		close = TRUE;
	}
	else {
		close = FALSE;
	}
	return close;
}