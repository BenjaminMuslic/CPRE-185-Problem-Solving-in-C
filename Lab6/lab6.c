// 185 lab6.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED

printf("Benjamin Muslic");
//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
//  True when the square button is pressed
//  False Otherwise
//This function is the ONLY place scanf is allowed to be used
//POST: it modifies its arguments to return values read from the input line.
int read_line(double*g_x, double*g_y, double*g_z,int*time,int*Button_T, int*Button_X, int*Button_S,int*Button_C);


// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number, int mode);

int main()
{
	double x, y, z;                             // magnitude values of x, y, and z
	int b_Triangle, b_X, b_Square, b_Circle, t, b4press;                           
	double roll_rad, pitch_rad;                 // value of the roll measured in radians
	int scaled_value,mode=0;                // value of the roll adjusted to fit screen display
	
	
	// ./ds4rd.exe -d 054c:09cc -D DS4_USB -t -g -b | ./lab6
	

	//insert any beginning needed code here
	do
	{
		// Get line of input
	read_line(&x, &y, &z, &t, &b_Triangle, &b_X, &b_Square, &b_Circle);
		// calculate roll and pitch.  Use the buttons to set the condition for roll and pitch
	roll_rad = roll(x);
	pitch_rad = pitch(z);
		// switch between roll and pitch(up vs. down button)
	if (b_Triangle==1 && b4press==0){
		if(mode==0) mode=1;
		else if (mode==1) mode=0;
	}
	b4press=b_Triangle;
		// Scale your output value
	if (mode==0){
		scaled_value = scaleRadsForScreen(roll_rad);
	}
	if (mode==1){
		scaled_value=scaleRadsForScreen(pitch_rad);
	}
	
		// Output your graph line
	graph_line(scaled_value, mode);

		fflush(stdout);
	} while (b_Square==0);
	return 0;
}

int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C)
{
	scanf("%d,%lf,%lf,%lf,%d,%d,%d,%d", time, g_x, g_y, g_z, Button_T, Button_C, Button_X, Button_S);
	
	if (*Button_S ==1){
		return 1;
	}
	else {
		return 0;
	
	}
}
	
double roll (double x_mag){
	double result;
	
	if (x_mag > 1.0) {
		x_mag = 1;
	}
	else if (x_mag < -1.0){
		x_mag = -1;
	}
	x_mag = asin(x_mag);
}

double pitch (double y_mag){
	double result;
	
	if (y_mag > 1.0) {
		y_mag = 1;
	}
	else if (y_mag < -1.0){
		y_mag = -1;
	}
	y_mag = asin(y_mag);
}

int scaleRadsForScreen(double rad){
	rad=rad*(78.0/PI);
	return rad;
}

void print_chars(int num, char use){
	int b;
	
	for (b = 0; b < num; b++){
		printf("%c", use);
	}
}
void graph_line(int number, int mode)
{
	number *= -1;
	
	if (mode==0) 
	{
		if (number < 0)
		{
			print_chars(39 + number, ' ');
			print_chars(abs(number),'L');
		}
		if (number >= 0)
		{
			print_chars(39, ' ');
			if (number == 0)
			{
				print_chars(1, '0');
			}
			print_chars(number, 'R');
		}
		print_chars(1,10);
	}
	if (mode==1) {
		if (number < 0)
		{
			print_chars(39 + number, ' ');
			print_chars(abs(number),'F');
		}
		if (number >= 0)
		{
			print_chars(39, ' ');
			if (number == 0)
			{
				print_chars(1, '0');
			}
			print_chars(number, 'B');
		}
		print_chars(1,10);
	}
	
}
