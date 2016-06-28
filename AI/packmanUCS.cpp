#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORI(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

struct Position{
  int posr;
  int posc;
  bool operator==(const Position& a) const{
    return ((posr == a.posr) && (posc == a.posc));
  }
}Position;

struct Pqnode{
  struct Position node;
  int priority;
  bool operator<(const Pqnode& a) const{
    return (priority > a.priority);
  }
}Pqnode;

class PackmanUCS{
private:
  vector<string> board;
  int boardsize[2];
  struct Position packmanpos,foodpos;
  void readInp(void);
public:
  PackmanUCS();
  void solveprob();
  ~PackmanUCS();
};

PackmanUCS::PackmanUCS(){
}

PackmanUCS::~PackmanUCS(){
}

void PackmanUCS::readInp(void){
  cin>>packmanpos.posr>>packmanpos.posc;
  cin>>foodpos.posr>>foodpos.posc;
  cin>>boardsize[0]>>boardsize[1];
  FOR(i,0,boardsize[0]){
    string s;
    cin>>s;
    board.push_back(s);
  }
}

void PackmanUCS::solveprob(){
  this->readInp();
  priority_queue<struct Pqnode> pq;
  struct Pqnode pqtemp;
  struct Pqnode popnode;
  struct Position temppos;
  int path[boardsize[0]][boardsize[1]];
  int total_count = 0;
  bool foodfound = false;
  bool visited[boardsize[0]][boardsize[1]];
  int g[boardsize[0]][boardsize[1]];
  int pr[boardsize[0]][boardsize[1]];
  FOR(i,0,boardsize[0]){
    FOR(j,0,boardsize[1]){
      g[i][j] = 10000;
      visited[i][j] = false;
      pr[i][j] = 10000;
    }
  }
  g[packmanpos.posr][packmanpos.posc] = 0;
  pqtemp.node = packmanpos;
  pqtemp.priority = 0;
  pq.push(pqtemp);
  pr[packmanpos.posr][packmanpos.posc] = g[packmanpos.posr][packmanpos.posc];
  path[packmanpos.posr][packmanpos.posc] = -1;
  while(!pq.empty() && (!foodfound)){
    popnode = pq.top();
    pq.pop();
    if (popnode.priority != pr[popnode.node.posr][popnode.node.posc]){
      continue;
    }
    if((popnode.node.posr == foodpos.posr) && (popnode.node.posc == foodpos.posc)){
      foodfound = true;
    }
    visited[popnode.node.posr][popnode.node.posc] = true;
    total_count += 1;
    if ((popnode.node.posr > 0) && (board[popnode.node.posr-1][popnode.node.posc] != '%') && (!visited[popnode.node.posr-1][popnode.node.posc])){
      temppos.posr = popnode.node.posr-1;
      temppos.posc = popnode.node.posc;
      pqtemp.node = temppos;
      if(temppos == foodpos){
	g[temppos.posr][temppos.posc] = g[popnode.node.posr][popnode.node.posc] + 0;
      }else{
	g[temppos.posr][temppos.posc] = g[popnode.node.posr][popnode.node.posc] + 1;
      }
      if(pr[temppos.posr][temppos.posc] > (g[temppos.posr][temppos.posc])){
	pqtemp.priority = g[temppos.posr][temppos.posc];
	pr[temppos.posr][temppos.posc] = g[temppos.posr][temppos.posc];
	pq.push(pqtemp);
	path[temppos.posr][temppos.posc] = popnode.node.posr*boardsize[1] + popnode.node.posc;
      }
      
    }
    if ((popnode.node.posc > 0) && (board[popnode.node.posr][popnode.node.posc-1] != '%') && (!visited[popnode.node.posr][popnode.node.posc-1])){
      temppos.posr = popnode.node.posr;
      temppos.posc = popnode.node.posc-1;
      pqtemp.node = temppos;
      if(temppos == foodpos){
	g[temppos.posr][temppos.posc] = g[popnode.node.posr][popnode.node.posc] + 0;
      }else{
	g[temppos.posr][temppos.posc] = g[popnode.node.posr][popnode.node.posc] + 1;
      }
      if(pr[temppos.posr][temppos.posc] > g[temppos.posr][temppos.posc]){
	pqtemp.priority = g[temppos.posr][temppos.posc];
	pr[temppos.posr][temppos.posc] = g[temppos.posr][temppos.posc];
	pq.push(pqtemp);
	path[temppos.posr][temppos.posc] = popnode.node.posr*boardsize[1] + popnode.node.posc;
      }

    }
    if ((popnode.node.posc < (boardsize[1]-1)) && (board[popnode.node.posr][popnode.node.posc+1] != '%') && (!visited[popnode.node.posr][popnode.node.posc+1])){
      temppos.posr = popnode.node.posr;
      temppos.posc = popnode.node.posc+1;
      pqtemp.node = temppos;
      if(temppos == foodpos){
	g[temppos.posr][temppos.posc] = g[popnode.node.posr][popnode.node.posc] + 0;
      }else{
	g[temppos.posr][temppos.posc] = g[popnode.node.posr][popnode.node.posc] + 1;
      }
      if(pr[temppos.posr][temppos.posc] > g[temppos.posr][temppos.posc]){
	pqtemp.priority = g[temppos.posr][temppos.posc];
	pr[temppos.posr][temppos.posc] = g[temppos.posr][temppos.posc];
	pq.push(pqtemp);
	path[temppos.posr][temppos.posc] = popnode.node.posr*boardsize[1] + popnode.node.posc;
      }

    }
    if ((popnode.node.posr < (boardsize[0]-1)) && (board[popnode.node.posr+1][popnode.node.posc] != '%') && (!visited[popnode.node.posr+1][popnode.node.posc])){
      temppos.posr = popnode.node.posr+1;
      temppos.posc = popnode.node.posc;
      pqtemp.node = temppos;
      if(temppos == foodpos){
	g[temppos.posr][temppos.posc] = g[popnode.node.posr][popnode.node.posc] + 0;
      }else{
	g[temppos.posr][temppos.posc] = g[popnode.node.posr][popnode.node.posc] + 1;
      }
      if(pr[temppos.posr][temppos.posc] > g[temppos.posr][temppos.posc]){
	pqtemp.priority = g[temppos.posr][temppos.posc];
	pr[temppos.posr][temppos.posc] = g[temppos.posr][temppos.posc];
	pq.push(pqtemp);
	path[temppos.posr][temppos.posc] = popnode.node.posr*boardsize[1] + popnode.node.posc;
      }

    }
  }
  int path_count = 0;
  struct Position pathpos,pathpos1;
  vector<struct Position> pathtravel;
  pathpos = foodpos;
  pathtravel.push_back(foodpos);
   while (path[pathpos.posr][pathpos.posc] != -1){
    path_count += 1;
    pathpos1.posr = path[pathpos.posr][pathpos.posc] / boardsize[1];
    pathpos1.posc = path[pathpos.posr][pathpos.posc] - (pathpos1.posr * boardsize[1]);
    pathpos.posr = pathpos1.posr;
    pathpos.posc = pathpos1.posc;
    pathtravel.push_back(pathpos);
  }
  
   // cout<<total_count<<endl;
  cout<<path_count<<endl;
  FORI(i,pathtravel.size()-1,0){
    cout<<pathtravel[i].posr<<" "<<pathtravel[i].posc<<endl;
  }
  
}

int main(){
  PackmanUCS paucs;
  paucs.solveprob();
  return 0;
}
