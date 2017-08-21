#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> c;
  for(int i=0;i<m;i++){
    int val;
    cin>>val;
    c.push_back(val);
  }
  sort(c.begin(),c.end());
  //for(int i=0;i<c.size();i++){
  //cout<<c[i]<<" ";
  //}
  //cout<<endl;
  vector<int> change(n+1,0);
  change[0] = 1;
  for(int i=0;i<m;i++){
    for(int j=1;j<=n;j++){
      if(j>=c[i]){
	change[j] += change[j-c[i]];
      }
    }
    //cout<<"max change #"<<i<<" = "<<change[i]<<endl;
  }
  cout<<change[n]<<endl;
  return 0;
}
