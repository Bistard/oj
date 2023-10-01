struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenHead = new ListNode();
        ListNode *oddHead = new ListNode();

        bool currEven = false;
        ListNode *evenTail = evenHead;
        ListNode *oddTail = oddHead;

        while (head) {
            
            if (currEven) {
                evenTail->next = head;
                if (evenTail->next) evenTail = evenTail->next;
            } else {
                oddTail->next = head;
                if (oddTail->next) oddTail = oddTail->next;
            }

            currEven ^= 1;
            head = head->next;
        }

        // cut the duplicate
        evenTail->next = nullptr;
        
        // try to append evenHead behind the oddHead
        if (evenHead->next) {
            if (oddHead->next) {
                oddTail->next = evenHead->next;
            } else {
                return evenHead->next;
            }
        }
 
        return oddHead->next;
    }
};