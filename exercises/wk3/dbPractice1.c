// The factorial of an integer is the product of the number with all
// the positive integers below it.

// For example: Factorial of 5 = 5 * 4 * 3 * 2 * 1 = 120

// Number of errors/bugs = 7
#include<stdio.h>

int factorial(int);

int main(void) {
	int n,fact;
	printf("Debugging Practice 1 - Quiz 3, Q3\n\n");
	printf("Please enter the number whose factorial you wish to find: ");
	// changed %f to %i and added & to n so it can assign an integer not float
	scanf(" %i", &n);
	fact = factorial(n);
	// changed c to d in order to print out an integer
	printf("\nThe factorial of %d is %d\n", n, fact);
}

// changed float to int to match skeleton
int factorial(int number) {
  if(number <=1){
    return 1;
  // changed this to 1 not number-1
  }
  return number * factorial(number-1);
}


 

