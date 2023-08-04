/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start

// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

// tag: hashmap; time: O(2n) => O(n); space: O(1);
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;

        Node* curr = head;
        while (curr) {
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        
        return m[head];
    }
};

// tag: hashmap; time: O(2n) => O(n); space: O(n);
class MySolution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        Node *copyHead = (head) ? new Node(head->val) : nullptr;
        Node *copyCurr = copyHead;

        unordered_map<Node *, int> indiceMap; // mapping from original node to its index.
        unordered_map<int, Node *> nodes;     // mapping from the index to the copy node.

        // update the first node indice mapping.
        indiceMap[head] = 0;
        nodes[0] = copyHead;

        // create the list linearly first.
        Node *curr = head->next;
        int idx = 1;
        while (curr) {
            Node *next = new Node(curr->val);
            copyCurr->next = next;
            
            indiceMap[curr] = idx;
            nodes[idx] = next;

            curr = curr->next;
            copyCurr = copyCurr->next;
            idx++;
        }

        // update the null pointer indice mapping.
        indiceMap[nullptr] = idx;
        nodes[idx] = nullptr;

        // iterate again to update the random field.
        copyCurr = copyHead;
        curr = head;
        while (curr) {
            int idx = indiceMap[curr->random];
            copyCurr->random = nodes[idx];
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return copyHead;
    }
};
// @lc code=end

