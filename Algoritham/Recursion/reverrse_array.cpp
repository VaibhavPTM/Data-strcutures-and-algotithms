#include <iostream>
#include <vector>
using namespace std;

void insert_Lats_elem(vector<int> &v, int t)
{
    // Here we use recurtion to set the last element
    if (v.size() == 0 || v[0] <= t) // Base condition
    {
        v.insert(v.begin(), t);
        return;
    }
    int t1 = v[v.size() - 1];
    v.pop_back();

    insert_Lats_elem(v, t); // Hypothesis

    
    v.push_back(t1);
}
void sort(vector<int> &v)
{
    // Base condition
    if (v.size() == 1)
    {
        return;
    }

    int temp = v[v.size() - 1]; // Induction
    v.pop_back();
    sort(v);
    insert_Lats_elem(v, temp); // Hypothesis
}
int main()
{
    vector<int> v = {10, 15, 5, 18, 14, 21, 3};
    sort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}