#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct Position{
  int posr;
  int posc;
  bool operator==(const Position &a) const{
    return ((posr == a.posr) && (posc == a.posc));
  }
}Position;

class StochasticBotClean{
private:
  struct Position botPos;
  vector<string> board;
  void readInp();
public:
  StochasticBotClean();
  void solveprob(void);
  ~StochasticBotClean();
};

StochasticBotClean::StochasticBotClean(){
  botPos.posr = -1;
  botPos.posc = -1;
}

void StochasticBotClean::readInp(){
  cin>>botPos.posr>>botPos.posc;
  FOR(i,0,5){
    string s;
    cin >> s;
    board.push_back(s);
  }
}

void StochasticBotClean::solveprob(){
  this->readInp();
  struct Position dirtpos;
  FOR(i,0,5){
    FOR(j,0,5){
      if (board[i][j] == 'd'){
	dirtpos.posr = i;
	dirtpos.posc = j;
      }
    }
  }
  if (dirtpos == botPos){
    cout<<"CLEAN"<<endl;
  }else if ((dirtpos.posc - botPos.posc) > 0){
    cout<<"RIGHT"<<endl;
  }else if ((dirtpos.posc - botPos.posc) < 0){
    cout<<"LEFT"<<endl;
  }else if((dirtpos.posr - botPos.posr) > 0){
    cout<<"DOWN"<<endl;
  }else if((dirtpos.posr - botPos.posr) < 0){
    cout<<"UP"<<endl;
  }
  
}

StochasticBotClean::~StochasticBotClean(){
}

int main(){
  StochasticBotClean sbc;
  sbc.solveprob();
  return 0;
}
