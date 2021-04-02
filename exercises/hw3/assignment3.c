/* Sophia Zhang
Assignment 3: Airline Booking
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function headers
char get_letter(int seat_num);
int select_seat(char section, int plane[][7]);
int is_assigned(int seat, int plane[][7]);
int section_full(char section, int plane[][7]);
void print_chart(int plane[][7]);
void print_boarding_pass(int seat, char log[105][60]);
void print_manifest(char log[105][60], int assigned_seats[], int assigned);

// main method
int main(void){
  // instantiating variables
  char input, section, seat;
  int plane[15][7];
  int a,b;
  for(a = 0; a < 15; a++){
    for (b = 0; b <7; b++){
      plane[a][b] = 0; // makes every seat in plane 0 meaning not taken
    }
  }
  char log[105][60]; // array of strings to hold the names/acts as a log for a person sitting in seat a+1
  int assigned_seats[105]; // array to hold the seat numbers
  int num_assigned_seats = 0; // int to hold the num of seats assigned already
  int reserve_num, seat_num;
 
  // begins Simulation
  do{
    // Asks user how many seats they want to reserve
    printf("\nHow many seats would you like to reserve today?: ");
    scanf(" %d", &reserve_num);
    // Ensures enough seating
    while(reserve_num > (105-num_assigned_seats)){
	printf("\nWe just checked. There are only %d seats left.  How many would you like to reserve today: ", 105 - num_assigned_seats);
	scanf(" %d", &reserve_num);
      }
    // Selection for x number of reserving seats (the correct amount)
      for(a = 0; a < reserve_num; a++){
	// Section
	printf("\nEnter 'F' for First Class, 'B' for Business Class, or 'E' for Economy Class: \n");
	scanf(" %c", &section);
	// If Section is full, ask for another option.
	if(section_full(section, plane)){
	  // first class
	  if(section == 'F' && !section_full('B', plane) && !section_full('E', plane)){
	      printf("\nThere are no available seats for First class. Would you like a seat in Business instead?: (Y/N)");
	      scanf(" %c", &input);
	      if (input == 'Y'){
		section = 'B';
		printf("\nYou are now in Business class.");
	      }
	      else{
		section = 'E';
		printf("\nThere were no seats left in Business class.  We have placed you in Economy instead.");
	      }
	    }
	    else if(section == 'F' && !section_full('B', plane)){
	      printf("\nWe only have available seats in our business class.");
	      section = 'B';
	    }
	    else if(section == 'F'){
	      printf("\nWe only have available seats in our economy class.");
	      section = 'E';
	    }
	    // business class
	    else if(section == 'B' && !section_full('F', plane) && !section_full('E', plane)){
		printf("\nThere are no available seats for business class. Would you like a seat in Economy instead?: (Y/N)");
		scanf(" %c", &input);
		if(input == 'Y'){
		  section = 'E';
		  printf("\nYou are now in Economy class.");
		}
		else{
		  section = 'F';
		  printf("\nYou have been placed in First class instead.");
		}
	      }
	      else if(section == 'B' && !section_full('F', plane)){
		printf("\nThere are only available seats in Economy.");
		section = 'E';
	      }
	      else if(section == 'B'){
		printf("\nThere are only available seats in First Class.");
		section = 'F';
	      }
	      // Economy class
	      else if(!section_full('F', plane) && !section_full('B', plane)){
		printf("\nOur apologies.  Economy is full. There are available seats in Business class. Would you like a seat in Business instead?: (Y/N)");
		scanf("\n %c", &input);
		if(input == 'Y'){
		  section = 'B';
		  printf("\nYou have been placed in Business class.");
		}
		else{
		  section = 'F';
		  printf("\nYou have been placed in First class instead.");
		}
	      }
	      else if(!section_full('F', plane)){
		section = 'F';
		printf("There is only availability in first class.");
	      }
	      else if(!section_full('B', plane)){
		printf("\nYou have been placed in business due to availability.");
		section = 'B';
	      }
	      if(section != 'B' && section != 'F'){
		section = 'E';
	      }
	      // priority
	      if(section == 'E' && !section_full('P', plane)){
		printf("\nWould you like a priority economy seat?: (Y/N)");
		scanf("\n %c", &input);
		if(input == 'Y' || input == 'y'){
		  section = 'P';
		}
	      }
	}
	      // Selecting a seat
	 do{
	     seat_num = select_seat(section, plane);
	     seat = get_letter(seat_num);
	     printf("\nWe have selected seat %c%d", seat, seat_num);
	     if (seat == 'A' || seat == 'I'){
	       printf("\nThis is a window seat.");
	     }
	     else if(seat == 'B' || seat == 'D' || seat == 'F' || seat == 'H'){
	       printf("\nThis is an aisle seat.");
	     }
	     printf("\nDo you want this seat?: (Y/N)");
	     scanf("\n %c", &input);
	    }
	  while(input != 'Y');
	      // Upgrades/Downgrads
	 printf("\nYou are currently in section %c. Would you like to upgrade or downgrade your seat if seats are available?: (Y/N)", section);
	      scanf("\n %c", &input);
	      if (input == 'Y'){
		printf("\nWhat section would you like to change to?: (F/B/E)");
		scanf("\n%c", &input);
		// Selects new seat in first if not full
		if(input == 'F' && !section_full('F', plane)){
		  section = 'F';
		  do{
		    seat_num = select_seat(section, plane);
		    seat = get_letter(seat_num);
		    printf("\nWe have selected seat %c%d", seat, seat_num);
		    if (seat == 'A' || seat == 'I'){
		      printf("\nThis is a window seat.");
		    }
		    else if (seat == 'B' || seat == 'D' || seat== 'F' || seat == 'H'){
		      printf("\nThis is an aisle seat.");
		    }
		    printf("\nDo you want this seat?: (Y/N"); 
		    scanf("\n %c", &input);
		  }
		  while (input != 'Y');
		  printf("\nFinal seat selection: First Class seat %c%d\n", seat, seat_num);
		}
		// Selects new seat in Business if not full
		else if(input == 'B' && !section_full('B', plane)){
		  section = 'B';
		  do{
		    seat_num = select_seat(section, plane);
		    seat = get_letter(seat_num);
		    printf("\nWe have selected seat %c%d", seat, seat_num);
		    if (seat == 'A' || seat == 'I'){
		      printf("\nThis is a window seat");
		    }
		    else if (seat == 'B' || seat == 'D' || seat== 'F' || seat == 'H'){
		      printf("\nThis is an aisle seat");
		    }
		    printf("\nDo you want this seat?: (Y/N");
		    scanf("\n %c", &input);
		  }
		  while(input != 'Y');
       		  printf("\nFinal seat selection: Business  Class seat %c%d\n", seat, seat_num);
		}
		// Selects new seta in Economy (not priority) if not full
		else if(input == 'E' && !section_full('E', plane)){
		  section = 'E';
		  do{
		    seat_num = select_seat(section, plane);
		    seat = get_letter(seat_num);
		    printf("\nWe have selected seat %c%d", seat, seat_num);
		    if (seat == 'A' || seat == 'I'){
		      printf("\nThis is a window seat");
		    }
		    else if (seat == 'B' || seat == 'D' || seat== 'F' || seat == 'H'){
		      printf("\n This is an aisle seat");
		    }
		    printf("\nDo you want this seat?: (Y/N)");
		    scanf("\n %c", &input);
		  }
		  while (input != 'Y');
		  printf("\nFinal seat selection: Economy seat %c%d\n", seat, seat_num);
		}
		// Selected section was full ope
		else{
		  printf("\nUnfortunately there are not any seats left for that section.\nFinal seat selection: %c%d", seat, seat_num);
		}
	      }
	      // Confirmation of seat choice without change in section
	      else{
		printf("\nYou are currently in seat %c%d. Would you like to change this seat?: (Y/N)", seat, seat_num);
		scanf("\n %c", &input);
		// Required statement
		if (input != 'Y'){
		  printf("\nThe flight will depart in three hours\n");
		}
		//Selects final seat
		else{
		  do{
		    seat_num = select_seat(section, plane);
		    seat = get_letter(seat_num);
		    printf("\nWe have selected seat %c%d", seat, seat_num);
		    if (seat == 'A' || seat == 'I'){
		      printf("\nThis is a window seat");
		    }
		    else if (seat == 'B' || seat == 'D' || seat== 'F' || seat == 'H'){
		      printf("\nThis is an aisle seat");
		    }
		    printf("\nDo you want this seat?: (Y/N)"); 
		    scanf("\n %c", &input);
		  }
		  while (input != 'Y');
		  printf("\nFinal seat selection: %c%d\n", seat, seat_num);
		}
	      }
	      
	      // Assigning the seat to the proper array position
	      int row = (seat_num - 1) % 7;
	      int col = (seat_num - 1) % 7;
	      plane[row][col] = 1;
	      assigned_seats[num_assigned_seats] = seat_num;
	      printf("\nWhat is the full passenger name? (Only 60 chars)");
	      scanf("\n %[^\n]%*c", &log[seat_num-1]);
	      num_assigned_seats += 1;
	    }
	    
	    // Display menu of post-selection
	    printf("\nPlease type 'C' to display the seating chart.\nPlease type 'M' to display the passenger manifest.\nHit any other letter to see the boarding pass of a seat: ");
	    scanf("\n %c", &input);
	    if (input == 'C'){
	      print_chart(plane);
	    }
	    else if( input == 'M'){
	      print_manifest(log, assigned_seats, num_assigned_seats);
	    }
	    // Gets the seat number for said boarding pass
	    else{
	      printf("\nPlease enter the seat number for the boarding pass you'd like to see.");
	      char seat_input[3];
	      int boarding_seat;
	      scanf("\n %s", &seat_input);
	      boarding_seat = atoi(seat_input);
	      // ensures the seat is assigned
	      while(!is_assigned(boarding_seat, plane)){
		printf("\nThis seat is unassigned.  There is no boarding pass available.  Try again.");
		printf("\nEnter another seat: ");
		scanf("\n %s", &seat_input);
		boarding_seat = atoi(seat_input);
	      }
	      print_boarding_pass(boarding_seat, log);
	    }
	      // other booking?
	    printf("\nWould you like to book another reservation?: \n");
	    scanf(" %c",&input);
  }
  while(num_assigned_seats < 105 && input == 'Y');
  return 0;
}

char get_letter(int seat_num){
  int col = (seat_num - 1) % 7;
  if (col == 0){
    return 'A';
  }
  else if (col == 1){
    return 'B';
  }
  else if(col == 2){
    return 'D';
  }
  else if(col == 3){
    return 'E';
  }
  else if(col == 4){
    return 'F';
  }
  else if(col == 5){
    return 'H';
  }
  else{
    return 'I';
  }
}

int select_seat(char section, int plane[][7]){
  int random = 0;
  if(section == 'F'){
    do{
      random = (rand() % 21) + 1;
    }
    while(is_assigned(random, plane));
    return random;
  }
  else if(section == 'B'){
    do{
      random = (rand() % 28) + 22;
    }
    while (is_assigned(random, plane));
    return random;
  }
  else if(section == 'P'){
    do{
      random = (rand() % 7) + 50;
    }
    while(is_assigned(random, plane));
    return random;
  }
  else if(section == 'E'){
    do{
      random = (rand() % 49) + 57;
    }
    while (is_assigned(random, plane));
    return random;
  }
}

int is_assigned(int seat, int plane[][7]){
  int row = (seat - 1) / 7;
  int col = (seat - 1) % 7;
  return plane[row][col];
}

int section_full(char section, int plane[][7]){
  int a;
  if (section == 'F'){
    for(a = 1; a <= 21; a++){
      if(!is_assigned(a, plane)){
	return 0;
      }
    }
  }
  else if(section == 'B'){
    for(a = 22; a <= 49; a++){
      if(!is_assigned(a, plane)){
	return 0;
      }
    }
  } 
  else if(section == 'P'){
    for(a = 1; a <= 7; a++){
      if (!is_assigned(a + 49, plane)){
	return 0;
      }
    }
  }
  else{
    for(a = 50; a <= 105; a++){
      if(!is_assigned(a, plane)){
	return 0;
      }
    }
  }
  return 1;
}

void print_chart(int plane[][7]){
  printf("\n  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15\n");
  int r, c;
  for (c = 0; c<7; c++){
    printf("%c ", get_letter(c+1));
    for (r = 0; r < 15; r++){
      if(!(r == 3 || r == 7))
	printf(" %d ", plane[r][c]);
      else
	printf("| %d ", plane[r][c]);
    }
    printf("\n");
    if (c == 1 || c == 4)
      printf("\n");
  }
  return;
}

void print_boarding_pass(int seat, char log[105][60]){
  printf("\nName: %s", log[seat-1]); 
  printf("\nSeat: %c%d", get_letter(seat), seat); 
  if (seat >= 57)
    printf("\nClass: Economy");
  else if (seat >= 50)
    printf("\nClass: Priority Economy");
  else if (seat >= 22)
    printf("\nClass: Business Class");
  else
    printf("\nClass: First Class");
  return;
}

void print_manifest(char log[105][60], int assigned_seats[], int assigned){
  int a;
  char name[] = "Passenger Full Name";
  printf("\n%-60s\tSeat\n", name);
  for (a = 0; a<assigned; a++){
    int temp = assigned_seats[a];
    printf("%-60s\t%c%d \n", log[temp-1], get_letter(temp), temp);
  }
  return;
}
