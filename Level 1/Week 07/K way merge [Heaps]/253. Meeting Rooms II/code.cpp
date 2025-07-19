/*
Approach:

This problem can be solved using a min heap to track the end times of ongoing meetings.

1. Sort the intervals by start time.
2. Use a min heap to keep track of the end times of meetings that are currently in progress.
3. For each interval:
   - If the current meeting starts after the earliest ending meeting (heap top), we can reuse that room.
   - Remove the earliest ending meeting from the heap.
   - Add the current meeting's end time to the heap.
4. The size of the heap at any point represents the number of rooms needed.

The key insight is that we only need to track when meetings end, not which specific room they use.

Time Complexity: O(n log n) for sorting + O(n log n) for heap operations = O(n log n)
Space Complexity: O(n) for the heap
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        // Min heap to track end times of ongoing meetings
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Add the first meeting's end time
        minHeap.push(intervals[0][1]);
        
        // Process remaining meetings
        for (int i = 1; i < intervals.size(); i++) {
            // If current meeting starts after the earliest ending meeting, reuse that room
            if (intervals[i][0] >= minHeap.top()) {
                minHeap.pop();
            }
            
            // Add current meeting's end time
            minHeap.push(intervals[i][1]);
        }
        
        // The size of heap represents the number of rooms needed
        return minHeap.size();
    }
}; 