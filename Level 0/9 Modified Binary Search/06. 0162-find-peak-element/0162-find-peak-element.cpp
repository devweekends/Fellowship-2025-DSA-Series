class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid is less than mid + 1, the peak must be on the right side
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                // Peak is on the left side or could be mid itself
                right = mid;
            }
        }

        // Left and right converge to the peak
        return left;
    }
};


// Approach 1

// int findPeakElement(vector<int>& nums) {
//     int left = 0;
//     int right = nums.size() - 1;
//     while(left <= right){
//         int mid = left + (right - left) / 2;
//         if(mid > 0 && mid < nums.size() - 1){
//             if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
//                 return mid;
//             }else if(nums[mid - 1] > nums[mid]){
//                 right = mid - 1;
//             }else{
//                 left = mid + 1;
//             }
//         }else if(mid == 0){
//             if(nums[0] > nums[1]){
//                 return 0;
//             }else{
//                 return 1;
//             }
//         }else{
//             if(nums[nums.size() - 1] > nums[nums.size() - 2]){
//                 return nums.size() - 1;
//             }else{
//                 return nums.size() - 2;
//             }
//         }
//     }
//     return 0;
// }