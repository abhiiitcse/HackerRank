#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

long buyMaximumProducts(int n, long k, vector <long> a) {
  vector<pair<long,long> > vec;
  FOR(i,0,n){
    vec.push_back(make_pair(a[i],i+1));
  }
  sort(vec.begin(),vec.end());
  long total_p = 0;
  FOR(i,0,n){
    total_p += min(vec[i].second, k/vec[i].first);
    k -= vec[i].first*min(1LL*vec[i].second,(k/vec[i].first));
  }
  return retval;
}

int main() {
    int n;
    cin >> n;
    vector<long> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long k;
    cin >> k;
    long result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
    return 0;
}
