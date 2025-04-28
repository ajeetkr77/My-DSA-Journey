*****************************************
  
  Naive Approach
  
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

********************************************************
