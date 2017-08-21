#include <bits/stdc++.h>
#define MAX_N 1000001
using namespace std;

int maxgcd = 0;
int maxsum = 0;

int maximumGcdAndSum(vector <int> C, vector <int> D) {
  sort(C.begin(),C.end());
  sort(D.begin(),D.end());
  vector<int> A;vector<int> B;
  if(C[C.size()-1] > D[D.size()-1]){
    A.assign(D.begin(),D.end());
    B.assign(C.begin(),C.end());
  }else{
    A.assign(C.begin(),C.end());
    B.assign(D.begin(),D.end());
  }
  
  
  vector<int> arr_b(MAX_N,0);
  for(int i=0;i<B.size();i++){
    arr_b[B[i]]++;
  }
  sort(A.begin(),A.end());
  
  int i = A.size()-1;
  while(true){
    if(i<0)
      break;
    if((2*A[i])<maxgcd)
      break;
    int sqrtval = sqrt(A[i]);
    bool found = false;
    for(int j=1;j<=sqrtval;j++){
      if((A[i]%j)==0){
	int currdiv = A[i]/j;
	if(arr_b[currdiv]){
	  found = true;
	  int currgcd = currdiv;
	  if(currgcd>maxgcd){
	    maxgcd = currgcd;
	    maxsum = A[i] + currdiv;
	  }else if(currgcd==maxgcd){
	    if(maxsum < (A[i]+currdiv)){
	      maxsum = A[i]+currdiv;
	    }
	  }
	  break;
	}
      }
    }
    if(!found)
    int j = B.size()-1;
    while(j>=0){
    int currgcd = __gcd(A[i],B[B.size()-1]);
    if(currgcd >maxgcd){
      maxgcd = currgcd;
      maxsum = A[i] + B[B.size()-1];
    }else if(currgcd == maxgcd){
      maxsum = max(maxsum, A[i]+B[B.size()-1]);
    }
      
 
    i--;
	  
  }
  return maxsum;
}
    

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  for(int A_i = 0; A_i < n; A_i++){
    cin >> A[A_i];
  }
  vector<int> B(n);
  for(int B_i = 0; B_i < n; B_i++){
    cin >> B[B_i];
  }
  int res = maximumGcdAndSum(A, B);
  cout << res << endl;
  return 0;
}
