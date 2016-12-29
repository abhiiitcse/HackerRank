#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef long int li;

li get_val(li *arr,int N,li val){
  li ret_val = INT_MAX;
  FOR(i,0,N-1){
    ret_val = min(ret_val,abs(arr[i]-val));
  }
  return ret_val;
}
  
int main(){
  int N;
  cin>>N;
  li arr[N];
  FOR(i,1,N){
    cin>>arr[i-1];
  }
  sort(arr,arr+N);
  li P,Q;
  cin>>P>>Q;
  li result = P;
  if(get_val(arr,N,Q)>get_val(arr,N,result)){
    result = Q;
  }
  FOR(i,0,N-1){
    li mid_val = (arr[i]+arr[i+1])/2;
    if((mid_val>=P)&&(mid_val<=Q)){
      if(get_val(arr,N,mid_val) > get_val(arr,N,result)){
	result = mid_val;
      }
    }
  }  
  cout<<result<<endl;
  return 0;
}
