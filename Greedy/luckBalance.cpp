#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii > vpii;
bool compare(const pii &a,const pii &b){
  return a.first <= b.first;
}

int main(){
  int N,K;
  cin>>N>>K;
  vpii input;
  int total_luck = 0;
  int tot_imp = 0;
  FOR(i,0,N-1){
    pii val;
    cin>>val.first>>val.second;
    if(val.second==1){
      tot_imp++;
    }
    total_luck += val.first;
    input.pb(val);
  }

  sort(input.begin(),input.end(),compare);
  //  FOR(i,0,input.size()-1){
  //    cout<<input[i].first<<","<<input[i].second<<endl;
  //  }
  int lost_luck = 0;
  int curr_lost = 0;
  cout<<"hi"<<endl;
  
  FOR(i,0,N-1){
    if(curr_lost >=(tot_imp-K)){
      break;
    }
    if(input[i].second == 1){
      lost_luck += (2*input[i].first);
      curr_lost++;
    }
  }
  //  cout<<total_luck<<endl;
  //  cout<<lost_luck<<endl;
  cout<<total_luck-lost_luck<<endl;
  return 0;
}
  
