#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeKLists(vector<ListNode*>& lists) {
    struct Cmp { bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; } };
    priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
    for (auto node : lists) if (node) pq.push(node);
    ListNode dummy(0), *tail = &dummy;
    while (!pq.empty()) {
        ListNode* cur = pq.top(); pq.pop();
        tail->next = cur; tail = cur;
        if (cur->next) pq.push(cur->next);
    }
    return dummy.next;
}


