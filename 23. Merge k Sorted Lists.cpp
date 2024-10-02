/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min heap -> smaller value on top
    }
};
class Solution {
public:
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

    // Sab lists ke first nodes ko heap mein daalo
    for (auto list : lists) {
        if (list) {
            pq.push(list);
        }
    }

    // Dummy node to simplify edge cases
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;

    // Jab tak heap empty nahi hota, process karte jao
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();

        // Output list mein node add karo
        current->next = node;
        current = current->next;

        // Agar next node exist karti hai toh heap mein daalo
        if (node->next) {
            pq.push(node->next);
        }
    }

    // Return merged list
    return dummy->next;
    }
};
