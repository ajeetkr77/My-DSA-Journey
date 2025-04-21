*********************************************************

 Time Complexity : O(N)

Space Complexity : O(N)

******************************************************************

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> list;

        ListNode* temp = head;

        while(temp != nullptr){
            list.push_back(temp->val);
            temp = temp->next;
        }

        int n = list.size();

        int index = 0;

        while( index + k <= n ){
            reverse(list.begin() + index, list.begin() + index + k);
            index += k;
        }

        ListNode *head1 = new ListNode(list[0]);

        temp = head1;

        for(int i = 1; i < n; i++){  
            ListNode* node = new ListNode(list[i]);
            temp->next = node;
            temp = temp->next;
        }

        return head1;
    }
};


****************************************************************

Time Complexity : O(N^2)

Space Complexity : O(1)

*************************************************************

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count=0;
        ListNode* curr, *headNew=nullptr;
        ListNode* dummy= new ListNode(-1);
        dummy->next=head;
        if(left==right)
            return head;
        head=dummy;
        while(head){
            if(count==left-1){
                ListNode *left=head;
                head=head->next;
                left->next=nullptr;
                count++;
                while(count<=right){
                    curr=head;
                    head=head->next;
                    curr->next=headNew;
                    headNew=curr;
                    count++;
                }
                left->next=headNew;
                while(headNew->next!=nullptr){
                    headNew=headNew->next;
                }
                headNew->next=head;
                break;
            }
            count++;
            head=head->next;
        }
        return dummy->next;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int n = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            n ++;
            temp = temp->next;
        }
        
        int index = 1; 

        while( index + k - 1 <= n ){
            head = reverseBetween(head, index, index + k - 1);
            index = index + k;
        }

        return head;
    }
};
