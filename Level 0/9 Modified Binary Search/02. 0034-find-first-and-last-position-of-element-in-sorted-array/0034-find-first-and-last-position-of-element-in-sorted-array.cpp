class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;

        int left = 0;
        int right = nums.size() - 1;

        int position = -1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target){
                position = mid;
                right = mid - 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        res.push_back(position);
        
        position = -1;

        left = 0;
        right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target){
                position = mid;
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        res.push_back(position);

        return res;
    }
};