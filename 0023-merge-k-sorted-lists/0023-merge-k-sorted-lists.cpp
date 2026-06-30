struct Compare {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (auto ll : lists) {
            while (ll) {
                pq.push(ll);
                ll = ll->next;
            }
        }

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (!pq.empty()) {
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;
        }

        temp->next = nullptr;

        return dummy.next;
    }
};