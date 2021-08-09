#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {3,4,1};
    int n = nums1.size() + nums2.size();
    // sort(nums1.begin(), nums1.end());
    // sort(nums2.begin(), nums2.end());
    vector<double> arr(n);
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), arr.begin());
    sort(arr.begin(),arr.begin()+n);
    
    if (arr.size() % 2 != 0)
        cout<< arr[(arr.size() - 1) / 2];
    else
        cout<< (arr[(arr.size() - 1) / 2] + arr[((arr.size() - 1) / 2) + 1]) / 2;
}