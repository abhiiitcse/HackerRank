#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int tt;
  long long A,M,A1;
  long long last_val = 1;
  cin>>tt;
  while(tt--){
    cin>>A1>>M;
    A = A1;
    long long e = (M-1)/2;
    if (e==1){
      last_val = A%M;
    }
    else if(e==0){
      last_val = 1;
    }
    else{
      while(e){
	if((e%2)==1){
	  last_val = (last_val*A)%M;
	}
	A = ((A%M)*(A%M))%M;
	e = e/2;
      }
      last_val = last_val % M;
    }
    if((last_val == 1) || (A1==0) || (A1==2)){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
    last_val = 1;
  }
  return 0;
}
