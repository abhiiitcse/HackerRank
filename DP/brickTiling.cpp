#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <map>
#include <bitset>
#define MAXN 21
#define MAXM 9
#define MOD 1000000007
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
bitset<MAXM> arr[MAXN];
int n,m;
map<string,ll> cache;

void pbs(int n,int m){
  FOR(i,0,n){
    FOR(j,0,m){
      cout<<arr[i][j];
    }
    cout<<endl;
  }
}

struct tile2{
  int rows[4],cols[4];
  tile2(int r1,int c1,int r2,int c2,int r3,int c3,int r4,int c4){
    rows[0] = r1; cols[0] = c1;
    rows[1] = r2; cols[1] = c2;
    rows[2] = r3; cols[2] = c3;
    rows[3] = r4; cols[3] = c4;
  }

  //check if the current row and col will okay for fitting tiles
  bool canFit(int row, int col){
    bool fit = true;
    FOR(i,0,4){
      if((row+rows[i])<0 || (row+rows[i])>=MAXN || (col+cols[i])<0 || (col+cols[i])>=MAXM){
	return false;
      }
      if(arr[row+rows[i]].test(col+cols[i])){
	return false;
      }
    }
    arr[row+rows[0]].set(col+cols[0]);
    arr[row+rows[1]].set(col+cols[1]);
    arr[row+rows[2]].set(col+cols[2]);
    arr[row+rows[3]].set(col+cols[3]);
    return true;
  }

  void removeTile(int row,int col){
    arr[row+rows[0]].reset(col+cols[0]);
    arr[row+rows[1]].reset(col+cols[1]);
    arr[row+rows[2]].reset(col+cols[2]);
    arr[row+rows[3]].reset(col+cols[3]);
  }
};

tile2 tiles[8] = {
  tile2(0, 0, 1, 0, 2, 0, 2, 1),
  tile2(0, 0, 1, 0, 1, -1, 1, -2),
  tile2(0, 0, 0, 1, 1, 1, 2, 1),
  tile2(0, 0, 1, 0, 0, 1, 0, 2),
  tile2(0, 0, 1, 0, 2, 0, 2, -1),
  tile2(0, 0, 0, 1, 0, 2, 1, 2),
  tile2(0, 0, 0, 1, 1, 0, 2, 0),
  tile2(0, 0, 1, 0, 1, 1, 1, 2)
};

string getHash(void){
  stringstream ss;
  FOR(i,0,MAXN){
    ss<<hex<<arr[i];
  }
  return ss.str();
}


ll getMyCount(int emptyCount){
  ll result = 0;
  bool empty = false;
  if((emptyCount%4)!=0){
    return 0;
  }

  FOR(i,0,MAXN){
    FOR(j,0,MAXM){
      if(!arr[i].test(j)){
	empty = true;
	FOR(t,0,8){
	  if(tiles[t].canFit(i,j)){
	    ll combinations = 0;
	    string hashval = getHash();
	    if(cache.find(hashval)!=cache.end()){
	      combinations = cache.at(hashval);
	    }else{
	      combinations = getMyCount(emptyCount);
	      cache[hashval] = combinations;
	    }
	    result += combinations;
	    tiles[t].removeTile(i,j);
	  }
	}
	return result;
      }
    }
  }
  if((result==0) && (!empty)){
    return 1;
  }
  return result;
}


int main(){
  int tt;
  cin>>tt;
  FOR(tcase,0,tt){
    FOR(i,0,MAXN){
      FOR(j,0,MAXM){
	arr[i].set(j,1);
      }
    }
    //cout<<arr[0]<<endl;
    cin>>n>>m;
    char c;
    int emptyCount = 0;
    FOR(i,0,n){
      FOR(j,0,m){
	cin>>c;
	if(c!='#'){
	  arr[i].set(j,0);
	  emptyCount++;
	}
      }
    }
    ll result = getMyCount(emptyCount);
    cout<<(result%MOD)<<endl;
  }
  return 0;
}
    
