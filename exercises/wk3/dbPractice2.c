// Program to read integers into a 3X3 matrix and display them
// Number of errors/bugs = 12


#include <stdio.h>
void display(int Matrix[3][3],int size);

int main(void) {
	int size=3;
	// changed it to be size since the parameter is 3 and it would've been 2
	int Matrix[size][size];
	printf("Enter 9 elements of the matrix:\n");
	// added a semicolon after i and instantiated j there
	int i, j;
	// added a semicolon instead of comma
	for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++){
	// changed %f to %i
        scanf("%i", &Matrix[i][j]);
      }
    }
	display(Matrix,3);
	return 0;
}
// changed paramter types to int and int
void display(int Matrix[3][3], int size) {
  // instantiated i and j here
  int i, j;
  for (i = 0; i < size; i++) {
    // changed to j = 0; j < size; j++
    for (j = 0; j < size; j++) 
    {
      // changed the matrix index 
       printf("%d ", Matrix[i][j]);
     }
    printf("\n");
  }
  // added a return
  return;
    
}
