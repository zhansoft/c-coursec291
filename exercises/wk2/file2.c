// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 812, exchange = 424
Output : 
812-424-0001
812-424-0002
812-424-0003
.
.
812-424-9998
812-424-9999
Number of bugs: 24
 */

#include<stdio.h>
  
int main(){
   int digit1, digit2, digit3, digit4;
   char areaCode[3], exchange[3];
   printf( "Hello, I am a telemarketing calling making program.\n");
   printf("Enter a three-digit area code: ");
   scanf("%3s", exchange);
   printf("Enter a three-digit exchange to call ");
   scanf("%3s", areaCode);
   for(digit1 = 0; digit1 < 10; ++digit1){
     for(digit2 = 0; digit2 <=9; ++digit2){
       for(digit3 = 0; digit3 <= 9; ++digit3){
	 for(digit4 = 0; digit4 < 10; ++digit4){
                printf( "Dialing (%3s)-%3s-", areaCode , exchange);
                printf( "%d%d%d%d\n", digit1,digit2,digit3,digit4);
		printf("I am calling to tell you to buy a subscription to Dogs Monthly!\n");
	       }
       }
     }
   }      
   printf("Number of bugs: 24");

   return 0;
}
