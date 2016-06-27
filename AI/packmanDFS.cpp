#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORI(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
struct Position{
  int posr;
  int posc;
  bool operator==(const Position &a) const{
    return ((this->posr == a.posr) && (this->posc == a.posc));
  }
  Position& operator=(const Position &a) {
    posr = a.posr;
    posc = a.posc;
    return *this;
  }
}Position;

class PackmanDFS{
private:
  struct Position packmanpos, foodpos;
  void readInp(void);
  int gridsize[2];
  vector<string> board;
public:
  PackmanDFS();
  void solveprob(void);
  ~PackmanDFS();
};

PackmanDFS::PackmanDFS(){
}

void PackmanDFS::readInp(void){
  cin>>packmanpos.posr>>packmanpos.posc;
  cin>>foodpos.posr>>foodpos.posc;
  cin>>gridsize[0]>>gridsize[1];
  FOR(i,0,gridsize[0]){
    string s;
    cin>>s;
    board.push_back(s);
  }
}

PackmanDFS::~PackmanDFS(){
}

void PackmanDFS::solveprob(void){
  this->readInp();
  stack<struct Position >dfstk;
  vector<struct Position> all_moves;
  vector<struct Position> path_move;
  int spath[gridsize[0]*gridsize[1]];
  struct Position nextmove;
  struct Position pushmove;
  struct Position tempmove;
  int total_move = 0;
  bool foundfood = false;
  bool visited[gridsize[0]][gridsize[1]]; 
  FOR(i,0,gridsize[0]){
    FOR(j,0,gridsize[1]){
      visited[i][j] = false;
    }
  }
  dfstk.push(packmanpos);
  visited[packmanpos.posr][packmanpos.posc] = true;
  spath[packmanpos.posr*gridsize[1] + packmanpos.posc] = -1;
  while ((!dfstk.empty()) && (!foundfood)){
    nextmove = dfstk.top();
    dfstk.pop();
    total_move += 1;
    all_moves.push_back(nextmove);
    if (nextmove == foodpos){
      foundfood = true;
    }
    if((nextmove.posr > 0) && (board[nextmove.posr-1][nextmove.posc] != '%') && (!visited[nextmove.posr-1][nextmove.posc])){
      pushmove.posr = nextmove.posr-1;
      pushmove.posc = nextmove.posc;
      visited[pushmove.posr][pushmove.posc] = true;
      dfstk.push(pushmove);
      spath[pushmove.posr*gridsize[1] + pushmove.posc] = (nextmove.posr*gridsize[1] + nextmove.posc);
    }
    if((nextmove.posc > 0) && (board[nextmove.posr][nextmove.posc-1] != '%') && (!visited[nextmove.posr][nextmove.posc-1])){
      pushmove.posr = nextmove.posr;
      pushmove.posc = nextmove.posc-1;
      visited[pushmove.posr][pushmove.posc] = true;
      dfstk.push(pushmove);
      spath[pushmove.posr*gridsize[1] + pushmove.posc] = (nextmove.posr*gridsize[1] + nextmove.posc);
    }
    if((nextmove.posr < (gridsize[1]-1)) && (board[nextmove.posr][nextmove.posc+1] != '%') && (!visited[nextmove.posr][nextmove.posc+1])){
      pushmove.posr = nextmove.posr;
      pushmove.posc = nextmove.posc+1;
      visited[pushmove.posr][pushmove.posc] = true;
      dfstk.push(pushmove);
      spath[pushmove.posr*gridsize[1] + pushmove.posc] = (nextmove.posr*gridsize[1] + nextmove.posc);
    }
    if((nextmove.posr < (gridsize[0]-1)) && (board[nextmove.posr+1][nextmove.posc] != '%') && (!visited[nextmove.posr+1][nextmove.posc])){
      pushmove.posr = nextmove.posr+1;
      pushmove.posc = nextmove.posc;
      visited[pushmove.posr][pushmove.posc] = true;
      dfstk.push(pushmove);
      spath[pushmove.posr*gridsize[1] + pushmove.posc] = (nextmove.posr*gridsize[1] + nextmove.posc);
    }
  }
  cout<<total_move<<endl;
  FOR(i,0,all_moves.size()){
    cout<<all_moves[i].posr<<" "<<all_moves[i].posc<<endl;
  }
  tempmove = foodpos;
  int path_cnt = -1;
  while(spath[tempmove.posr*gridsize[1] + tempmove.posc] != -1){
    path_move.push_back(tempmove);
    path_cnt += 1;
    int r = spath[tempmove.posr*gridsize[1] + tempmove.posc]/gridsize[1];
    int c = spath[tempmove.posr*gridsize[1] + tempmove.posc] - (r*gridsize[1]);
    tempmove.posr = r;
    tempmove.posc = c;
  }
  path_cnt += 1;
  path_move.push_back(tempmove);
  cout<<path_cnt<<endl;
  FORI(i,path_move.size()-1,0){
    cout<<path_move[i].posr<<" "<<path_move[i].posc<<endl;
  }
    
  
}

int main(){
  PackmanDFS pmd;
  pmd.solveprob();
  return 0;
}
