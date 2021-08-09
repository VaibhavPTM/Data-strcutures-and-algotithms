#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1 , n = -1;
        std::vector<int> arr;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target == nums[mid]){
                n = mid;
                end = mid - 1;
            }
            else if(target < mid){
                end = mid - 1;
                
            }
            else{
                start = mid +1;
            }
        }
        if(n==-1){
            arr.push_back(-1);
            arr.push_back(-1);
            return arr;
        } 
        else if(nums.size()==1 && n!=-1){
            arr.push_back(n);
            arr.push_back(n);
            return arr;
        }
        while(nums[n] == target){
            arr.push_back(n);
            n++;
            if(n==nums.size())
                break;
        }
        if(arr.size()==1){
            arr.push_back(arr[0]);
        }
        return arr;
    }
int main()
{
    vector<int> nums = {3,3,3};
    int target = 3;
    vector<int> ans =searchRange(nums,target); 
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}