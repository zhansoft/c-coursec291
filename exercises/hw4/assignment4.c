/*
Name: Sophia Zhang
Assignment 4
 */

#include<stdio.h>
#include<stdlib.h>

int highestpoint(float totalpoints[7]);
int lowestpoint(float totalpoints[7]);

int main(void){
  char* topics[7] = {"Women's rights", "Global warming", "RBG's successor", "Reproductive Rights", "2nd Amendment", "Sex education", "Representation in media"};
  int i, j;
  /*
    This allowed for users to input the topics they cared about...I didn't want to erase it.
    // topics would not have anything in it obviously
  char topic[100];
  for(i = 0; i < 7; i++){
    printf("\nEnter a topic you really care about for topic #%d: ", i+1);
    scanf("\n%s", topic);
    *(topics+i) = topic;
    printf("\n%s ", *(topics+i));
  }
  */

  // Allocating the array of pointers for each column of responses
  int topic_row = 7; int topic_response = 10;
  int** responses = (int**) malloc(topic_row * sizeof(int*));

  // Allocating rows
  for(i = 0; i < topic_row; i++){
    *(responses+i) = (int*) malloc(topic_response * sizeof(int));
  }
  for(i = 0; i < topic_row; i++){
    for(j = 0; j < topic_response; j++){
      *(*(responses+i)+j) = 0;
    }
  }


  // prompting the users
  int user = 0;
  int rating = 0;
  i=0;j= 0;
  do{
    printf("\nHello User %d, you will be asked about certain issues today.", user+1);
    for(i = 0; i < topic_row; i++){
      printf("\nHow do you feel about topic %d, %s: ", i+1, *(topics+i));
      scanf("\n %d", &rating);
      *(*(responses+i)+j) = rating;
    }
    j++;
    user++;
  }while(user < 10);

  // summarizing the results w/ averages
  i, j = 0;                                                                   
  float avgs[7] = {0, 0, 0, 0, 0, 0, 0};
  float totalpoint[7] = {0,0,0,0,0,0,0};
  printf("-------Summary--------");                                            
  for(i = 0; i < 7; i++){                                                      
    printf("\n%s: \t", *(topics+i));                                           
    for(j = 0; j < 10; j++){                                                   
      printf("%d\t", *(*(responses+i)+j));
      *(avgs+i) += *(*(responses+i)+j);
      *(totalpoint+i) += *(*(responses+i)+j);
    }
    *(avgs+i) /= 10;
    printf("Avg: %.1f\n", *(avgs+i));
  }
  printf("-------Summary--------");
 
  // returning the rankings
  // returning the highest points
  printf("\nIssue of most importance: %s\nPoints: %.1f", *(topics + highestpoint(totalpoint)), *(totalpoint + highestpoint(totalpoint)));

  // returning the lowest points
  printf("\nIssue of least importance: %s\nPoints: %.1f", *(topics + lowestpoint(totalpoint)), *(totalpoint + lowestpoint(totalpoint)));

  // returning the ranking of topics
  // sort a temp array
  float temparray[7] = {0, 0, 0, 0, 0, 0, 0};
  for(i = 0; i < 7; i++){
    *(temparray + i) = *(totalpoint + i);
  }
  
  // descending order
  float tmp = 0;
  for(i = 0; i < 7; i++){
    for(j = i + 1; j < 7; j++){
      if(*(temparray + i) < *(temparray + j)){
	tmp = *(temparray + i);
	*(temparray + i) = *(temparray + j);
	*(temparray +j) = tmp;
      }
    }
  }
  
  // printing out the rankings haha
  printf("\n---------Rankings---------");
  for(i = 0; i < 7; i++){
    for(j = 0; j < 7; j++){
      if(*(totalpoint+j) == *(temparray+i)){
	printf("\n%d. %s - %.1f", i+1, *(topics+j), *(totalpoint+j));
      }
    }
  }
  printf("\n---------Rankings---------");

  
  return 0;
}



//Determines the highest point amount in the array
//@param totalpoints      float array that contains all the totalpoints
//return index of the highest point
int highestpoint(float totalpoints[7]){
  int index_max = 0;
  int max = 0;
  int i = 0;
  for(i = 0; i < 7; i++){
    if( *(totalpoints + i ) > max){
      index_max = i;
      max = *(totalpoints +i);
    }
  }
  return index_max;
}

//Determines the lowest point amount in the array
//@param totalpoints      float array that contains all the totalpoints
//return index of the lowest points 
int lowestpoint(float totalpoints[7]){
  int index_min = 0;
  int min = 1000;
  int i = 0;
  for(i = 0; i < 7; i++){
    if( *(totalpoints + i ) < min){
      index_min = i;
      min = *(totalpoints +i);
    }
  }
  return index_min;
}

