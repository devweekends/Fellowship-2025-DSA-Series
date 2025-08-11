/*  
///Understanding
We are given a sorted 2D matrix:
Each row is sorted in ascending order.
The first element of each row is greater than or equal to the first element of the previous row (the whole matrix is row-wise sorted).
We need to check if a target value exists in the matrix.
We can solve this efficiently using two binary searches:
Outer Binary Search — to find the potential row where the target may be present.
Inner Binary Search — to search for the target in that selected row.


////Approach
Outer Binary Search (on rows):
Initialize BigLeft = 0, BigRight = total rows - 1.
Calculate mid row.
If the target is less than the first element of the mid row → move up (BigRight = mid - 1).
If the target is greater than the last element of the mid row → move down (BigLeft = mid + 1).
If the target lies between the first and last elements of the mid row → apply inner binary search in this row.
Inner Binary Search (on columns in the selected row):
Initialize left = 0, right = last index of row.
While left <= right:
Calculate innerMid.
If matrix[mid][innerMid] == target → return true.
If the element is greater than target → move left (right = innerMid - 1).
If the element is less than target → move right (left = innerMid + 1).
If loop finishes without finding the target → return false.
If the outer search also finishes without finding any match → return false.

*/


// ```
// //Template

// int Bigleft=0;
// int BogRight=size-1;


// while(BigLeft <= BigRight)
// {
  
//  calculate mid
//  if(arr[mid][0]<target>arr[mid][size-1])   // if no is between in subarray
//  {
   
//   //binary search  
  
  
//   return false;// if no not exist in subarray
   
   
//  }
//  else if (arr[mid][0]>target && arr[mid][lastIndex]>target)
//  {
//    // move right  => mid -1
//  }
//  else()
//  {
//    //move left to mid +1 
//  }
 
// }



// return false; //if no is between subarray but actaul not
// ```




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int BigLeft=0;
        int BigRight=matrix.size()-1;

        while(BigLeft <= BigRight)
        {
            //calculate Mid 
            int mid=(BigLeft+BigRight)/2;
            int lastIndex= matrix[mid].size()-1;
   


            if(matrix[mid][0]<= target && matrix[mid][lastIndex] >=target)
            {
              int left =0;
              int right = lastIndex;
              while(left <= right )
              {
               int innerMid= (left+right)/2;
                 cout<<matrix[mid][innerMid];

               if(matrix[mid][innerMid]==target)
               {  
                    return true;
                }
              
               else if(matrix[mid][innerMid]>target)
               {
                right = innerMid-1;
               }
               else
               {
                left=innerMid+1;
               }
              }//inner while 


              return false;

            }// if target in  mid sub array


            else if(matrix[mid][0]>target)
            {
               BigRight=mid-1;
            }
            else
            {
                BigLeft=mid+1;
            }

        }//Outer Array while -> 


        return false;
    }
};

















//previous Approch 

/*
Approach: Binary Search on Flattened 2D Matrix

Problem:
- Given a 2D matrix where:
  - Integers in each row are sorted in ascending order.
  - The first integer of each row is greater than the last integer of the previous row.
- We need to determine if a given `target` exists in the matrix using O(log (m × n)) time.

Steps:

1. **Edge Case Check**:
   - If the matrix is empty (`rows == 0`), return `false`.

2. **Flatten the Matrix**:
   - Convert the 2D matrix into a 1D array called `flat` using nested loops.
   - This helps treat the 2D matrix like a simple sorted array.

3. **Apply Binary Search**:
   - Set `low = 0` and `high = flat.size() - 1`.
   - While `low <= high`:
     - Calculate `mid = (low + high) / 2`.
     - If `flat[mid] == target`: return `true`.
     - If `flat[mid] < target`: move right → `low = mid + 1`.
     - Else: move left → `high = mid - 1`.

4. **Return Result**:
   - If not found, return `false`.

Time Complexity: O(log (m × n))  
Space Complexity: O(m × n) (due to flattening into a new array)
*/
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int rows = matrix.size();
//         if (rows == 0)
//             return false;
        
//         int cols = matrix[0].size();

//         vector<int> flat;
//         for (auto& row : matrix) {
//             for (int num : row) {
//                 flat.push_back(num);
//             }
//         }

//         int low = 0;
//         int high = flat.size() - 1;
//         while (low <= high) {
//             int mid = (low + high) / 2;
//             if (flat[mid] == target){
//                 return true;
//             }
//             else if (flat[mid] < target){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }
//         return false;
//     }
// };
