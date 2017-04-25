#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll get_pow(ll a, ll b){
    ll result = 1;
    while(b){
        if((b%2)!=0){
            result = (result*a)%MOD;
        }
        b = b/2;
        a = (a*a)%MOD;
    }
    return result%MOD;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tt;
    cin>>tt;
    while(tt--){
        ll inp;
        cin>>inp;
        ll powa = get_pow(2,inp+1);
        //ll inpsq = sqrt(powa);
        //ll result = ((inpsq+1)*2)%MOD;
        ll result = (powa+2)%MOD;
        cout<<result<<endl;
    }
    return 0;
}
