*****************************************
  
  Naive Approach

  Time Complexity: O(K*N) + O((N*K) * log(N*K)) + O(N*K) where K is the number of linked lists and N is the length of each linked list.

  Space Complexity: O(N*K) + O(N*K) where K is the number of linked lists and N is the length of each linked list.
  
****************************************

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        vector<int> list;

        for(int i = 0; i < n; i++){
            ListNode* temp = lists[i];

            while(temp != nullptr){
                list.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        if(list.size() == 0) 
            return nullptr;

        sort(list.begin(), list.end());

        ListNode *head = new ListNode(list[0]);

        ListNode *temp = head;

        for(int i = 1; i < list.size(); i++){
            temp->next = new ListNode(list[i]);
            temp = temp->next;
        }

        return head;
    }
};

**********************************************

  Better Approach

  T = (N1 + N2) + (N1 + N2 + N3) + .... + (N1 + N2 + N3 + .... + Nk)

For simplification let's assume the length of each linked list to be proportional to N,

T = N + 2N + 3N + 4N + 5N + .... + kN

T = N (1 + 2 + 3 + 4 + ... + k)

The sum of lengths of the lists can be calculated using the formula for the sum of the first N natural numbers:

T = N (k(k+1))/2

Hence, the time complexity is O( N*k(k+1)/2) ~ O(N*k^2)
  
*********************************************

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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }  
            temp = temp->next; 
        }

        if(list1)
            temp->next = list1;
        
        if(list2)
            temp->next = list2;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0) return nullptr;

        ListNode* head = lists[0];

        for(int i = 1; i < n; i++){
            head = merge(head, lists[i]);
        }

        return head;
    }
};


********************************************************

  Optimal Approach

Time Complexity: O(K log K) + O(N*K*(3*log K))where K is the number of linked lists and N is the number of nodes in each list.

O(K log K) as inserting an element into the priority queue takes log K time and is repeated K times for each list head.

Considering there are N nodes in each of the K linked lists, the overall number of nodes to be processed is N * K. For each of these N * K nodes:

Pop: Removing the smallest element (top of the priority queue) takes log K time.
Add: Adding the next element from the same list (when available) also takes log K time.
Access top: Accessing the top of the priority queue for extraction or comparison also takes log K time.
Hence, the total time complexity for the merging process across all nodes is ~ O(N * K * log K).

Space Complexity : O(K) where K is the number of linked lists. The main contributor to space usage is the 
priority queue which holds a node from each of these lists. Regardless of the number of nodes within each list, 
priority queue only holds a reference to one of its nodes at a time hence the space complexity is proportional to the number of input linked lists

********************************************************


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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0) return nullptr;

        // Priority queue to maintain
        // sorted order based on node values
        // Pairs store node value and pointer to the node
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i = 0; i < n; i++){
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            temp->next = it.second;
            temp = temp->next;
            if(it.second->next){
                pq.push({it.second->next->val, it.second->next});
            }
        }

        return dummy->next;

    }
};
