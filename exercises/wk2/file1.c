/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*  Total number of bugs : 16
*/

#include <stdio.h>

int main(){
  int limit = 10,  even_product = 1, odd_product = 1, sum = 0, i;
  int c;
  printf("The value of limit is %d\n", limit);
  for(i = 1; i <= limit; ++i){
    if(i% 2 == 0){
      even_product = i*even_product;
    }   
    if(i% 2 == 1){
      odd_product = i*odd_product;
    }
  }
  sum = even_product + odd_product;
  printf("The Sum = %d\n", sum);
  for(c = 'Z'; c >= 'A';c= c-2){
     // printf("here\n");
    printf("%c ", c);
    }
  printf("\nTotal number of bugs: 16\n");
    return 0;
}
