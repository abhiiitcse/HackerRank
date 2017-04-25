 #include <iostream>
#include <vector>
#include <cstring>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;
typedef vector<vector<ull> > matrix;

matrix matmul(matrix M1, matrix M2){
  matrix R(15);
  FOR(i,0,14){
    R[i].assign(15,0);
    FOR(j,0,14){
      FOR(k,0,14){
	R[i][j] = (R[i][j] +  (M1[i][k]*M2[k][j]))%MOD;
      }
    }
  }
  return R;
}

matrix npow(matrix M, ull n){
  matrix R(15);
  FOR(i,0,14){
    R[i].assign(15,0);
    FOR(j,0,14){
      if(i==j){
	R[i][j] = 1;
      }else{
	R[i][j] = 0;
      }
    }
  }
  while(n){
    if((n%2)!=0){
      R = matmul(R,M);
    }
    n = (n/2);
    M = matmul(M,M);
  }
  return R;
}

int main(){
  matrix M(15);
  FOR(i,0,14){
    M[i].assign(15,0);
    FOR(j,0,14){
      if((i+1)==j){
	M[i][j] = 1;
      }
    }
  }
  int k;
  ull n;
  ull tmp;
  ull V[15];
  memset(V,0,sizeof(V));
  cin>>n;
  cin>>k;
  M[14].assign(15,0);
  FOR(i,1,k){
    cin>>tmp;
    M[14][14-tmp+1] = 1;
  }
  FOR(i,0,14){
    FOR(j,0,i){
      if(M[14][14-j] == 1){
	  if((i-j)==0){
	    V[i]++;
	  }else{
	    V[i] += V[i-j-1];
	  }
	}
    }
  }
  if(n<=15){
    ull result = 0;
    result = (V[n-1]*2)%MOD;
    cout<<result<<endl;
  }else{
    matrix R = npow(M,n-15);
    ull res = 0;
    FOR(i,0,14){
      res = (res + (R[14][i]*V[i])%MOD)%MOD;
    }
    res = (res*2)%MOD;
    cout<<res<<endl;
  }
  return 0;
}
