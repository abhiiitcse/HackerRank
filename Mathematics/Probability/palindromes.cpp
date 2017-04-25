#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_ROW 10
#define MAX_COL 10
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

double mat[MAX_ROW][MAX_COL];
double constVal[MAX_ROW];

void init_mat(void){
  mat[0][0] = 2.0; mat[0][1] = 1.0; mat[0][2] = 1.0;
  mat[1][0] = 4.0; mat[1][1] = -6.0; mat[1][2] = 0.0;
  mat[2][0] = -2.0; mat[2][1] = 7.0; mat[2][2] = 2.0;
  constVal[0] = 5.0; constVal[1] = -2.0; constVal[2] = 9.0;
  int row = 3;
  int col = 3;
}

int get_pivot_row(int r, int c1){
  double max_val = mat[c1][c1];
  int ret_index = c1;
  FOR(j,c1,r){
    if(mat[j][c1]>max_val){
      ret_index = j;
      max_val = mat[j][c1];
    }
  }
  return ret_index;
}

void swaprow(int r1,int r2,int c){
  double temp[c];
  FOR(j,0,c){
    temp[j] = mat[r1][j];
  }
  FOR(j,0,c){
    mat[r1][j] = mat[r2][j];
  }
  FOR(j,0,c){
    mat[r2][j] = temp[j];
  }
  double temp_res_val = constVal[r1];
  constVal[r1] = constVal[r2];
  constVal[r2] = temp_res_val;
} 

int forward_elimination(int r, int c){
  int cur_row = 0;
  FOR(i,0,c){
    int pivot_row = get_pivot_row(r,i);
    if(pivot_row!=i){
      swaprow(i,pivot_row,c);
    }
    FOR(k,i+1,r){
      double f = mat[k][i]/mat[i][i];
      FOR(j,i+1,c){
	mat[k][j] -= f*mat[i][j];
      }
      constVal[k] -= f*constVal[i];
      mat[k][i] = 0;
    } 
  }
  return -1;
}

void backSub(int r,int c){
  double x[r];
  for(int i=r-1;i>=0;i--){
    x[i] = constVal[i];
    for(int j=i+1;j<c;j++){
      x[i] -= mat[i][j]*x[j];
    }
    x[i] /= mat[i][i];
  }
  FOR(i,0,r){
    cout<<x[i]<<endl;
  }
}

void gaussElim(void){
  forward_elimination(3,3);
  backSub(3,3);
}

int main(){
  init_mat();
  gaussElim();
  return 0;
}
