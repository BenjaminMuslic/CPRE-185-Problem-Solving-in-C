/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name: Benjamin Muslic
- 	Section: 7
-	NetID: muslicb
-	Date: 9/7/2021
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-							 Implementation
-----------------------------------------------------------------------------*/
int main()
{
    int integerResult;
    double decimalResult;

    integerResult = 77 / 5;
    printf("The value of 77/5 is %d, using integer math\n", integerResult); // The %lf was changed to %d

    integerResult = 2 + 3;
    printf("The value of 2+3 is %d\n", integerResult); //The line was missing integerResult

    decimalResult = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf\n", decimalResult); //The %d was replaced with %lf
	

    return 0;
}

