#include <vector>
#include <queue>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    struct Item { int value, i, j; };
    struct Cmp { bool operator()(const Item& a, const Item& b) const { return a.value > b.value; } };
    priority_queue<Item, vector<Item>, Cmp> pq;
    vector<int> result;
    for(int i = 0; i < K; i++) if(!arr[i].empty()) pq.push({arr[i][0], i, 0});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        result.push_back(cur.value);
        int nj = cur.j + 1;
        if(nj < (int)arr[cur.i].size()) pq.push({arr[cur.i][nj], cur.i, nj});
    }
    return result;
}


