#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORI(i,a,b) for(int i=a;i>=b;i--)
typedef short int SI;
using namespace std;
class savePrincess{
private:
  int gridSize;
  vector<string> board;
  void displayPathtoPrincess(void);
  void readInput(void);
public:
  savePrincess();
  void solveProblem(void);
  ~savePrincess();
};

savePrincess::savePrincess(void):gridSize(0){ }

void savePrincess::readInput(void){
  cin>>gridSize;
  FOR(i,0,gridSize){
    string s;
    cin>>s;
    board.push_back(s);
  }
}

void savePrincess::displayPathtoPrincess(void){
  SI botPos[2],princePos[2];
  int up,left;
  FOR(i,0,gridSize){
    FOR(j,0,gridSize){
      if (board[i][j] == 'm'){
	botPos[0] = i;
	botPos[1] = j;
      }
      if (board[i][j] == 'p'){
	princePos[0] = i;
	princePos[1] = j;
      }
    }
  }
  if((up = (princePos[0] - botPos[0])) > 0){
    FOR(i,0,up){
      cout<<"DOWN"<<endl;
    }
  }
  else if((up = (princePos[0] - botPos[0])) < 0){
    FOR(i,up,0){
      cout<<"UP"<<endl;
    }
  }
  if ((left = (princePos[1] - botPos[1])) > 0){
    FOR(i,0,left){
      cout<<"RIGHT"<<endl;
    }
  }
  else if ((left = (princePos[1] - botPos[1])) < 0){
    FOR(i,left,0){
      cout<<"LEFT"<<endl;
    }
  }
}

savePrincess::~savePrincess(void){
}

void savePrincess::solveProblem(void){
  this->readInput();
  this->displayPathtoPrincess();
}
int main(){
  savePrincess sp;
  sp.solveProblem();
  return 0;
}
