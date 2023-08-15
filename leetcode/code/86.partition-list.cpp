/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        // initialization
        ListNode *lessHead = new ListNode();
        ListNode *greaterHead = new ListNode();

        ListNode *lessFront = lessHead;
        ListNode *greaterFront = greaterHead;
        
        ListNode *curr = head;
        while (curr) {
            ListNode *currNode = curr->next;
            curr->next = nullptr;

            // < x, we move it to the lessFront.
            if (curr->val < x) {
                lessFront->next = curr;
                lessFront = curr;
            }

            // >= x, we move it to the greaterFront.
            else {
                greaterFront->next = curr;
                greaterFront = curr;
            }

            curr = currNode;
        }
        
        // combine two lists
        lessFront->next = greaterHead->next;
        
        // return the initial
        return lessHead->next;
    }
};
// @lc code=end

