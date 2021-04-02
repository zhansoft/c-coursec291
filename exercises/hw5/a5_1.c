/*
Name: Sophia Zhang
Assignment 5
Date: 09/28/20
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct patientinformation{
  char patient_name[20];
  char* abbreviated_name;
  unsigned int age;
  struct{
    char phone_number[11];
    char address[60];
    char city[20];
    char state[3];
    int zipCode;
  } physical_address;
  struct{
    bool istested;
    bool istested_positive;
  } covid_test;
} healthrecord, *healthrecord_ptr;

int main(void){
  // initializing

  // del struct patientinformation healthrecord;
  // del struct patientinformation *healthrecord_ptr;

  healthrecord_ptr = &healthrecord;
  strcpy(healthrecord.patient_name, "Sophia ZHang");
  healthrecord.abbreviated_name = "SZ";
  healthrecord.age = 19;
  strcpy(healthrecord.physical_address.phone_number, "6664201234");
  strcpy(healthrecord.physical_address.address, "iu university address");
  strcpy(healthrecord.physical_address.city, "bloomington");
  strcpy(healthrecord.physical_address.state, "IN");
  healthrecord.physical_address.zipCode = 47408;
  healthrecord.covid_test.istested = true;
  healthrecord.covid_test.istested_positive = false;
  printf("hi");

  // Member patient_name of structure healthrecord
  printf("\npatient_name access: %s", healthrecord.patient_name);

  // Member patient_name of the structure pointed by healthrecord_ptr
  printf("\nhealthrecord_ptr patient_name access: %s", healthrecord_ptr -> patient_name);

  // Member abbreviated_name number of structure healthrecord
  printf("\nabbreviated_name: %s", healthrecord.abbreviated_name);

  // Member abbreviated_name of the structure pointed by healthrecord_ptr
  printf("\nabbreviated_name by ptr: %s", healthrecord_ptr -> abbreviated_name);

  /*   
     Create a new character array of appropriate size
     and assign abbreviated_name pointer to it for health record
     and use it to print abbreviated_name of the structuer pointed to by healthrecord_ptr
  */
  const int carray_size = strlen(healthrecord_ptr -> abbreviated_name);
  char ab[carray_size];
  strcpy(ab, healthrecord_ptr -> abbreviated_name);
  char* ab_ptr = ab;
  printf("\nchar array: %s", ab_ptr);

  // Member phone_number of member physical_address of structure healthrecord
  printf("\nPhone number: %s", healthrecord.physical_address.phone_number);

  // Member address of member physical_address of the structure ponited to by healthrecord_ptr
  printf("\nAddress: %s", (healthrecord_ptr -> physical_address).address);

  // Member istested of member covid_test of structure pointed to by healthrecord_ptr
  printf("\nistested: %d", (healthrecord_ptr -> covid_test).istested); 

  // Create an array 5 healthrecord and print zip codes for all patientinformatinor records
  struct patientinformation hrecordarray[5];
  int i = 0;
  for(i = 0 ; i < 5; i++){
    hrecordarray[i].physical_address.zipCode = i + i + i + i;
    printf("\nhrecordarary at %d: %d", i, hrecordarray[i].physical_address.zipCode);
  }

  // Create a new pointer to these 5 healthercord and use it to initialize istested flag for all five records to false
  struct patientinformation * hra_ptr = hrecordarray;
  for(i = 0; i < 5; i++){
    (hra_ptr -> covid_test).istested = false;
    (hra_ptr -> covid_test).istested_positive = false;
    printf("\n%d hra_ptr istested = %d", i, (hra_ptr -> covid_test).istested);
    printf("\n%d hra_ptr istested = %d", i, (hra_ptr -> covid_test).istested_positive);
    hra_ptr++;
  }

  
  return 0;
}

