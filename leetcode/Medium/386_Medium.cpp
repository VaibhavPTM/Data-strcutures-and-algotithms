// Link : https://leetcode.com/problems/lexicographical-numbers/
// Topic : Lexicographical Numbers
#include <bits/stdc++.h>
using namespace std;
vector<int> res;
void help(int idx, int n){
    if (idx > n)
        return;
    res.push_back(idx);
    for (int i = 0; i <= 9; i++){
        help(idx * 10 + i, n);
    }
}
vector<int> lexicalOrder(int n){
    for (int i = 1; i <= 9; i++)
    {
        help(i, n);
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    lexicalOrder(n);
    for(int i : res){
        cout<<i<<" ";
    }

    return 0;
}