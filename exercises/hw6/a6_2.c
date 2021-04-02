/*
Name: Sophia Zhang
Date: October 14, 2020
Assignment 6 Part 2
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

  // instantiating vars
  FILE *fPtr;
  char txtfile[1000];
  char option = 'c';
  int space = 0, hasVowel = 0, wasNumber = 0, i;
  char word[100];
  int numCount = 0, numDigitCount = 0, charCount = 0, vowelCount = 0, sentenceCount = 0, vc, wc, nc;
 
  printf("\nWhat txt file would you like to read?: \n");
  scanf("\n%s", txtfile);
  //  printf("\n%s", txtfile);
  fPtr = fopen(txtfile, "r");
  if( fPtr == NULL ){
    puts("Nope.  Doesn't exist");
  }
  else{
    
    while(1){
      int status = fgetc(fPtr);
      if(status < 0){
	break;
      }
      //digit
      if(status >= '0' && status <= '9'){
	numDigitCount++;
	wasNumber = 1;
      }

      //char
      if( (status >= 'a' && status <= 'z') || (status >= 'A' && status <= 'Z')){
	if(status == 'a' || status == 'A' || status == 'i' || status == 'I' || status == 'o' || status == 'O' || status ==  'u' || status == 'U' || status == 'e' || status == 'E'){
	  hasVowel = 1;
	}
	charCount++;
      }

      //sentence
      if(status == '.' || status == '?' || status == '!'){
	sentenceCount++;
      }

      // word w/ at least one vowel
      if(status == ' ' || status == '.' || status == ',' || status == '!' || status == '?'){
	if(hasVowel == 1){
	  vowelCount++;
	}
	if(wasNumber == 1){
	  numCount++;
	}
	hasVowel = 0;
	wasNumber = 0;
      }

    }
    
    while(option != 'q' && option != 'Q'){
      printf("\nHere are your options:");
      printf("\nType a/A to display the number of numbers in the file.");
      printf("\nType b/B to display the number of characters and numeric digits in the file.");
      printf("\nType c/C to display the number of words which include at least 1 vowel in the file.");
      printf("\nType d/D to display the number of sentences in a file.");
      printf("\nType e/E to display analysis of the file.");
      printf("\nType q/Q to quit.");
      printf("\nYour option:\n");
      scanf("\n%c", &option);
      printf("\nOption: %c\n", option);

      // Displaying all the number of numbers in the files.
      if(option == 'a' || option == 'A'){	
	printf("\nNumber of numbers: %d\n", numCount);
      }

      // Displays number of characters and numeric digits in the files
      if(option == 'b' || option == 'B'){
	printf("\nNumber of chars: %d",charCount);
	printf("\nNumber of numeric digits: %d\n", numDigitCount);
      }

      // Display number of words which include at least one vowel in a file.
      if(option == 'c' || option == 'C'){
	printf("\nNumber of words with vowels: %d\n", vowelCount);
      }

      // Displays sentence
      if(option == 'd' || option == 'D'){
	printf("\nNumber of sentences: %d\n", sentenceCount);
      }

      if(option == 'e' || option == 'E'){
	FILE* aPtr;
	aPtr = fopen("analysis.txt", "w");
	fprintf(aPtr, "Number: %d\nChars: %d\nNumeric digits: %d\nWords w/ 1 vowel:%d\nSentence count: %d", numCount, charCount, numDigitCount, vowelCount, sentenceCount);
	fclose(aPtr);
	aPtr = fopen("analysis.txt", "r");
	while(1){
	  int phrase = fscanf(aPtr, "%s", word);
	  if(phrase == -1){
	    break;
	  }
	  else if(phrase != 1){
	    fclose(aPtr);
	    aPtr = NULL;
	    return -1;
	  }
	  printf("%s ", word);
	}
	fclose(aPtr);
      }
      
      if(option == 'q' || option == 'Q'){
	break;
      }
    }
    fclose(fPtr);
  }
  return 0;
}
