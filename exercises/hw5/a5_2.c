/*
Name: Sophia Zhang
Assignment 5 Q2
Date: September 29, 2020
*/
// Fig. 10.3: fig10_03.c
// Card shuffling and dealing program using structures
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDS 52
#define FACES 13
// card structure definition

struct card {                                 
  const char *face; // define pointer face   
  const char *suit; // define pointer suit   
}; 

typedef struct card Card; // new type name for struct card   

// prototypes
void fillDeck(Card * const wDeck, const char * wFace[], 
	      const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);
void dealFive(const Card* const wDeck, struct card * hPtr);

// my functions
int highCard(Card * hPtr, const char *wFace[]);
int twoPair(Card * hPtr);
int threeOfKind(Card * hPtr);
int straight(Card * hPtr, const char *wFace[]);
int fullHouse(Card * hPtr, const char * wFace[]);
int royalFlush(Card * hPtr, const char *wFace[]);
void check(Card * hPtr, const char *wFace[]);



int main(void)
{ 
  Card deck[CARDS]; // define array of Cards

  // initialize array of pointers
  const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
			 "Six", "Seven", "Eight", "Nine", "Ten",
			 "Jack", "Queen", "King"};

  // initialize array of pointers
  const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

  Card hand[5];
  Card * hPtr = hand;
  srand(time(NULL)); // randomize

  fillDeck(deck, face, suit); // load the deck with Cards
  shuffle(deck); // put Cards in random order
  deal(deck); // deal all 52 Cards
  printf("\nYour hand: ");
  dealFive(deck, hPtr);
  check(hPtr, face);
  return 0;
} 

// place strings into Card structures
void fillDeck(Card * const wDeck, const char * wFace[], 
	      const char * wSuit[])
{ 
  // loop through wDeck
  size_t i = 0;
  for (i = 0; i < CARDS; ++i) { 
    wDeck[i].face = wFace[i % FACES];
    wDeck[i].suit = wSuit[i / FACES];
  } 
} 

// shuffle cards
void shuffle(Card * const wDeck)
{ 
  size_t i;
  // loop through wDeck randomly swapping Cards
  for (i = 0; i < CARDS; ++i) { 
    size_t j = rand() % CARDS;
    Card temp = wDeck[i];      
    wDeck[i] = wDeck[j];
    wDeck[j] = temp;      
  } 
} 

// deal cards
void deal(const Card * const wDeck)
{ 
  // loop through wDeck
  size_t i = 0;
  for (i = 0; i < CARDS; ++i) {
    printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit,
	   (i + 1) % 4 ? "  " : "\n");
  } 
} 

void dealFive(const Card * const wDeck, struct card * hPtr){
  size_t i = 0;
  for (i = 0; i < 5; ++i) {
    printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit,
           (i + 1) % 4 ? "  " : "\n");
    (*(hPtr + i)).face = wDeck[i].face;
    (*(hPtr + i)).suit = wDeck[i].suit;
  }   
}


/*
  Determines whether the hand has zero matches or any type of special hands.
  Returns 0 for false.
  Returns 1 for true.
*/
int highCard(Card * hPtr, const char * wFace[]){
  int bool = 1;
  if(twoPair(hPtr) == 1 || threeOfKind(hPtr) == 1 || straight(hPtr, wFace) == 1 || fullHouse(hPtr, wFace) == 1 || royalFlush(hPtr, wFace)){
    bool = 0;
  }
  return bool;
}

/*
  Determines whether there is two pairs of matching faces.
  Returns 0 for false.
  Returns 1 for true
 */
int twoPair(Card * hPtr){
  int bool = 0, i = 0, j = 0, numPair = 0, avoid = 0;
  for(i = 0; i < 5; i++){
    for(j = i+ 1; j < 5; j++){
      if( (*(hPtr + i)).face == (*(hPtr + j)).face && j!= avoid){
	numPair++;
	avoid = j;
      }
    }
  }
  if(numPair >= 2){
    bool = 1;
  }
  else{
    bool = 0;
  }
  return bool;
}

