// // leetode Problem
#include <iostream>
#define FUN(i,j) i##j
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 1, 1, 3, 4, 4, 4};
    // cout<<FUN(10,20);
    // count the element which is not repeat in given vactor
    int n = arr.size();
    vector<int> v(32, 0);

    for (int e : arr)
    {
        for (int i = 0; i < 32; i++)
            if (e & (1 << i))
            {
                v[i]++;
            }
    }
    int res = 0;
    for (int i = 0; i < 32; i++)
        if (v[i] % 3 == 1)
            res += (1 << i);

    cout<<"answer is : "<<res;

    return 0;
}