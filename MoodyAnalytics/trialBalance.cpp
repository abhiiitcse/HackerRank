#include <bits/stdc++.h>

using namespace std;
int k = 0;
int mindiff = INT_MAX;
void getResult(vector<int> d, int n, int diff, int count){
  if(n<0)
    return;
  for(int i=n-1;i>=0;i--){
    int curr_diff = (diff - 2*d[i]);
    if((curr_diff>=0)&&(curr_diff <mindiff)){
      mindiff = curr_diff;
      k = count + 1;
      getResult(d,i,curr_diff,count+1);
    }else{
      getResult(d,i,diff,count);
    }
  } 
}

pair<int,int> getMin(vector<int> d, int first_sum, int n, int tot_sum){
  int init_diff = abs(first_sum - tot_sum )/2;
  sort(d.begin(),d.end());
  int dp[2*tot_sum];
  for(int i=0;i<2*tot_sum;i++){
    dp[i] = INT_MAX;
  }
  dp[0] = 1;
  for(int i=1;i<2*tot_sum;i++){
    for(int j=0;j<n;j++){
      if(d[j]<=i){
	dp[i] = min(dp[i],1+dp[i-d[j]]);
      }
    }
  }
  int act_diff = INT_MAX;
  int i;
  for(i=init_diff;i>0;i--){
    if(dp[i]!=INT_MAX){
      act_diff = abs(first_sum - tot_sum - 2*i);
      break;
    }
  }
  pair<int,int> result ;
  result.first = act_diff;
  result.second = dp[i];
  return result;
}


int solve(int n, int m, vector <int> d, vector <int> c) {
    // Complete this function
  int d_sum = 0;
  int c_sum = 0;
  for(int i=0;i<n;i++){
    d_sum += d[i];
  }
  for(int j=0;j<m;j++){
    c_sum += c[j];
  }
  mindiff = abs(c_sum-d_sum);
  sort(d.begin(),d.end());
  sort(c.begin(),c.end());
  if(c_sum>d_sum){
    getResult(d,n,mindiff,0);
  }else{
    getResult(c,m,mindiff,0);
  }
  cout<<"mindiff="<<mindiff<<endl;
  cout<<"count = "<<k<<endl;
  
  pair<int,int> result = getMin(c,c_sum, n, d_sum);
  cout<<result.first<<endl;
  cout<<result.second<<endl;
  return 0;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> d(n);
    for(int d_i = 0; d_i < n; d_i++){
       cin >> d[d_i];
    }
    vector<int> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    int result = solve(n, m, d, c);
    cout << result << endl;
    return 0;
}

