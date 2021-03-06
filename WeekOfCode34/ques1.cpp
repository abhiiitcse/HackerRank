#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

pii get_half_num(int num){
    pii result;
    int first_half = 0,second_half = 0;
    for(int i=0;i<3;i++){
        first_half += ((10*first_half) + (num%10));
        num /= 10;
    }
    for(int i=0;i<3;i++){
        second_half += ((10*second_half) + (num%10));
        num /= 10;
    }
    result.first = first_half;
    result.second = second_half;
    return result;
}

bool isEqual(int x){
    int first_half_sum = 0;
    int second_half_sum = 0;
    for(int i=0;i<3;i++){
        second_half_sum += (x%10);
        x = x/10;
    }
    for(int i=0;i<3;i++){
        first_half_sum += (x%10);
        x = x/10;
    }
    if(first_half_sum == second_half_sum){
        return true;
    }
    return false;
}

string onceInATram(int x) {
    // Complete this function
    string result="";
    bool found = false;
    int next_num = 0;
    for(int i=x+1;i<=999999;i++){
        if(isEqual(i)){
            found = true;
            next_num = i;
            break;
        }
    }
    if(found){
      result = to_string(next_num);
    }
    return result;
}

int main() {
    int x;
    cin >> x;
    string result = onceInATram(x);
    cout << result << endl;
    return 0;
}

