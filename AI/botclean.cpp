#include <iostream>
#include <vector>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
class BotClean{
private:
  int boardSize;
  int moves;
  vector<string> board;
  vector<string> cboard;
public:
  BotClean();
  void next_move(int posr, int posc);
  int move(int x,int y, int count);
  void readInp(void);
  bool done (void);
  ~BotClean();
};

BotClean::BotClean():boardSize(5){ }

void BotClean::readInp(void){
  int botPos[2];
  cin>>botPos[0];
  cin>>botPos[1];
  FOR(i,0,boardSize){
    string s;
    cin>>s;
    board.push_back(s);
  }
  moves  = INT_MAX;
  this->next_move(botPos[0],botPos[1]);
}

bool BotClean::done(void){
  FOR(i,0,boardSize){
    FOR(j,0,boardSize){
      if (cboard[i][j] == 'd'){
	return false;
      }
    }
  }
  return true;
}
void BotClean::next_move(int posr,int posc){
  enum Move {RIGHT, LEFT, UP, DOWN, CLEAN};
  string mm;
  FOR(i,0,boardSize){
    cboard.push_back(board[i]);
  }
  if(cboard[posr][posc] == 'd'){
    cout<<"CLEAN"<<endl;
    return;
  }
  if (posc < 4){
    int c = move(posr,posc+1,1);
    if ( moves > c){
      moves  = c;
      mm = "RIGHT";
    }
  }
  if (posc > 0){
    int c = move(posr,posc-1,1);
    if (moves > c){
      moves  = c;
      mm = "LEFT";
    }
  }
  if (posr < 4){
    int c = move(posr+1,posc,1);
    if (moves > c){
      moves  = c;
      mm = "DOWN";
    }
  }
  if (posr > 0){
    int c = move(posr-1,posc,1);
    if (moves > c){
      moves = c;
      mm = "UP";
    }
  }
  cout << mm << endl;
}

int BotClean::move(int x,int y,int count){
  if (this->done()){
    return count;
  }
  if (cboard[x][y] == 'd'){
    cboard[x][y] = 'v';
    int c = this->move(x,y,count+1);
    cboard[x][y] = 'd';
    return c;
  }
  int tmpCnt = INT_MAX;
  cboard[x][y] = 'v';
  if ((y<4) && (cboard[x][y+1] != 'v')){
    tmpCnt = min(tmpCnt,move(x,y+1,count +1));
  }
  if ((y>0) && (cboard[x][y-1] != 'v')){
    tmpCnt = min(tmpCnt,move(x,y-1,count+1));
  }
  if ((x<4) && (cboard[x+1][y] != 'v')){
    tmpCnt = min(tmpCnt,move(x+1,y,count +1));
  }
  if ((x>0) && (cboard[x-1][y] != 'v')){
    tmpCnt = min(tmpCnt,move(x-1,y,count + 1));
  }
  cboard[x][y] = '-';
  return tmpCnt;
}

BotClean::~BotClean(void){
}

int main(){
  BotClean bc;
  bc.readInp();
  return 0;
}
