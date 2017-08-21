#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>
#include <climits>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MAXC 26
#define MAXS 5200001
using namespace std;
int g[MAXS][MAXC];
set<int> out[MAXS];
int f[MAXS];
int states=1;

int findNextState(int currstate, char nextInput){
  int answer = currstate;
  int ch = nextInput - 'a';
  while(g[answer][ch]==-1){
    answer = f[answer];
  }
  return g[answer][ch];
}

void buildgoto(string word,int index){
  int currentstate = 0;
  FOR(j,0,word.length()){
    int ch = word[j]-'a';
    if(g[currentstate][ch]==-1){
      g[currentstate][ch] = states++;
    }
    currentstate = g[currentstate][ch];
  }
  out[currentstate].insert(index);
}

int buildMatchingMachine(){ 
  set<int>::iterator it;
  FOR(i,0,MAXC){
    if(g[0][i]==-1){
      g[0][i] = 0;
    }
  }
  memset(f,-1,sizeof(f));
  queue<int> q;
  FOR(ch,0,MAXC){
    if(g[0][ch]!=0){
      f[g[0][ch]] = 0;
      q.push(g[0][ch]);
    }
  }
  while(!q.empty()){
    int state = q.front();
    q.pop();
    FOR(ch,0,MAXC){
      if(g[state][ch]!=-1){
	int failure = f[state];
	while(g[failure][ch]==-1){
	  failure = f[failure];
	}
	failure = g[failure][ch];
	f[g[state][ch]] = failure;
	for(it=out[failure].begin();it!=out[failure].end();++it){
	  out[g[state][ch]].insert(*it);
	}
	q.push(g[state][ch]);
      }
    }
  }
  return states;
  
}

vector<int> searchWords(string text,vector<int> lenvec, vector<pair<int,int> > pvec, int health[]){
  int currentState = 0;
  set<int>::iterator it;
  vector<int> result(pvec.size(),0);
  int currvec = 0;
  FOR(i,0,text.size()){
    if(i>=lenvec[currvec]){
      currvec++;
    }
    currentState = findNextState(currentState,text[i]);
    if(out[currentState].size()==0){
      continue;
    }
    set<int> currres = out[currentState];
    for(it=currres.begin();it!=currres.end();++it){
      int nn = *it;
      if((nn<=pvec[currvec].second)&&(nn>=pvec[currvec].first)){
	result[currvec] += health[nn];
      }
    }
  }
  return result;
}

int main(){
  freopen("input.txt","r",stdin);
  memset(g,-1,sizeof(g));
  int n;
  cin>>n;
  //cout<<"n="<<n<<endl;
  int health[n];
  FOR(i,0,n){
    string val;
    cin>>val;
    buildgoto(val,i);
  }
  cout<<"build goto completed"<<endl;
  buildMatchingMachine();
  //cout<<"pattern builded"<<endl;
  FOR(i,0,n){
    cin>>health[i];
  }
  int s;
  cin>>s;
  int minval = INT_MAX;
  int maxval = INT_MIN;
  string text="";
  vector<pair<int,int> > se;
  vector<int> strlen;
  cout<<"here1"<<endl;
  FOR(i,0,s){
    int start,end;
    string d;
    cin>>start>>end>>d;
    text += d;
    strlen.push_back(d.length());
    se.push_back(make_pair(start,end));
  }
  cout<<"here2"<<endl;
  FOR(i,1,s){
    strlen[i] += strlen[i-1];
  }
  vector<int> res = searchWords(text,strlen,se,health);
  FOR(i,0,res.size()){
    if(res[i]>maxval){
      maxval = res[i];
    }
    if(res[i]<minval){
      minval=res[i];
    }
  }
  
  cout<<minval<<" "<<maxval<<endl;
  return 0;
}
