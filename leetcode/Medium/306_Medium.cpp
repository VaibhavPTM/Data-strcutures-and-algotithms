// Link : https://leetcode.com/problems/additive-number/
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
bool help(string n1, string n2, string num, bool found)
{
    if (found && num.size() == 0)
    {
        return true;
    }
    long long int num1 = stol(n1);
    long long int num2 = stol(n2);
    long long int num3 = num1 + num2;
    string n3 = to_string(num3);
    if (n3 == num.substr(0, n3.size()))
    {
        return help(n2, n3, num.substr(n3.size()), true);
    }
    return false;
}
bool isAdditiveNumber(string num)
{
    if (num.size() < 2)
        return false;
    for (int i = 1; i < num.size() - 1; i++)
    {
        string n1 = num.substr(0, i);
        long long int num1 = stol(n1);
        if (to_string(num1) != n1)
            return false;

        for (int j = i; j < num.size(); j++)
        {
            string n2 = num.substr(i, j - i + 1);
            long long int num2 = stol(n2);
            bool found = help(n1, n2, num.substr(j + 1), false);
            if (found && to_string(num2) == n2)
                return true;
        }
    }
    return false;
}
int main()
{
    // Constraints:
    //     num consists only of digits '0'-'9'.
    //     1 <= num.length <= 35
    return 0;
}