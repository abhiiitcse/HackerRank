#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

bool compare(pair<int,int> a, pair<int ,int> b){
  return (a.first<= b.first);
}

int main(){
  int N,K;
  cin>>N>>K;
  vector<pair<int,int> > LTval;
  int numImpContest = 0;
  long int total_sum = 0;
  FOR(i,0,N){
    int a,b;
    cin>>a>>b;
    LTval.push_back(make_pair(a,b));
    if (b ==1){
      numImpContest += 1;
    }
    total_sum += a;
  }
  sort(LTval.begin(),LTval.end(),compare);
  int maxdefeat = numImpContest - K;
  if(maxdefeat <= 0){
    cout<<total_sum<<endl;
  }else{
    int tot = 0;
    FOR(i,0,N){
      if(LTval[i].second == 1){
	total_sum = total_sum - (2*LTval[i].first);
	tot += 1;
      }
      if(tot == maxdefeat){
	break;
      }
    }
    cout<<total_sum<<endl;
  }
  
  return 0;
}
