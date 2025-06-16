/*
Approach:

The goal is to find the top `k` most frequent elements in the given array.

1. **Count Frequencies**:
   - We use an unordered map (`cnt`) to count the frequency of each element in the array.

2. **Store Frequencies in a Vector**:
   - We create a vector of pairs, where each pair contains `{frequency, number}`.
   - This allows us to sort the elements by frequency.

3. **Sort the Vector**:
   - We sort the vector in descending order based on frequency using `sort(arr.rbegin(), arr.rend())`.

4. **Extract the Top K Elements**:
   - After sorting, the most frequent elements will be at the beginning.
   - We extract the first `k` elements and store their corresponding values in the result vector `res`.

Time Complexity:
- Counting frequencies: O(n)
- Sorting: O(n log n)
- Collecting results: O(k)

Space Complexity:
- O(n) for the frequency map and the pair vector.

This is a simple and effective approach when `n` is not extremely large. For larger datasets, a heap-based or bucket sort approach may be more optimal.

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // I have declared a map here to put the value and increase the count
        unordered_map<int, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }

        // A new vector arr is declared 
        vector<pair<int, int>> arr;
        for (const auto& p : cnt) {
            arr.push_back({p.second, p.first});
        }

        // Sort the vector in descending order of frequency
        sort(arr.rbegin(), arr.rend());

        // The result vector to store and return the answer
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i].second);
        }

        return res;
    }
};
