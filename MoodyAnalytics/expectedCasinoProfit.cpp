#include <bits/stdc++.h>

using namespace std;

double getProfit(int n, int x, int m, vector<int> money, vector<int> prob){
  vector<int> profit;
  int total_investment = m*x;
  double result = 0.0;
  for(int i=0;i<n;i++){
    int prof = (total_investment - m*money[i])*prob[i];
    result += ((double)(prof));
  }
  result = result / 100.0;
  return result;
}

int main() {
    int n;
    int x;
    int m;
    vector<int> money;
    vector<int> prob;
    cin >> n >> x >> m;
    for(int a0 = 0; a0 < n; a0++){
        int w;
        int p;
        cin >> w >> p;
	money.push_back(w);
	prob.push_back(p);
    }
    cout<<getProfit(n,x,m,money,prob)<<endl;
    return 0;
}

