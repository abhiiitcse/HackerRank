#include <bits/stdc++.h>
#define MOD 1000000007
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std;
int powers[] = {2,3,5,7};
double logpow[] = {log(2),log(3),log(5),log(7)}
vector<vector<int> > arr[25];

vector<int> getpow(long val){
  vector<int> ret_val(4,0);
  if(val==0){
    return ret_val;
  }
  FOR(i,0,4){
    while((val%powers[i])==0){
      ret_val[i]++;
      val /= powers[i];
    }
  }
  return ret_val;
}

void printvec(vector<int> vec){
  FOR(i,0,vec.size()){
    cout<<vec[i]<<" ";
  }
  cout<<endl;
}

int main(){
  cout<<logpow[1]<<endl;
  int n;
  cin>>n;
  int x,s,f,m;
  cin>>x>>s>>f>>m;
  
  FOR(i,0,n){
    FOR(j,0,n){
      long val;
      cin>>val;
      vector<int> vec = getpow(val);
      arr[i].pb(vec);
      cout<<"FOR i="<<val<<endl;
      printvec(vec);
    }
  }
  FOR(i,0,n){
    cout<<"size for i="<<i<<" , "<<arr[i].size()<<endl;
  }
  
  return 0;
}
