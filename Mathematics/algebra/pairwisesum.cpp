#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    int n;
    ll result = 0;
    int arr[2]={0,0};
    cin>>n;
    FOR(i,1,n){
      ll val;
      cin>>val;
      if((val==1)||(val==2)){
	arr[val-1]+=1;
      }
    }
    if(arr[0]>=1){
      int rest = n-arr[0];
      result += ((arr[0]*(arr[0]-1))+(rest*arr[0]));
    }
    if(arr[1]>1){
      result += (arr[1]*(arr[1]-1)/2);
    }
    cout<<result<<endl;
  }
  return 0;
}
