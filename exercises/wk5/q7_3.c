//This program uses a function called CharacterScan to read a char from the user
//The function must take an int pointer as a parameter
//The program should print the char and ascii code for each character the user enters
//The program should only exit whe nthe user enters escape

#include <stdio.h>

char CharacterScan(int*);

int main(void){

  char exit;
  while(1){
    //exit = getchar();

    int aCode;
    int* iPtr;
    iPtr = &aCode;
    char c = CharacterScan(iPtr);
    //aCode = iPtr;

    if(aCode == 27){
      break;
    }
    else{
      printf("%c is ASCII code %d.\n", c, *iPtr);
    }
  }
  return 0;
}

char CharacterScan(int* iPtr){
  char c;
  printf("Enter a character: ");
  scanf(" %c", &c);
  *iPtr = (int) c;
  return c;
}
