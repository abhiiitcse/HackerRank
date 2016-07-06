#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
struct Position{
  int r;
  int c;
}Position;

struct Compare{
  vector<int> vec;
  int prt;
  bool operator<(const Compare& a) const{
    return (prt > a.prt);
  }
}Compare;


class NPuzzle{
private:
  vector<int> initState;
  vector<int> goalState;
  int boardSize;
  void readInp();
  int calHeuristic(vector<int> currState);
public:
  NPuzzle();
  void solveProb(void);
  ~NPuzzle();
};

NPuzzle::NPuzzle(){
}

int NPuzzle::calHeuristic(vector<int> currState){
  int retval = 0;
  FOR(i,0,boardSize*boardSize){
    int r1=(i/boardSize);
    int c1=(i-(r1*boardSize));
    FOR(j,0,boardSize*boardSize){
      if(goalState[i]==currState[j]){
	int r2 = (j/boardSize);
	int c2 = (j-(r2*boardSize));
	retval += fabs(r1-r2) + fabs(c1-c2);
	break;
      }
    }
  }
  return retval;
}
				     

void NPuzzle::readInp(){
  cin>>boardSize;
  FOR(i,0,boardSize*boardSize){
    int val;
    cin>>val;
    initState.push_back(val);
    goalState.push_back(i);
  }  
}

void NPuzzle::solveProb(){
  this->readInp();
  vector<int> currState;
  vector<int> prevState;
  struct Compare cp;
  bool found=false;
  currState = initState;
  int currHVal = calHeuristic(currState);
  priority_queue<struct Compare> pq;
  map<vector<int>,bool> visited;
  cp.vec = currState;
  cp.prt = currHVal;
  pq.push(cp);
  while(!pq.empty() && !found){
    prevState = pq.top().vec;
    pq.pop();
    currHVal = calHeuristic(prevState);
    if(currHVal == 0){
      found = true;
    }
    int currPos[2],newPos[2];
    FOR(i,0,boardSize){
      if(prevState[i] == 0){
	currPos[0] = (i/boardSize);
	currPos[1] = i - (currPos[0]*boardSize);
      }
    }
    if((currPos[0] > 0)){
      cout<<"UP"<<endl;
      newPos[0] = currPos[0] - 1;
      newPos[1] = currPos[1];
      currState = prevState;
      currState[currPos[0]*boardSize + currPos[1]] = currState[newPos[0]*boardSize + newPos[1]];
      currState[newPos[0]*boardSize + newPos[1]] = 0;
      cp.vec = currState;
      cp.prt = calHeuristic(currState);
      pq.push(cp);
    }
    if((currPos[1] > 0)){
      cout<<"LEFT"<<endl;
      newPos[0] = currPos[0];
      newPos[1] = currPos[1]-1;
      currState = prevState;
      currState[currPos[0]*boardSize + currPos[1]] = currState[newPos[0]*boardSize + newPos[1]];
      currState[newPos[0]*boardSize + newPos[1]] = 0;
      cp.vec = currState;
      cp.prt = calHeuristic(currState);
      pq.push(cp);
    }
    if((currPos[1] < (boardSize-1))){
      cout<<"RIGHT"<<endl;
      newPos[0] = currPos[0];
      newPos[1] = currPos[1]+1;
      currState = prevState;
      currState[currPos[0]*boardSize + currPos[1]] = currState[newPos[0]*boardSize + newPos[1]];
      currState[newPos[0]*boardSize + newPos[1]] = 0;
      cp.vec = currState;
      cp.prt = calHeuristic(currState);
      pq.push(cp);
    }
    if((currPos[0] < (boardSize-1))){
      cout<<"DOWN"<<endl;
      newPos[0] = currPos[0] + 1;
      newPos[1] = currPos[1];
      currState = prevState;
      currState[currPos[0]*boardSize + currPos[1]] = currState[newPos[0]*boardSize + newPos[1]];
      currState[newPos[0]*boardSize + newPos[1]] = 0;
      cp.vec = currState;
      cp.prt = calHeuristic(currState);
      pq.push(cp);
    }
  }
  // cout<<currHVal<<endl;

}

NPuzzle::~NPuzzle(){
}

int main(){
  NPuzzle np;
  np.solveProb();
  return 0;
}
