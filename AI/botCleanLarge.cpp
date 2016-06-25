#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct Position{
  int posr;
  int posc;
  bool operator==(const Position &a) const{
    return ((posr == a.posr) && (posc == a.posc));
  }
}Position;

class BotCleanLarge{
private:
  int H,W;
  vector<string> board;
  vector<string> cboard;
  struct Position botpos;
  void readInp();
  bool done();
  int moves;
public:
  BotCleanLarge();
  void solveprob();
  ~BotCleanLarge();
};

BotCleanLarge::BotCleanLarge():H(0),W(0) { }

bool BotCleanLarge::done(){
  FOR(i,0,H){
    FOR(j,0,W){
      if (cboard[i][j] == 'd'){
	return false;
      }
    }
  }
  return true;
}

void BotCleanLarge::readInp(){
  cin >> botpos.posr >> botpos.posc;
  cin >> H >> W;
  FOR(i,0,H){
    string s;
    cin >> s;
    board.push_back(s);
  }
  moves = INT_MAX;
}

void BotCleanLarge::solveprob(){
  string printstr;
  vector<pair<int,int> > all_dirty;
  int choicer,choicec;
  this->readInp();
  FOR(i,0,H){
    cboard.push_back(board[i]);
  }
  if(cboard[botpos.posr][botpos.posc] == 'd'){
    cout<<"CLEAN"<<endl;
    return;
  }
  FOR(i,0,H){
    FOR(j,0,W){
      if (cboard[i][j] == 'd'){
	all_dirty.push_back(make_pair(i,j));
      }
    }
  }

  int smallDist = INT_MAX;
  FOR(i,0,all_dirty.size()){
    int distNode = fabs(botpos.posr - all_dirty[i].first) + fabs(botpos.posc - all_dirty[i].second);
    if (distNode < smallDist){
      smallDist = distNode;
      choicer = all_dirty[i].first;
      choicec = all_dirty[i].second;
    }
  }

  if ((choicec - botpos.posc) > 0){
    cout<<"RIGHT"<<endl;
  }else if((choicec - botpos.posc) < 0){
    cout<<"LEFT"<<endl;
  }else if((choicer - botpos.posr) > 0){
    cout<<"DOWN"<<endl;
  }else if((choicer - botpos.posr) < 0){
    cout<<"UP"<<endl;
  }
}

BotCleanLarge::~BotCleanLarge(){
}

int main(){
  BotCleanLarge bcl;
  bcl.solveprob();
  return 0;
}
