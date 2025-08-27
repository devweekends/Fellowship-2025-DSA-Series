/*
There are 3 approaches, but we will solve it using a queue because in this repo we are studying queues


Understanding
-------------
Problem:
- Given an array 'tickets' where tickets[i] = number of tickets the i-th person wants.
- Index 'k' = target person.
- Each person buys 1 ticket per second, and after buying 1 ticket, goes back to the 
  end of the line if they have more tickets.
- Goal: Find total time (seconds) for person at index 'k' to finish buying all tickets.

Observations:
1. Each person contributes to the total time depending on their position relative to 'k'.
2. Target person's total time = their own tickets + contributions from others.
---

SOLUTION 1: Formula-based (O(n) time, O(1) space)
--------------------------------------------------
approch:
- Identify target person at index k with tickets[k] tickets.
- Total time = target person's own tickets + contribution of all other people.
- Contribution rules:
  1. If i <= k → person i will be in line until target finishes last ticket 
     → contribution = min(tickets[i], tickets[k])
  2. If i > k → person i may not reach the last round after target finishes 
     → contribution = min(tickets[i], tickets[k]-1)
- Sum all contributions → total time for target to finish buying tickets.
- This avoids simulating the entire queue and gives O(n) time.

Time Complexity: O(n) → single pass over tickets array.
Space Complexity: O(1) → only variables used (result, loop counter).

*/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int result=0;
        for(int i=0;i<tickets.size();i++)
        {
            if(i<=k)
                result += min(tickets[k], tickets[i]);
            else
                result += min(tickets[k]-1, tickets[i]);
        }
        return result;
    }
};

/*
Example:
tickets = [2,3,2], k=2
Target tickets = 2

Index 0: min(2,2)=2
Index 1: min(3,2)=2
Index 2: min(2,2)=2
Total time = 2+2+2=6
*/

/*
---

SOLUTION 2: Queue-based simulation (O(n*m) time, O(n) space)
--------------------------------------------------------------
approch:
- Use a queue to store (index, remaining tickets) of each person.
- Each second, person at front buys 1 ticket:
    1. decrement remaining tickets
    2. increment time
    3. if remaining > 0 → push back to queue
    4. if remaining == 0 and person is target → return time
- This is a literal simulation of the queue buying process.

Time Complexity: O(n * m) → worst case every person buys ticket in multiple rounds.
Space Complexity: O(n) → queue stores up to n people at a time.

*/
class Solution2 {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int, int>> q;

        for (int i = 0; i < tickets.size(); i++) {
            q.push({i, tickets[i]});
        }

        int time = 0;

        while (!q.empty()) {
            auto [pos, remain] = q.front();
            q.pop();
            remain--;
            time++;
            if (remain > 0) {
                q.push({pos, remain});
            }
            if(pos==k && remain == 0)
                return time;
        }
        return time;
    }
};

/*
---

SOLUTION 3: Circular Simulation / Direct Array Modification (O(n*m) time, O(1) space)
----------------------------------------------------------------------------------------
approch:
- Use two variables: 'sec' = total seconds, 'i' = current person index.
- Loop until target person tickets[k] = 0:
    1. If tickets[i] > 0 → decrement tickets[i], increment sec
    2. Move to next person: i++  
       - If i == tickets.size() → i = 0 (start new round)
- When tickets[k] = 0 → return sec.
- This simulates queue circularly **without extra memory**.

Time Complexity: O(n * m) → worst case loop runs tickets[k] * n times.
Space Complexity: O(1) → only counters used, tickets array modified in-place.

*/
class Solution3 {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sec = 0;
        int i = 0;

        while (tickets[k] != 0) {
            if (tickets[i] > 0) {  
                tickets[i]--; 
                sec++;
            }
            i++;
            if (i == tickets.size()) i = 0; // complete a round
        }
        return sec;
    }
};

/*
---
Time & Space Complexity:

| Approach                  | Time Complexity | Space Complexity |
|----------------------------|----------------|----------------  |
| Formula-based              | O(n)           | O(1)             |
| Queue simulation           | O(n*m)         | O(n)             |
| Circular array simulation  | O(n*m)         | O(1)             |


*/
