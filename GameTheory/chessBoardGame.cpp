#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,bool > mp;
static int count1 = 0;

bool getWinner(int x,int y){
  count1++;
  if((x<1)||(y<1)||(x>15)||(y>15)){
    return true;
  }
  if(mp.find(make_pair(x,y))!=mp.end()){
    return mp[make_pair(x,y)];
  }
  bool state = true;
  cout<<"Going for = "<<x<<","<<y<<endl;
  state = state&(getWinner(x-1,y-2));
  state = state&(getWinner(x+1,y-2));
  state = state&(getWinner(x-2,y+1));
  state = state&(getWinner(x-2,y-1));
  cout<<"FOR (x,y) = "<<x<<","<<y<<",state="<<state<<endl;
  return mp[make_pair(x,y)] = (!state);
}

int main(){
  int tt;
  cin>>tt;
  while(tt--){
    int x,y;
    cin>>x>>y;
    if(!getWinner(x,y)){
      cout<<"Second"<<endl;
    }else{
      cout<<"First"<<endl;
    }
    cout<<"rec calls = "<<count1<<endl;
    count1 = 0;
  }
  return 0;
}
