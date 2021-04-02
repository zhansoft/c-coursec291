/* Instructions:
 *
 *
 1. Write a program to assign a grade to Student. 
	Get the number of assignmnets from user.
  Get the students score out of how many points for each assignmnet.
	Calculate percentage and return the grade associated with a range of marks.
 2. The overall score range and the associated grades are as follows:
     a. [97-100] = A+
     b. [90-97] = A
     c. [80-90] = B
     d. [70-80] = C
     e. less than 70 is a failing grade and should be given an F
     e. greater than 100 or less than 0 is invalid and your code should print "Invalid"
 3. Use the skeleton code provided below to create a new function "printGrade" to assign a grade based on the score ranges.
 4. Use print statements in your function to display the grade. For example, if the input marks is 77, the output should read:
        "Your grade is : C"
 5. Please adhere to standard C syntax conventions and use comments to explain your code. Failure to do so will result in a penalty.
 *
 *
 * */
#include <stdio.h>
void printGrade(int score){
	//print the students grade based on their score in the class
  if(score <= 100 && score >= 97){ // an A+ is 97-100
    printf("Your grade is: A+"); // prints A+
  }else if(score < 97 && score >= 90){ // an A is 90-96
    printf("Your grade is: A"); // prints A
  }else if (score < 90 && score >= 80){ // a B is 80-89
    printf("Your grade is: B"); // prints B
  }else if (score < 80 && score >= 70){ // a C is 70-79
    printf("Your grade is: C"); // prints C
  }else if (score < 70 && score >= 0){ // a F is 69-0
    printf("Your grade is: F"); // prints F
  }else if (score > 100 || score <0){ // a score cannot be higher than 100 or lower than 0
    printf("Invalid"); // prints that it's invalid
  }
  return; //end of void function
}
int main(void){
	char ch;
	float score;
	int assignments;
	do {
		printf("How many assignmnets did you have ? ");
		scanf("\n%i", &assignments); // this will take in the number of assignments
    //get the number of assignmnets from the student
		printf("Enter your score for all assignments : \n" );
    //get the student's score and the max score for each assignment
		int count; // for the for loop
		float ascore,  maxscore; // to hold the assignments score & maxscore
		// this will provide a simple format for the entering of scores
		printf("Please enter in the format of 'score maxpoints':\n");
		for(count = 1; count <= assignments; count++){ // a for loop to collect scores
		  printf("Assignment %i: ", count); // Layout
		  scanf("%f %f", &ascore, &maxscore); // Assignments to assignment score and maxscore which will then be added to score
                  score += (ascore/maxscore); // it'll provide a float grade like 8/10 = 0.8000
}
    //calculate the student's percentage in the class using the information you've gathered.
		int percent;
                score = score/assignments; // this computes the total by taking the average
                percent = (int) (score * 100); // (int) float will turn the float into an int & 0.8 * 100 = 80%
    
		printGrade(percent);
                score = 0; //this resets the score for next time
		printf(" \n Do you want to continue? (Y/N) ");
		scanf(" %c",&ch);
	} while(ch == 'y'|| ch == 'Y');
}
