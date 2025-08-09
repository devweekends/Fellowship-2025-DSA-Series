class Solution {
     // Helper to find the maximum element in the array
    int findMax(const vector<int>& v) {
        int maxVal = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            maxVal = max(maxVal, v[i]);
        }
        return maxVal;
    }

    // Helper to calculate total hours needed at a given eating speed
    long long int calculateTotalHours(const vector<int>& v, int hourly) {
        long long int totalHours = 0;
        for (int i = 0; i < v.size(); i++) {
            totalHours += ceil((double)v[i] / hourly);
        }
        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        
        while (low <= high) {
            int mid = (low + high) / 2;
            long long int totalH = calculateTotalHours(piles, mid);
            
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};