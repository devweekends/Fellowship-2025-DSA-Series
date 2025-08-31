#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for(int num : nums){
        freq[num]++;
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    
    for(auto& [num, count] : freq){
        minHeap.push({count, num});
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    
    vector<int> result;
    while(!minHeap.empty()){
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    return result;
}
