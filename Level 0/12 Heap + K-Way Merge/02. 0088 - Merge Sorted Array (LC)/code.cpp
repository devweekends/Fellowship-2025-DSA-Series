#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){ nums1[k] = nums1[i]; i--; }
        else { nums1[k] = nums2[j]; j--; }
        k--;
    }
    while(j >= 0){ nums1[k] = nums2[j]; j--; k--; }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n; if(!(cin>>m>>n)) return 0;
    vector<int> a(m+n), b(n);
    for(int i=0;i<m;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    merge(a,m,b,n);
    for(int x:a) cout<<x<<' ';
    cout<<'\n';
    return 0;
}


