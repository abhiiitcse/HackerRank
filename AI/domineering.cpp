#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <climits>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

class Domineering{
private:
  vector<string> board;
  int sizex,sizey;
  char player;
  char MAX_NODE, MIN_NODE;
  pair<int,int> final_move;
  void readinp(void);
  vector<pair<int,int> > possChoice(char curr_player);
  int checkCurrState(char player);
  int minimax(char player,int alpha,int beta);
  int evaluateBoard(char player);
public:
  Domineering();
  void solveprob();
  ~Domineering();
};

Domineering::Domineering():sizex(0), sizey(0) { }

int Domineering::evaluateBoard(char player){
  if (player==MAX_NODE){
    vector<pair<int,int> > retval = possChoice(MIN_NODE);
    if(retval.size()!=0){
      return retval.size();
    }else{
      return 1;
    }
  }else{
    vector<pair<int,int> > retval = possChoice(MAX_NODE);
    if(retval.size()!=0){
      return -1*retval.size();
    }else{
      return -11;
    }
  }
}

void Domineering::readinp(){
  cin>>player;
  sizex = sizey = 8;
  MAX_NODE = player;
  MAX_NODE == 'v' ? MIN_NODE='h':MIN_NODE='v';
  FOR(i,0,8){
    string s;
    cin>>s;
    board.push_back(s);
  }
}

int Domineering::checkCurrState(char player){
  vector<pair<int,int> > all_pos = possChoice(player);
  if (all_pos.size() == 0){
    return 1;
  }
  return 0;
}

vector<pair<int,int> > Domineering::possChoice(char curr_player){
  vector<pair<int,int> > retval;
  if (curr_player=='v'){
    FOR(i,0,sizex-1){
      FOR(j,0,sizey){
	if((board[i][j]=='-') && (board[i+1][j]=='-')){
	  retval.push_back(make_pair(i,j));
	}
      }
    }
  }else{
    FOR(i,0,sizex){
      FOR(j,0,sizey-1){
	if((board[i][j] == '-') && (board[i][j+1] == '-')){
	  retval.push_back(make_pair(i,j));
	}
      }
    }
  }
  return retval;
}

void Domineering::solveprob(){
  this->readinp();
  int alpha = INT_MIN;
  int beta = INT_MAX;
  minimax(player,alpha,beta);
  cout<<final_move.first<<" "<<final_move.second<<endl;
  //vector<pair<int,int> > all_poss = possChoice(player);
  //FOR(i,0,all_poss.size()){
  //cout<<all_poss[i].first<<" "<<all_poss[i].second<<endl;
  //}
}

int Domineering::minimax(char player,int alpha, int beta){
  if(checkCurrState(player)){
    return evaluateBoard(player);
  }
  if(player == MAX_NODE){
    int val = INT_MIN;
    vector<pair<int,int> > all_poss = possChoice(player);
    while(!all_poss.empty()){
      pair<int,int> curr_move = all_poss.back();
      all_poss.pop_back();
      if(MAX_NODE=='v'){
	board[curr_move.first][curr_move.second] = MAX_NODE;
	board[curr_move.first+1][curr_move.second] = MAX_NODE;
      }else{
	board[curr_move.first][curr_move.second] = MAX_NODE;
	board[curr_move.first][curr_move.second+1] = MAX_NODE;

      }
      int val1 = max(val,minimax(MIN_NODE,alpha,beta));
      if(val1>val){
	val = val1;
	final_move = curr_move;
      }
      alpha = max(alpha,val);
      if (beta<=alpha){
	break;
      }
      if(MAX_NODE=='v'){
	board[curr_move.first][curr_move.second] = '-';
	board[curr_move.first+1][curr_move.second] = '-';
      }else{
	board[curr_move.first][curr_move.second] = '-';
	board[curr_move.first][curr_move.second+1] = '-';
      }
    }
    return val;
  }else{
    int val_min = INT_MAX;
    vector<pair<int,int> > all_poss1 = possChoice(player);
    while(!all_poss1.empty()){
      pair<int,int> curr_move1 = all_poss1.back();
      all_poss1.pop_back();
      if (MIN_NODE=='h'){
	board[curr_move1.first][curr_move1.second] = MIN_NODE;
	board[curr_move1.first][curr_move1.second+1] = MIN_NODE;
      }else{
	board[curr_move1.first][curr_move1.second] = MIN_NODE;
	board[curr_move1.first+1][curr_move1.second] = MIN_NODE;
      }
      //cout<<all_poss1.size()<<endl;
      int val1 = min(val_min,minimax(MAX_NODE,alpha,beta));
      //int val1 = min(val,minimax(MAX_NODE,alpha,beta));
      if (val1 < val_min){
	val_min = val1;
      }
      beta = min(beta,val_min);
      if (beta <= alpha){
	break;
      }
      if(MIN_NODE=='h'){
	board[curr_move1.first][curr_move1.second] = '-';
	board[curr_move1.first][curr_move1.second+1] = '-';
      }else{
	board[curr_move1.first][curr_move1.second] = '-';
	board[curr_move1.first+1][curr_move1.second] = '-';
      }
    }
    return val_min;
  }
  return 0;
}

Domineering::~Domineering(){ }

int main(){
  Domineering dm;
  dm.solveprob();
  return 0;
}
