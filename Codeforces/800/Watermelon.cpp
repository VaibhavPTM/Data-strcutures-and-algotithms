// Link : https://codeforces.com/problemset/problem/4/A
// Name : Watermelon (800)
// Topic : brute force, math
#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

string help(int n){
    if(n < 4 || (n & 1) == 1) return "NO";
    else return "YES";
}
int main()
{
    int n;
    cin>>n;
    cout<<help(n);
    
    return 0;
}