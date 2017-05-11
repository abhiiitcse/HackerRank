#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
  int n;
  int result = 0;
  cin>>n;
  vector<int> arr;
  FOR(i,0,n){
    int val;
    cin>>val;
    arr.push_back(val);
  }
  bool removed[102];
  bool passed[102];
  FOR(i,0,102){
    removed[i] = false;
    passed[i] = false;
  }
  bool found = false;
  while(!found){
    int cnt1,cnt2,cnt3;
    bool cnt1_set=false,cnt2_set=false,cnt3_set=false;
    FOR(i,0,n-2){
      if(!passed[i]){
	cnt1 = i;
	cnt1_set = true;
	break;
      }
    }
    FOR(i,cnt1+1,n-1){
      if(!removed[i]){
	cnt2 = i;
	cnt2_set = true;
	break;
      }
    }
    FOR(i,cnt2+1,n){
      if(!removed[i]){
	cnt3 = i;
	cnt3_set=true;
	break;
      }
    }
        
    if(cnt1_set&&cnt2_set&&cnt3_set){
      if((arr[cnt1]<arr[cnt2])&&(arr[cnt2]<arr[cnt3])){
	removed[cnt1] = true;
      }else if((arr[cnt1]>arr[cnt2])&&(arr[cnt2]>arr[cnt3])){
	removed[cnt1] = true;
      }
      passed[cnt1] = true;
    }else{
      found = true;
    }
    //cout<<"cnt1 = "<<cnt1<<" cnt2="<<cnt2<<" cnt3="<<cnt3<<endl;
    //int inp;
    //cin>>inp;
  }

  FOR(i,0,n){
    if(removed[i]){
      result++;
    }
  }
      
  cout<<result<<endl;
  return 0;
}
