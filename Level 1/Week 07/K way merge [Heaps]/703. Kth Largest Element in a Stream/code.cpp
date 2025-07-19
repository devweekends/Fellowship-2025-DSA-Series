/*
Approach:

This is a classic problem that can be efficiently solved using a min heap.

1. Use a min heap to maintain the k largest elements.
2. In the constructor:
   - Initialize the heap with the first k elements from nums.
   - For remaining elements, if they're larger than the smallest element in heap, replace it.
3. In the add method:
   - Add the new value to the heap.
   - If heap size exceeds k, remove the smallest element.
   - Return the smallest element in the heap (which is the kth largest).

The key insight is that we only need to keep track of the k largest elements, and the smallest among them will be the kth largest element.

Time Complexity: O(n log k) for constructor, O(log k) for add
Space Complexity: O(k)
*/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        // Keep only k largest elements
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        
        // Return the kth largest element (smallest in our min heap)
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */ 