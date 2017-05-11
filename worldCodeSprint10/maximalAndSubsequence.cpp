#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MAX 100005
#define MOD 1000000007
using namespace std;
typedef unsigned long long ll;

ll ncr(int n, int r){
  ll result = 0;
  vector<ll> val(r+1);
  FOR(i,0,r+1){
    val[i] = 0;
  }
  FOR(i,1,n+1){
    vector<ll> new_val(r+1);
    FOR(j,0,r+1){
      if(j>i){
	break;
      }
      if(i==j){
	new_val[j] = 1;
      }else if(j==0){
	new_val[j] = 1;
      }else if(j==1){
	new_val[j] = i;
      }else{
	new_val[j] = (val[j] + val[j-1])%MOD;
      }
    }
    val = new_val;
  }
  result = val[r];
  return result;
}


int get_num_vec(vector<ll> arr, int n,int k){
  int ret_val = 0;
  int setindex[64];
  FOR(i,0,64){
    setindex[i] = 0;
  }
  vector<ll> new_arr = arr;
  int s = n;
  for(int i=63;i>=0;i--){
    vector<ll> inc_arr;
    int new_cnt = 0;
    FOR(j,0,s){
      if((new_arr[j]>>i)&1){
	inc_arr.push_back(new_arr[j]);
	new_cnt ++;
      }
    }
    if(new_cnt>=k){
      setindex[i] = 1;
      new_arr = inc_arr;
      s = new_cnt;
    }
  }
  ll sum = 0;
  FOR(i,0,64){
    sum += (setindex[i]*(pow(2,i)));
  }
  cout<<sum<<endl;
  ret_val = s;
  return ret_val;
}

int main(){
  int n,k;
  cin>>n>>k;
  vector<ll> arr;
  FOR(i,0,n){
    ll val;
    cin>>val;
    arr.push_back(val);
  }
  int num_vec = get_num_vec(arr,n,k);
  int r_val = min(k,num_vec-k);
  cout<<ncr(num_vec,r_val)<<endl;
  
  return 0;
}
