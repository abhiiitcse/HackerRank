#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <string>
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
    W = cboard[i].size();
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
  H = W = 5;
  FOR(i,0,H){
    string s;
    cin >> s;
    board.push_back(s);
  }
  moves = INT_MAX;
}

void BotCleanLarge::solveprob(){
  string printstr;
  vector<pair<pair<int,int>,int > > all_dirty;
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
    W = cboard[i].size();
    FOR(j,0,W){
      if (cboard[i][j] == 'd'){
	all_dirty.push_back(make_pair(make_pair(i,j),0));
      }
    }
  }

  if(all_dirty.size()==0){
    if(((botpos.posc+1)<W) && (cboard[botpos.posr][botpos.posc+1]!='o')) {
      cout<<"RIGHT"<<endl;
    }else if(((botpos.posc-1)>=0) && (cboard[botpos.posr][botpos.posc-1]!='o')){
      cout<<"LEFT"<<endl;
    }else if (((botpos.posr+1)<H) && (cboard[botpos.posr+1][botpos.posc]!='o')){
      cout<<"DOWN"<<endl;
    }else if (((botpos.posr-1)>=0) && (cboard[botpos.posr-1][botpos.posc]!='o')){
      cout<<"UP"<<endl;
    }
  }
  else{

    bool found = false;

    while(!found){
      int index =0;
      int smallDist = INT_MAX;
      FOR(i,0,all_dirty.size()){
	if(all_dirty[i].second!=1){
	  int distNode = fabs(botpos.posr - all_dirty[i].first.first) + fabs(botpos.posc - all_dirty[i].first.second);
	  if (distNode < smallDist){
	    smallDist = distNode;
	    choicer = all_dirty[i].first.first;
	    choicec = all_dirty[i].first.second;
	    index = i;
	  }
	}
      }
      all_dirty[index].second = 1;

      if (((choicec - botpos.posc) > 0) && (cboard[botpos.posr][botpos.posc+1]!='o')){
	cout<<"RIGHT"<<endl;
	found = true;
      }else if(((choicec - botpos.posc) < 0)  && (cboard[botpos.posr][botpos.posc-1]!='o')){
	cout<<"LEFT"<<endl;
	found = true;
      }else if(((choicer - botpos.posr) > 0) && (cboard[botpos.posr+1][botpos.posc]!='o')){
	cout<<"DOWN"<<endl;
	found = true;
      }else if(((choicer - botpos.posr) < 0) && (cboard[botpos.posr-1][botpos.posc]!='o')){
	cout<<"UP"<<endl;
	found = true;
      }else{
	found = false;
      }
    }
  }
}

BotCleanLarge::~BotCleanLarge(){
}

int main(){
  BotCleanLarge bcl;
  bcl.solveprob();
  return 0;
}
