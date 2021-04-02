// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

struct Card{
  const char* face;
  const char* suit;
};


// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[], 
	  const char *wSuit[], struct Card * myhand); // dealing doesn't modify the arrays
// my own functions here
int highCard(struct Card * hPtr, const char *wFace[]);
int twoPairs(struct Card * hPtr);
int threeOfKind(struct Card * hPtr);
int straight(struct Card * hPtr, const char *wFace[]);
int flush(struct Card * hPtr);
int fourOfKind(struct Card * hPtr);
int straightFlush(struct Card * hPtr, const char *wFace[]);
void check(struct Card * hPtr, const char *wFace[]);


int main(void)
{
  // initialize deck array
  unsigned int deck[SUITS][FACES] = { 0 };

  srand(time(NULL)); // seed random-number generator

  shuffle(deck); // shuffle the deck

  // initialize suit array                       
   const char *suit[SUITS] =            
     {"Hearts", "Diamonds", "Clubs", "Spades"};
   
   // initialize face array                   
   const char *face[FACES] =
     {"Ace", "Deuce", "Three", "Four",         
      "Five", "Six", "Seven", "Eight",         
      "Nine", "Ten", "Jack", "Queen", "King"};

   // I created a hand of 5 cards with a pointer to it
   struct Card myHand[5];
   struct Card * hPtr = myHand;
   deal(deck, face, suit, hPtr); // deal the deck
   //check
   check(hPtr, face);
   

}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
  size_t card = 1;
  // for each of the cards, choose slot of deck randomly
  for (card = 1; card <= CARDS; ++card) {
    size_t row; // row number
    size_t column; // column number

    // choose new random location until unoccupied slot found
    do {                                                        
      row = rand() % SUITS;                                   
      column = rand() % FACES;                             
    } while(wDeck[row][column] != 0); // end do...while

    // place card number in chosen slot of deck
    wDeck[row][column] = card;
  } 
  return;
}


// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[],
	  const char *wSuit[], struct Card * myHand)
{
  // deal each of the cards
  size_t card = 1;
  size_t row = 0;
  size_t column = 0;
  // added
  int cardnum = 1;
  int fivecount = 0;
  

  for (card = 1; card <= CARDS; ++card) {
    // loop through rows of wDeck
    for (row = 0; row < SUITS; ++row) {
      // loop through columns of wDeck for current row
      for (column = 0; column < FACES; ++column) {
	// if slot contains current card, display card
	if (wDeck[row][column] == card) {
	  // dealing the 1st 5 cards
	  if(fivecount < 5){
	    // Here I set the pointer to instantiate the face and the suit of teh first 5 cards
	    (*(myHand + fivecount)).face = wFace[column];
	    (*(myHand + fivecount)).suit = wSuit[row];
	    fivecount++;
	  }
	  printf("%d - ", cardnum);
	  printf("%5s of %-8s%c", wFace[column], wSuit[row],
		 card % 2 == 0 ? '\n' : '\t'); // 2-column format
	  cardnum++;
	  
	} 
      } 
    } 
  } 
  return;
}

/*
 Determines whether the five cards does not match whatsoever
 Returns 1 for true
 Returns 0 for false
 */
int highCard(struct Card * hPtr, const char *wFace[]){
  int bool = 1;
  if( twoPairs(hPtr) == 1 || threeOfKind(hPtr) == 1 || straight(hPtr, wFace) == 1|| flush(hPtr) == 1|| fourOfKind(hPtr) == 1 || straightFlush(hPtr, wFace) == 1){
    bool = 0;
  }
  return bool; 
}

