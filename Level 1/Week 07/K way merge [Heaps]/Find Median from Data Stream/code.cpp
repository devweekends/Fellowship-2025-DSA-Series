/*
Approach:

Use two heaps:
- Max heap for lower half
- Min heap for upper half

Balance the heaps so their sizes differ by at most one. Median is either the top of one heap or the average of the tops.

Time Complexity: O(log n) per insertion, O(1) for median
Space Complexity: O(n)
*/

#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap; // lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // upper half
public:
    MedianFinder() {}
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        // Balance
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
    }
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
}; 