/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */
	int buttons(int tri, int circ, int x, int squ);


int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t, tri, circ, x, squ;
    double  ax, ay, az;     


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
		scanf("%d,%d,%d,%d", &tri, &circ, &x, &squ);
		printf("%d\n", buttons(tri, circ, x, squ));
		fflush(stdout);
		
    }

return 0;
}

/* Put your functions here */
int buttons(int tri, int circ, int x, int squ) {
	
	
	
	return tri + circ + x + squ;
	
}