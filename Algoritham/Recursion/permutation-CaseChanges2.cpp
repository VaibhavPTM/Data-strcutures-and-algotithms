#include <iostream>
#include <string>
using namespace std;
void solve(string op, string in)
{
    if (in == "")
    {
        cout << "\'" << op << "\' | "
             << " ";
        return;
    }
    string op1 = op;
    string op2 = op;
    if (isalpha(in[0]))
    {
        op1.push_back(tolower(in[0]));
        op2.push_back(toupper(in[0]));
        in.erase(in.begin() + 0);
        solve(op1, in);
        solve(op2, in);
    }
    else
    {
        op1.push_back(in[0]);
        in.erase(in.begin() + 0);
        solve(op1, in);
    }
    return;
}
int main()
{
    string in, op = "";
    cout << "Enter the string : ";
    cin >> in;
    solve(op, in);

    return 0;
}