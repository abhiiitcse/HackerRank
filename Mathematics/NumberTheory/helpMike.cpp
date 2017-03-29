#include <iostream>
#include <cmath>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
typedef long int li;
int main(){
  int t;
  cin>>t;
  while(t--){
    li n,k;
    cin>>n>>k;
    li arr[k];
    arr[0] = n/k;
    FOR(i,1,k-1){
      arr[i] = (int)(n-i)/k + 1;
    }
    li sum = 0;
    if((k%2)!=0){
      sum += (arr[0]*(arr[0]-1))/2;
      FOR(i,1,k/2){
	sum += (arr[i]*arr[k-i]);
      }
    }else{
      sum += (arr[0]*(arr[0]-1))/2;
      FOR(i,1,k/2-1){
	sum += (arr[i]*arr[k-i]);
      }
      sum += (arr[k/2]*(arr[k/2]-1))/2;
    }
    cout<<sum<<endl;
  }
  return 0;
}
  
