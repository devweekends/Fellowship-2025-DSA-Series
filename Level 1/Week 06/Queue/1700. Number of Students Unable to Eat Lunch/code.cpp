#include <queue>
#include <vector>
using namespace std;

// 🧠 Approach:
// This problem simulates a queue of students trying to get sandwiches.
// 1. Use a queue to represent students and a stack (vector) for sandwiches.
// 2. At each step, check if the front student wants the top sandwich.
// 3. If yes, both student and sandwich are removed.
// 4. If no, student goes to the back of the queue.
// 5. Continue until no more students can get sandwiches (when we've gone through all students without any matches).
// 6. The key insight is to track when we've processed all students without any progress.

// ✅ Time Complexity: O(n²), where n is the number of students
// ✅ Space Complexity: O(n), for the queue

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentQueue;
        
        // Add all students to the queue
        for (int student : students) {
            studentQueue.push(student);
        }
        
        int sandwichIndex = 0;
        int processedWithoutMatch = 0;
        
        while (!studentQueue.empty() && sandwichIndex < sandwiches.size()) {
            int currentStudent = studentQueue.front();
            studentQueue.pop();
            
            if (currentStudent == sandwiches[sandwichIndex]) {
                // Student gets the sandwich
                sandwichIndex++;
                processedWithoutMatch = 0; // Reset counter
            } else {
                // Student goes to the back of the queue
                studentQueue.push(currentStudent);
                processedWithoutMatch++;
                
                // If we've processed all students without any matches, no one can eat
                if (processedWithoutMatch >= studentQueue.size()) {
                    break;
                }
            }
        }
        
        return studentQueue.size();
    }
}; 