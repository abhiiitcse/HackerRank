#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second


const int maxn = (int)1e5+5;
int a[maxn];

typedef unsigned int uint;

uint dp[1<<22], closure[1<<16];


int main(){
  int n;
  assert(scanf("%d", &n) != -1);
  int MV = 0;
  for (int i = 0; i < n; i++){
    assert(scanf("%d", &a[i]) != -1);
    MV = max(MV, a[i]);
  }
  int z = 0;
  while ((1<<z) <= MV) z++;
  cout<<"MV="<<MV<<endl;
  cout<<"Z="<<z<<endl;

  for (int i = 0; i < (1<<16); i++)
    {
      uint res = 0;
      for (int j = 0; j < 32; j++)
        {
	  if ((uint)i & ((uint)1 << j)) res |= (uint)1 << j;
	  for (int k = 0; k < 5; k++)
	    if ((j & (1<<k)) && (res & ((uint)1<<(j^(1<<k)))))
	      res |= (uint)1 << j;                
        }
      closure[i] = res;
    }
  for(int i=0;i<10;i++){
    cout<<closure[i]<<" ";
  }
  cout<<endl;

  pii ans = mp(100, (int)1e9);
  for (int i = 0; i < n; i++)
    dp[a[i]>>5] |= (uint)1 << (a[i]&31);
  z = max(z, 5);
  for (int i = 0; i < (1<<(z-5)); i++)
    {
      for (int j = 0; j < z-5; j++)
	if (i & (1<<j))
	  dp[i] |= dp[i ^ (1<<j)];
      dp[i] = closure[dp[i]&uint((1<<16)-1)] | ((closure[dp[i]>>16] & (((uint)1 << 16)-(uint)1)) << 16);
      for (int j = 0; j < 32; j++)
	if (!(dp[i]&((uint)1<<j))) 
	  ans = min(ans, mp(z-__builtin_popcount((i<<5)|j), ((1<<z)-1)^(i<<5)^j));
    }
  cout << ans.Y << endl;
  return 0;
}