/*
  Determines whether the hand has three of the same kind.
  Returns 0 for false.
  Returns 1 for true.
*/
int threeOfKind(Card * hPtr){
  int bool = 0, sameCount, i = 0, j=0 ;
  for(i = 0; i < 3; i++){
    sameCount = 1;
    for(j = i + 1; j < 5 ; j++){
      if((*(hPtr +i)).face == (*(hPtr+j)).face){
	sameCount++;
      }
    }
    if(sameCount >= 3){
      bool = 1;
    }
  }
  return bool;
}

/*
  Determines whether the hand is in order (ascending or descending).  However, it's not the same suit.
  Returns 0 for false.
  Returns 1 for true.
*/
int straight(Card * hPtr, const char * wFace[]){
  int bool = 0, i = 0, j = 0, minValue = 13, sum = 0;
  for(i = 0;i <5; i++){
    //accounts for the int vals of the faces
    //ace = 0...king = 12
    for(j = 0; j <13; j++){
      if( (*(hPtr +i)).face == wFace[j]){
	sum += j;
	if( j < minValue ){
 	  minValue = j;
	}
      }
    }
  }
  if(sum == (minValue +5)){
    bool = 1;
  }
  return bool;
}

/*
  Determines whether the hand has all the same suit and cards: A, K, Q, J, 10 (10, 11, 12, 13, 1)
  Returns 0 for false.
  Returns 1 for true.
*/
int royalFlush(Card * hPtr, const char * wFace[]){
  int bool = 0, i = 0, ace = 0, king = 0, queen = 0, jack = 0, ten = 0;
  if(straight(hPtr, wFace) == 1 ){
    for(i = 0; i < 5; i++){
      // check for Ace
      if( (*(hPtr +i)).face == wFace[0]){
	ace = 1;
      }
      // check for Ten
      if( (*(hPtr + i)).face == wFace[9]){
	ten = 1;
      }
      // check for Jack
      if( (*(hPtr + i)).face == wFace[10]){
	jack = 1;
      }
      // check for Queen
      if( (*(hPtr +i)).face == wFace[11]){
	queen = 1;
      }
      // check for King
      if( (*(hPtr +i)).face == wFace[12]){
	king = 1;
      }
    }
    if( ace == 1 && ten == 1 && jack == 1 && queen == 1 && king == 1 ){
      bool = 1;
    }
    else{
      bool = 0;
    }
  }
  return bool;
}

/*
  Determines whether the cards have three of a kind and also one pair
  Returns 0 for false.
  Returns 1 for true.
*/
int fullHouse(Card * hPtr, const char * wFace[]){
  int bool = 0, i = 0, j = 0, whilebool = 1, sameCount = 0, twoPair = 0, threeKind = 0;
  int bool_face_array[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for(i = 0; i < 5; i++){
    whilebool = 1;
    j = 0;
    while(whilebool){
      if( (*(hPtr + i)).face == wFace[j]){
	whilebool = 0;
	bool_face_array[j] += 1;
      }
      j++;
    }
  }
  
  // checks for a 2 and 3 in the array
  for(i = 0 ; i < 13; i++){
    if(bool_face_array[i] == 2){
      if(twoPair == 1){
	bool = 0;
	return bool;
      }
      else{
	twoPair = 1;
      }
    }
    if(bool_face_array[i] == 3){
      if(threeKind == 1){
	bool = 0;
	return bool;
      }
      else{
	threeKind = 1;
      }
    }
    if(bool_face_array[i] != 0 || bool_face_array[i] != 2 || bool_face_array[i] != 3){
      bool = 0;
      return bool;
    }
  }
  
  // checks to ensure ensure that there is two pairs and three kinds
  if(twoPair == 1 && threeKind == 1){
    bool = 1;
  }

  return bool;
}

/* Prints out a summary of what the hand holds */
void check(Card * hPtr, const char * wFace[]){
  if(highCard(hPtr, wFace) == 1){
    printf("\nYour hand has a highcard.");
  }
  if(twoPair(hPtr) == 1){
    printf("\nYour hand has two pairs.");
  }
  if(threeOfKind(hPtr) == 1){
    printf("\nYour hand has three of a kind.");
  }
  if(straight(hPtr, wFace) == 1){
    printf("\nYour hand has a straight.");
  }
  if(royalFlush(hPtr, wFace) == 1){
    printf("\nYour hand has a royal flush.");
  }
  if(fullHouse(hPtr, wFace) == 1){
    printf("\nYour hand has a fullhouse.");
  }
}
