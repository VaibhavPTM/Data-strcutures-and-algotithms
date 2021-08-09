// Link : https://leetcode.com/problems/range-sum-query-mutable/
#include <bits/stdc++.h>
using namespace std;
vector<int> st;
vector<int> arr;
int n;
//     Bulid the tree
void buildtree(int si, int ss, int se)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return;
    }
    int mid = ss + (se - ss) / 2;
    // cout<<si<<" ";
    buildtree(si * 2 + 1, ss, mid);
    buildtree(si * 2 + 2, mid + 1, se);
    st[si] = st[si * 2 + 1] + st[si * 2 + 2];
}

//     update the tree
void update2(int si, int ss, int se, int qe, int val)
{
    if (ss == se)
    {
        st[si] = val;
        return;
    }
    int mid = ss + (se - ss) / 2;
    // cout<<si<<" ";
    if (qe <= mid)
        update2(si * 2 + 1, ss, mid, qe, val);
    else
        update2(si * 2 + 2, mid + 1, se, qe, val);
    st[si] = st[si * 2 + 1] + st[si * 2 + 2];
}

//     query answer
int query(int si, int ss, int se, int qs, int qe)
{
    //        out of range
    if (qs > se || qe < ss)
    {
        return 0;
    }
    //         in the range
    if (qs <= ss && qe >= se)
    {
        return st[si];
    }
    int mid = ss + (se - ss) / 2;
    int l = query(si * 2 + 1, ss, mid, qs, qe);
    int r = query(si * 2 + 2, mid + 1, se, qs, qe);
    return l + r;
}

void NumArray(vector<int> &nums)
{
    n = nums.size();
    arr = nums;
    st.resize(n * 4, 0);
    buildtree(0, 0, n - 1);
}

void update(int index, int val)
{
    update2(0, 0, n - 1, index, val);
}

int sumRange(int left, int right)
{
    return query(0, 0, n - 1, left, right);
}

int main()
{
    // Constraints:
    //     1 <= nums.length <= 3 * 104
    //     -100 <= nums[i] <= 100
    //     0 <= index < nums.length
    //     -100 <= val <= 100
    //     0 <= left <= right < nums.length
    //     At most 3 * 104 calls will be made to update and sumRange.

    return 0;
}