#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v)
{
    // Base condition
    if (v.size() == 1)
    {
        return;
    }

    int temp = v[v.size() - 1]; // Hypothesis
    v.pop_back();
    reverse(v);
    // Induction
    v.insert(v.begin(), temp);
}
int main()
{
    vector<int> v = {10, 15, 5, 18, 14, 21, 3};
    reverse(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}