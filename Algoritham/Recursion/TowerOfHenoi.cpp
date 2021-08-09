#include <iostream>
using namespace std;
void solve(int n, int s, int d, int h, int &a)
{
    if (n == 1)
    {
        cout << "moving " << n << " plate " << s << " to " << d << endl;
        a++;
        return;
    }
    solve(n - 1, s, h, d, a);
    cout << "moving " << n << " plate " << s << " to " << d << endl;
    a++;
    solve(n - 1, h, d, s, a);
    return;
}
int main()
{
    int n, cont=0;
    cout << "Enter n : ";
    cin >> n;
    int s = 1, h = 2, d = 3; //moving plat numbers
    solve(n, s, d, h, cont);
    cout<<"number of steps is : "<<cont;
    return 0;
}