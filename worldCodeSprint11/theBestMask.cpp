#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std;
int get_num_of_one(int num){
  int result = 0;
  while(num){
    result++;
    num &= (num-1);
  }
  return result;
}

int main(){
  vector<int> vec;
  int n;
  cin>>n;
  FOR(i,0,n){
    int val;
    cin>>val;
    vec.pb(val);
  }
  int result = 0;
  bool visited[n];
  int belongsto[n];
  FOR(i,0,n){
    visited[i] = false;
    belongsto[i] = -1;
  }
  //if(pre_result==0){
  FOR(i,0,27){
    bool found = false;
    FOR(j,0,n){
      if(!visited[j]){
	if(vec[j]&(1<<i)){
	  found = true;
	  visited[j] = true;
	  belongsto[j] = i;
	}
      }
    }
    if(found){
      FOR(j,0,n){
	if(vec[j]&(1<<i)){
	  belongsto[j] = i;
	}
      }
    }
  }
  FOR(i,0,n){
    result |= (1<<belongsto[i]);
  }
  int min_num_of_one = get_num_of_one(result);
  int index = result+1;
  int final_index = result + 1000;
  while(index<final_index){
    int curr_result = index;
    int curr_num_of_one = get_num_of_one(curr_result);
    if(curr_num_of_one < min_num_of_one){
      bool fail = false;
      FOR(i,0,n){
	if(!(vec[i]&curr_result)){
	  fail = true;
	  break;
	}
      }
      if(!fail){
	result = curr_result;
	min_num_of_one = curr_num_of_one;
      }
    }
    index++;
  }
  
  cout<<result<<endl;
  return 0;
}

