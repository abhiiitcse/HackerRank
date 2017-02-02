#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
typedef long int li;

/**
 * Check if solution exists for the given value of A and M
 */
bool checkForSolution(li A, li M){
  if ((A==0) || (M ==2)){
    return true;
  }
  li k = (M-1)/2;
  li ans = 1;
  while(k){
    if((k%2) == 1){
      ans = (ans*A)%M;
    }
    A = (A*A)%M;
    k /= 2;
  }
  return ((ans==1)?true:false);
}
int main(){
  int t;
  cin>>t;
  li A,M;
  while(t--){
    cin>>A>>M;
    if(checkForSolution(A,M)){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
