#include <iostream>
#include <cmath>
#define mod 1000000007
using namespace std;

int main(){
  int tt;
  long long A,B,N;
  cin>>tt;
  long long val[2][2] = {{1,1},{1,0}};
  while(tt--){
    cin>>A>>B>>N;
    long long retval[2][2] = {{1,0},{0,1}};
    long long temp[2][2];
    long long final_val;
    if (N==0){
      final_val = A;
    }else if(N==1){
      final_val = B;
    }else{
      while(N){
	if((N%2)!=0){
	  temp[0][0] = ((retval[0][0] * val[0][0])%mod + (retval[0][1]*val[1][0])%mod)%mod;
	  temp[0][1] = ((retval[0][0] * val[0][1])%mod + (retval[0][1]*val[1][1])%mod)%mod;
	  temp[1][0] = ((retval[1][0] * val[0][0])%mod + (retval[1][1]*val[1][0])%mod)%mod;
	  temp[1][1] = ((retval[1][0] * val[0][1])%mod + (retval[1][1]*val[1][1])%mod)%mod;
	  for(int i=0;i<2;i++){
	    for(int j=0;j<2;j++){
	      retval[i][j] = temp[i][j];
	    }
	  }
	}
	N = N/2;
	
	temp[0][0] = ((val[0][0] * val[0][0])%mod+(val[0][1]*val[1][0])%mod)%mod;
	temp[0][1] = ((val[0][0] * val[0][1])%mod+(val[0][1]*val[1][1])%mod)%mod;
	temp[1][0] = ((val[1][0] * val[0][0])%mod+(val[1][1]*val[1][0])%mod)%mod;
	temp[1][1] = ((val[1][0] * val[0][1])%mod+(val[1][1]*val[1][1])%mod)%mod;
	
	for(int i=0;i<2;i++){
	  for(int j=0;j<2;j++){
	    val[i][j] = temp[i][j];
	  }
	}
      }
      final_val = ((retval[1][0] * B)%mod + (retval[1][1] * A)%mod)%mod;
    }
    cout<<final_val<<endl;
    val[0][0] = 1; val[0][1] = 1;val[1][0] = 1;val[1][1]=0;
  }
  return 0;
}
