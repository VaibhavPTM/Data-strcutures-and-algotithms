// Link : https://codeforces.com/problemset/problem/1553/D
// Topic : dp, greedy, strings, two pointers - 1500	
#include<bits/stdc++.h>
using namespace std;

bool backspace(string s, string t){
    int n = s.size();
    int m = t.size();
    int i = n-1;
    bool flg = true;
    for(int j = m-1; j >= 0; j--){
        while(i >= 0 && s[i] != t[j]){
            i -= 2;
        }
        if(i < 0){
            flg = false;
            break;
        }
        i--;
    }
    return flg;
}

int main(){
    // https://codeforces.com/contest/1553/submission/123846958
    int n;
    cin>>n;
    while(n--){
        string s, t;
        cin>>s>>t;
        if(backspace(s,t)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}