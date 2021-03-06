/*
Name: Sophia Zhang
Date: October 14th, 2020
Assignment 6
*/

struct patient{
  char lastName[15];
  char firstName[15];
  char gender;
  int* isCovidPositive;
};

typedef struct patient patient;

#include <stdio.h>
#include <string.h>
int main(void){
  
  FILE *fPtr, *data; //pointer for the new file
  fPtr = fopen("nameage.dat", "w");
  data = fopen("data.txt", "r");

  // 20 records using an array
  patient record[20] = {
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
    {"", "", '\0', NULL},
  };
  int i = 0;

  // reads in the data from anothe file and will write them to 0, 2, 4 etc in the records!
  for(i = 0; i < 20; i++){
    if(i % 2 == 0){
      fscanf(data, "%s %s %c %d", record[i].lastName, record[i].firstName, &record[i].gender, &record[i].isCovidPositive);
    }
  }
  fwrite(record, sizeof(record), 1, fPtr);

  patient *rPtr = record;
  char search = '\0';
  char ln[15];
  char fn[15];
  char g;
  int* covid;
  int index;
  int count = 0;
  int dup[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  while(search != 'N' && search != 'n'){
    printf("Would you like to search today (Y/y/N/n)?: \n");
    scanf("\n%c", &search);
    if(search == 'Y' || search == 'y'){
      printf("\nGreat! Enter the last name: ");
      scanf("%s", &ln);
      printf("\nNow enter the first name: ");
      scanf("%s", &fn);
      printf("\nNow enter the gender:\n");
      scanf("\n%c", &g);
      printf("\nNow enter their covid status (0, 1): ");
      scanf("%d", &covid);
      // searching part
      
      index = -1;
      count = 0;
      i = 0;
      // searching
      for(i = 0; i < 20; i++){
	if(strcmp(rPtr[i].lastName, ln) == 0 && strcmp(rPtr[i].firstName, fn) == 0 && rPtr[i].gender == g && rPtr[i].isCovidPositive == covid){
	  if(count == 0){
	    // first instance
	    index = i;
	  }
	  count++;
	  dup[i] = 1;
	}
      }
      
      //eradicating duplicates
      if(count > 1){
	fclose(fPtr);
	fPtr = fopen("nameage.dat", "w");
	for(i = 0; i < 20; i++){
	  if(dup[i] == 1 && i != index){
	    strcpy(rPtr[i].lastName, "");
	    strcpy(rPtr[i].firstName, "");
	    rPtr[i].gender = '\0';
	    rPtr[i].isCovidPositive = NULL;
	    printf("\nErased at index %d", i);
	  }
	  // fwrite(rPtr[i].lastName, sizeof(rPtr[i].lastName), 1, fPtr);
	  //	  fwrite(rPtr[i].firstName, sizeof(rPtr[i].firstName), 1, fPtr);
	  fprintf(fPtr, "%s ", rPtr[i].lastName);
	  fprintf(fPtr, "%s ", rPtr[i].firstName);
	  fputc(rPtr[i].gender, fPtr);
	  fprintf(fPtr, "%d", rPtr[i].isCovidPositive);
	}
      }
      // if found
      if(index != -1){
	printf("\nRecord found: ");
	printf("\nLast Name: %s", rPtr[index].lastName);
	printf("\nFirst Name: %s", rPtr[index].firstName);
	printf("\nGender: %c", rPtr[index].gender);
	printf("\nCovid: %d\n", rPtr[index].isCovidPositive);
      }else{
	printf("\nNot found!\n");
      }
    }
    index = -1;
    count = 0;
  }

  fclose(data);
  fclose(fPtr);
  return 0;
}

