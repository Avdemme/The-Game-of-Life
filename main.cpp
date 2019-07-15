#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include "math.h"
#include "string.h"
#include "time.h" 
#include <cmath>
#include <iomanip>

using namespace std;

double rand_uniform ( long rand_int ) {
  
  return (double)rand() / (double)RAND_MAX;
  
}

void ClearTheScreen ( ) {
  
  printf("\033[%d;%dH",1,1);
  return;
  
}

int main ( int argc, char** argv ) {

  int* a = NULL;
  int ROW;
  int COL;

  ofstream data;
  std::remove("data.txt");

  cout << "Number of Rows = ";
  cin >> ROW;
  cout << "Number of Columns = ";
  cin >> COL;
  
  int neighbors;
  double prob;
  double delay;

   double grid[ROW][COL];
  double next[ROW][COL];

  for ( int i = 0; i < ROW; i++ ){
    for ( int j = 0; j < COL; j++ ) {
      next[i][j] = 0;
    }
  }

  // five life forms grid
  //  double grid[20][40] = {/*row1*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row2*/{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row3*/{0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row4*/{0,0,1,0,1,1,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row5*/{0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row6*/{0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row7*/{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row8*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row9*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row10*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row11*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row12*/{0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row13*/{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row14*/{0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row15*/{0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row16*/{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row17*/{0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row18*/{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row19*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row20*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

  // gosper glider gun
  // double grid[20][40] = {/*row1*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row2*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row3*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row4*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row5*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row6*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row7*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row8*/{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},/*row9*/{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},/*row10*/{0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row11*/{0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row12*/{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row13*/{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row14*/{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row15*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row16*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row17*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row18*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row19*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},/*row20*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

  
  cout << "prob_alive = ";
  cin >> prob;
  cout << " sleep_time = ";
  cin >> delay;
  
  // prob = 0.1;
  // delay = .01;

  int rsd;

  cout << "which seed do you want: (1,2,3)" << endl;
  cin >> rsd;
  
  // rsd = 1;

  if ( rsd == 1 ) { 
    rand_uniform(time(NULL));
  }

  if ( rsd == 2 ) {
    rand_uniform(time(NULL));
    rand_uniform(time(NULL));
  }

  if ( rsd == 3 ) {
    rand_uniform(time(NULL));
    rand_uniform(time(NULL));
    rand_uniform(time(NULL));
  }
  
  int space;
    
    cout << "type of space (0 for edge, 1 for toroidal) = " << endl;
    cin >> space;
  
  // space = 0;
  
  char slow[9]; sprintf(slow,"sleep %lf", delay);
  
  //initial setup that needs to be commented out for manual placement begins
  
  for ( int i = 0; i < ROW; i++ ) {
    for (int j = 0; j < COL; j++ ) {
      if ( rand_uniform(rand()) < prob ) {
	grid[i][j] = 1; cout << "o";
      }
      else {
	grid[i][i] = 0; cout << " ";
      }
    }
    cout << endl;
  }
  
  //initial setup that needs to be commented out ends

  int counters[ROW][COL];

  for ( int i = 0; i < ROW; i++ ) {
    for ( int j = 0; j < COL; j++ ) {
      counters[i][j] = 0;
    }
  }

  double check[ROW][COL];
  double check1[ROW][COL];
  double check2[ROW][COL];
  double check3[ROW][COL];
  double check4[ROW][COL];
  double check5[ROW][COL];
  double check6[ROW][COL];

  for ( int i = 0; i < ROW; i++) {
    for ( int j = 0; j < COL; j++) {
      check[i][j]=0;
    }
  }

  for ( int i = 0; i < ROW; i++) {
    for ( int j = 0; j < COL; j++) {
      check1[i][j]=0;
    }
  }

  for ( int i = 0; i < ROW; i++) {
    for ( int j = 0; j < COL; j++) {
      check2[i][j]=0;
    }
  }
  
  for ( int i = 0; i < ROW; i++) {
    for ( int j = 0; j < COL; j++) {
      check3[i][j]=0;
    }
  }

  for ( int i = 0; i < ROW; i++) {
    for ( int j = 0; j < COL; j++) {
      check4[i][j]=0;
    }
  }

  for ( int i = 0; i < ROW; i++) {
    for ( int j = 0; j < COL; j++) {
      check5[i][j]=0;
    }
  }

  for ( int i = 0; i < ROW; i++) {
    for ( int j = 0; j < COL; j++) {
      check6[i][j]=0;
    }
  }
  
  int tics = 0;
  double boxes = ROW * COL;
  int finish = 1;
  double ratio_num = 0;
  double gen = 0;
  double ratio = 0;

  while ( finish != 0 ) {
    gen++;
    ratio_num = 0;
    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	neighbors = 0;
	if ( i >=1 && grid[i-1][j] == 1 ) neighbors++;
	if ( i < (ROW-1) & grid[i+1][j] == 1 ) neighbors++;
	if ( j < (COL-1) && grid[i][j+1] == 1 ) neighbors++;
	if ( j >= 1 && grid[i][j-1] == 1 ) neighbors++;
	if ( i < (ROW-1) && j < (COL-1) && grid[i+1][j+1] == 1 ) neighbors++;
	if ( i >= 1 && j >= 1 && grid[i-1][j-1] == 1 ) neighbors++;
	if ( i < (ROW-1) && j >= 1 && grid[i+1][j-1] == 1 ) neighbors++;
	if ( i >= 1 && j < (COL-1) && grid[i-1][j+1] == 1 ) neighbors++;
	
	if ( space == 1 && i == 0 && grid[ROW-1][j] == 1 ) neighbors++;
	if ( space == 1 && i == (ROW-1) && grid[0][j] == 1 ) neighbors++;
	if ( space == 1 && i == 0 && j < (COL-1) && grid[ROW-1][j+1] == 1 ) neighbors++;
	if ( space == 1 && i == (ROW-1) && j < (COL-1) && grid[0][j+1] == 1 ) neighbors++;
	if ( space == 1 && i == 0 && j > 0 && grid[ROW-1][j-1] == 1 ) neighbors++;
	if ( space == 1 && i == (ROW-1) && j > 0 && grid[0][j-1] == 1 ) neighbors++;
	if ( space == 1 && i == 0 && j == 0 && grid[ROW-1][COL-1] == 1 ) neighbors++;
	if ( space == 1 && i == 0 && j == (COL-1) && grid[ROW-1][0] == 1 ) neighbors++;
	if ( space == 1 && i == (ROW-1) && j == 0 && grid[0][COL-1] == 1 ) neighbors++;
	if ( space == 1 && i == (ROW-1) && j == (COL-1) && grid[0][0] == 1 ) neighbors++;
	if ( space == 1 && j == 0 && grid[i][COL-1] == 1 ) neighbors++;
	if ( space == 1 && j == 0 && i < (ROW-1) && grid[i+1][COL-1] == 1 ) neighbors++;
	if ( space == 1 && j == 0 && i > 0 && grid[i-1][COL-1] == 1 ) neighbors++;
	if ( space == 1 && j == (COL-1) && i > 0 && grid[i-1][0] == 1 ) neighbors++;
	if ( space == 1 && j == (COL-1) && i < (ROW-1) && grid[i+1][0] == 1 ) neighbors++;
	if ( space == 1 && j == (COL-1) && grid[i][0] == 1 ) neighbors++; 
	
	if ( grid[i][j] == 1 ) {
	  ratio_num++;
	  if ( neighbors < 2 ) next[i][j] = 0;
	  else if ( neighbors > 3 ) next[i][j] = 0;
	  else next[i][j] = grid[i][j];
	}
	else {
	  if ( neighbors == 3 ) next[i][j] = 1;
	}
      }
    }

    ratio = ratio_num / boxes;

    data.open("data.txt",ios::app);
    data << gen << "\t" << ratio << endl;
    data.close();

    cout << gen << "\t" << ratio << endl;


    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	check6[i][j] = check5[i][j];
      }
    }

    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	check5[i][j] = check4[i][j];
      }
    }

    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	check4[i][j] = check3[i][j];
      }
    }

    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	check3[i][j] = check2[i][j];
      }
    }

    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	check2[i][j] = check1[i][j];
      }
    }
    
    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	check1[i][j] = check[i][j];
      }
    }
    
    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	check[i][j] = grid[i][j];
      }
    }
     
    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	grid[i][j] = next[i][j];
      }
    }
     
    system(slow);
    ClearTheScreen();
    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	if ( grid[i][j] == 1 ) cout << "o";
	else cout << " ";
      }
      cout << endl;
    }
    
    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	counters[i][j] = 0;
      }
    }
    
    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	if ( check[i][j] == check6[i][j] ) {
	  counters[i][j] = 1;
	} 
      }
    }
    
    tics = 0;
    for ( int i = 0; i < ROW; i++ ) {
      for ( int j = 0; j < COL; j++ ) {
	if ( counters[i][j] == 1 ) {
	  tics++;
	}
      }
    }
    
     if ( tics == boxes  ) {
     finish = 0;
     }    
  }
    delete [] a;
    a = NULL;
    return 1;
}
      
