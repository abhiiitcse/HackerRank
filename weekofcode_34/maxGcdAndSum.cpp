#include <bits/stdc++.h>

using namespace std;

int maximumGcdAndSum(vector <int> A, vector <int> B) {
  // Complete this function
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  
}

int main() {
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
