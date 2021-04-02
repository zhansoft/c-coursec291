/*
 * Basic C program to print out how many days you have been alive! 
 * Author: Sophia Zhang
*/

#include <stdio.h>
#include <unistd.h>

int main(void) {
 /* This is from Assignment 0.  I'm still a little confused as to whether
 I should modify this or not??
  int daysAlive = 0;
  printf("Here is the number of days you have been alive: %d\n",daysAlive);
  int actualDaysAlive = 7026;
  printf("Here is the number of days you have ACTUALLY  been alive: %d\n",actualDaysAlive);
  return(0);
*/
  printf("\"*****\"{Welcome to Fall2020 - 'Corona-affected' 8-Week session @ IU}, | Every week, please start early and ask for help! Also, let's try to stay safe!//\"*****\"");
  printf("\n");
  
  int startval = 100;
  while(1){
    printf("%03d ", startval);
    startval = startval - 1;
    int count;
    for(count = 0; count < 5; count = count + 1){
      fflush(stdout);
      sleep(1);
      printf(".");
    }
    printf("\n");
  }
  return(0);
}


