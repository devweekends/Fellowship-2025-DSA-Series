/*
Approach: Binary Search on Answer — Min Eating Speed (Leetcode: Koko Eating Bananas)

Problem:
- Koko has to eat all bananas in `h` hours.
- Each pile has `piles[i]` bananas.
- She eats at a fixed speed `k` bananas/hour, and must choose the **minimum** `k` such that she can eat all piles in `h` hours.
- The faster she eats, the fewer hours it takes.

Steps:

1. **Helper: findMax()**:
   - Find the maximum pile size; this will be the upper limit of the search space (`high = max(piles)`).
   - This is because any speed > max(pile) is unnecessary (she can eat a pile in 1 hour at most).

2. **Helper: calculatehours()**:
   - For a given eating speed `hours` (k), calculate the **total hours** needed to finish all piles.
   - Use `ceil(pile / k)` to represent the time taken to finish each pile.
   - Use `long long` to prevent overflow.

3. **Binary Search on Answer**:
   - Initialize `low = 1`, `high = max(piles)`.
   - While `low <= high`:
     - Compute `mid` = candidate speed.
     - If the total hours required at speed `mid` is **less than or equal to** `h`, try a slower speed → move left (`high = mid - 1`).
     - Else, speed is too slow → move right (`low = mid + 1`).

4. **Return the Result**:
   - `low` will end up pointing to the smallest valid eating speed.

Time Complexity: O(n * log m)  
- `n` = number of piles  
- `m` = max pile size  
(For each binary search step, we calculate total hours over `n` piles)

Space Complexity: O(1)  
- Only uses a few variables, no extra space used
*/

class Solution {
public:
    int findMax(vector<int> &piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , piles[i]);
        }
        return maxi;
    }

    long long calculatehours(vector<int> &piles , int hours ){
        long long  totalhours = 0;
        int n = piles.size();
        for(int i = 0 ; i<n ;i++){
            totalhours += ceil((double)piles[i] / (double)hours);
        }
        return totalhours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        while(low <= high){
            int mid = (low+high)/2;
            long long totalhours = calculatehours(piles , mid);
            if(totalhours <= h){
                high =  mid -1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
