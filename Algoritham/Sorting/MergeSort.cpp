#include<bits/stdc++.h>
using namespace std;
#define print(T) for(int &i : T) cout << i << " ";
#define lli long long int
#define vec(int) vector<int>


void Merge(int ar[],int tmp[], int l, int mid, int r) {
    int t = l, left_end = mid-1, size = r - l + 1;
    while(l <= left_end && mid <= r) {
        if(ar[l] <= ar[mid]) {
            tmp[t++] = ar[l++];
        }
        else {
            tmp[t++] = ar[mid++];
        }
    }
    while(l <= left_end) {
        tmp[t++] = ar[l++];
    }
    while(mid <= r) {
        tmp[t++] = ar[mid++];
    }
    for(int i = 0; i <= size; i++) {
        ar[r] = tmp[r];
        r--;
    }
}
void MergeSort(int ar[],int tmp[], int l, int r) {
    if(l < r) {
        int mid = (l+r) / 2;
        
        MergeSort(ar,tmp,l,mid);
        MergeSort(ar,tmp,mid+1,r);
        Merge(ar,tmp,l, mid+1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cout << "Enter the array size : " << endl;
    cin >> n;
    int ar[n], tmp[n+1];
    cout << "Enter the elements : ";
    for(int &i : ar) {
        cin >> i;
    }

    MergeSort(ar,tmp,0,n-1);
    print(ar);

    
    return 0;
}