/*                                                                                                       Determines whether the five cards contains two pairs.
  Returns 1 for true.
  Return 0 for false.
*/
int twoPairs(struct Card * hPtr){
  int bool = 0, i =0, j =0, numPair = 0, avoid = 0;
  for(i = 0; i < 5; i++){
    for(j = i+1; j < 5; j++){
      if( (*(hPtr + i)).face == (*(hPtr +j)).face && j != avoid){
	numPair++;
	avoid = j;
      }
    }
  }

  if(numPair >= 2){
    bool = 1;
  }
  else{
    bool= 0;
  }

  return bool;
}
/*
  Determines whether the five cards have three of the same kind.
  Returns 1 for true.
  Returns 0 for false.
*/
int threeOfKind(struct Card * hPtr){
  int bool = 0, sameCardCount, i, j;
  for(i = 0; i < 3; i++){
    sameCardCount = 1;
    for(j = i + 1; j < 5; j++){
      if( (*(hPtr + i)). face == (*(hPtr +j)).face){
	sameCardCount++;
      }
    }
    if(sameCardCount >= 3){
      bool = 1;
    }
  } 
  return bool;
}
/*
  Determines whether the five cards are in the same sequence but not the same suit.
  Returns 1 for true.                                                                                  
  Returns 0 for false. 
*/
int straight(struct Card * hPtr, const char *wFace[]){
  int bool = 0, i = 0, j = 0, minValue = 13, sum = 0;
  for(i = 0; i < 5; i++){
    // accounts for the int values of Face
    // ace = 0...king = 12
    for(j = 0; j < 13; j++){
      if( (*(hPtr +i)).face == wFace[j]){
	sum += j;
	if( j < minValue ){
	  minValue = j;
	}
      }
    }
  }
  if(sum == (minValue + 5)){
    bool = 1;
  }
  return bool;
}
/*
  Determines whether the five cards are the same suit but not in the same sequence.
  Returns 1 for true.                                                                                  
  Returns 0 for false. 
*/
int flush(struct Card * hPtr){
  int bool = 1, i = 0;
  const char* samesuit = (*(hPtr+i)).suit;
  for(i = 1; i < 5; i ++){
    if( (*(hPtr +i)).suit != samesuit){
      bool = 0;
    }
  }
  return bool;
}
/*
  Determines whether the five cards have the same face and same suit minus 1.
  Returns 1 for true.                                                                                  
  Returns 0 for false. 
*/
int fourOfKind(struct Card * hPtr){
  int bool = 0, sameCardCnt = 0, i = 0, j =0;
  const char * sameFace;
  // finds the same face to look for
  do{
    for(i = 0; i < 2; i++){
      for(j = i + 1; j < 5; j++){
	if( (*(hPtr + 0)).face == (*(hPtr +i)).face){
	  sameFace = (*(hPtr +i)).face;
	  break;
	}
	if(i == 1 && j == 4){
	  break;
	}
      }
    }
  }
  while(bool = 0);
  
  for(i = 0; i < 5; i++){
    if( sameFace == (*(hPtr +i)).face){
      sameCardCnt++;
    }
  }
  
  if(sameCardCnt == 4){
    bool = 1;
  }
  else{
    bool = 0;
  }
  return bool;
}
/*
  Determines whether the five cards have the same sequence and same suit.
  Returns 1 for true.                                                                                  
  Returns 0 for false. 
*/
int straightFlush(struct Card *hPtr, const char *wFace[]){
  int bool = 0;
  if(straight(hPtr, wFace) == 1 && flush(hPtr) == 1){
    bool = 1;
  }
  return bool;
}

/* Checks all w/ no return type just prints */
void check(struct Card * hPtr, const char *wFace[]){
  if(highCard(hPtr, wFace) == 1){
    printf("\nYour hand has a highcard.");
  }
  if(twoPairs(hPtr) == 1){
    printf("\nYour hand has two pairs.");
  }
  if(threeOfKind(hPtr) == 1){
    printf("\nYour hand has three of a kind.");
  }
  if(straight(hPtr, wFace) == 1){
    printf("\nYour hand has a straight.");
  }
  if(flush(hPtr) == 1){
    printf("\nYour hand has a flush.");
  }
  if(fourOfKind(hPtr) == 1){
    printf("\nYour hand has four of a kind.");
  }
  if(straightFlush(hPtr, wFace) == 1){
    printf("\nYour hand has a straight flush.");
  }
  return;
}
      
