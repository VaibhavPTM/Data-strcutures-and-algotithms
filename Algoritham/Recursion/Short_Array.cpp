#include <iostream>
#include <vector>
using namespace std;
void insert_Lats_elem(vector<int> &v, int t)
{
    // Here we use recurtion to set the last element
    if (v.size() == 0 || v[v.size() - 1] >= t) // Base condition
    {
        v.push_back(t);
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

    int temp = v[v.size() - 1]; // Hypothesis
    v.pop_back();
    sort(v);
    insert_Lats_elem(v, temp); // Induction
}
void print(vector<int> v)
{
    if (v.size() == 1)
    {
        cout << v[0] << " ";
        return;
    }
    int temp = v[v.size() - 1];
    v.pop_back();
    print(v);
    cout << temp << " ";
    return;
}
void delet_midEle(vector<int> &v)
{
    int mid = (v.size()) / 2 + 1;
    if ((v.size() - 1) == mid)
    {
        v.pop_back();
        return;
    }
    int a = v[v.size() - 1];
    v.pop_back();
    delet_midEle(v);
    v.push_back(a);
    return;
}
int main()
{
    vector<int> v = {2, 21, 43, 22, 35, 23};
    sort(v);
    // print(v);
    // delet_midEle(v);
    // cout << endl;
    // print(v);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}