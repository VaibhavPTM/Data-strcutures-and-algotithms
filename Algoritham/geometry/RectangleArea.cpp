// Link : https://leetcode.com/problems/rectangle-area/
#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define si set<int>
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int>, grater<int>>
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define mod 1000000007
#define endl "\n"
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int r1 = ((ax2 - ax1) * (ay2 - ay1)) + ((bx2 - bx1) * (by2 - by1));
    int r2;
    if (ax2 <= bx1 || ax1 >= bx2 || ay1 >= by2 || ay2 <= by1)
        r2 = 0;
    else{
        r2 = (min(bx2, ax2) - max(bx1, ax1)) * (min(by2, ay2) - max(by1, ay1));
    }
    return r1 - r2;
}
int main()
{
    // Constraints:
    // -104 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 104

    int ax1,ax2,ay1,ay2,bx1,bx2,by1,by2;
    cin>>ax1>>ax2>>ay1>>ay2>>bx1>>bx2>>by1>>by2;
    cout<<computeArea(ax1,ax2,ay1,ay2,bx1,bx2,by1,by2);

    return 0;
}