/*
Approach:

To group anagrams from a list of strings, we leverage the property that anagrams share the same characters in a different order.

1. We use a hash map (`unordered_map`) where:
   - The key is the sorted version of the string.
   - The value is a vector of strings that are anagrams of each other.

2. For each string in the input:
   - We create a copy and sort it alphabetically.
   - This sorted string acts as a key to group all its anagrams together in the map.

3. After processing all strings, we extract the grouped anagrams from the map and return them as a vector of vectors.

Time Complexity:
- O(n * k log k), where `n` is the number of strings and `k` is the average length of each string (due to sorting).

Space Complexity:
- O(n * k), for storing the grouped anagrams.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> Groups;

        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());  
            Groups[sortedStr].push_back(s);  
        }

        vector<vector<string>> result;
        for (auto& pair : Groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};
