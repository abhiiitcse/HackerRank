#include <bits/stdc++.h>

using namespace std;

string solve(int n, vector <int> p, vector <int> d) {
    // Complete this function
  bool isCorr = true;
  for(int i=1;i<n;i++){
    if((p[i]>p[i-1])&&(d[i]<=d[i-1])){
      isCorr = false;
      break;
    }else if((p[i]<p[i-1])&&(d[i]>=d[i-1])){
      isCorr = false;
      break;
    }else if((p[i]==p[i-1])&&(d[i]!=d[i-1])){
      isCorr = false;
      break;
    }
  }
  if(isCorr){
    return "Yes";
  }else{
    return "No";
  }
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int p_i = 0; p_i < n; p_i++){
       cin >> p[p_i];
    }
    vector<int> d(n);
    for(int d_i = 0; d_i < n; d_i++){
       cin >> d[d_i];
    }
    string result = solve(n, p, d);
    cout << result << endl;
    return 0;
}

