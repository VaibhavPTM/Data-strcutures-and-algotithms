#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
static int n;
int find(vector<int> arr, int num, int f, int l){
    if (f <= l){
        int m = (f + l)/2;
        if(arr[m] == num) return m;
        else if (arr[m] > num) return find(arr, num, f, m-1);
        return find(arr, num, m+1, l);
    }
    return -1;
}
int main()
{
    int b;
    vector<int> arr = {1, 2, 3, 5, 6, 7, 8, 9, 10, 34, 96, 998};
    printf("Enter the element you want to search : ");
    scanf("%d", &b);
    int f = 0, l = arr.size() - 1;
    int index = find(arr, b, f, l);

    index != -1?printf("Your arry index is %d", index):printf("not found");
    return 0;
}
