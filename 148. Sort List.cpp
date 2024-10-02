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
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has one element, it's already sorted
        if (!head || !head->next) {
            return head;
        }
        
        // Step 1: Find the middle of the list
        ListNode* mid = getMiddle(head);
        ListNode* nextToMid = mid->next;
        mid->next = nullptr; // Split the list into two halves

        // Step 2: Recursively sort the two halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(nextToMid);

        // Step 3: Merge the sorted halves
        return merge(left, right);
    }

private:
    // Function to find the middle node of the linked list
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // slow is the middle node
    }

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        // Create a dummy node to simplify the merge process
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        // If there are remaining nodes in left or right, append them
        if (left) {
            tail->next = left;
        } else {
            tail->next = right;
        }

        return dummy.next; // Return the merged list
    }
};
