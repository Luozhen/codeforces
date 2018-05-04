//
// Created by luozhen on 2018/5/4.
//

#ifndef CODEFORCES_LIST_ADD_H
#define CODEFORCES_LIST_ADD_H

#endif //CODEFORCES_LIST_ADD_H

#include "leetcode_lib.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* p1 = l1, *p2 = l2, *res = result;
        int carry = 0;
        while(p1 != NULL && p2 != NULL){
            int tmp = p1->val + p2->val + carry;
            res->next = new ListNode(0);
            res = res->next;
            res->val = tmp % 10;
            carry = tmp / 10;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1 != NULL || p2 != NULL) {
            ListNode* p = p1 != NULL ? p1 : p2;
            while(p != NULL) {
                int tmp = p->val + carry;
                res->next = new ListNode(0);
                res = res->next;
                res->val = tmp % 10;
                carry = tmp / 10;
                p = p->next;
            }
        }
        if(carry){
            res->next = new ListNode(0);
            res = res->next;
            res->val = carry;
        }
        return result->next;
    }
    
    ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2) {
        ListNode preNode(0), *p = &preNode;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preNode.next;
    }
};


void test_func(){
    if(NULL){
        cout << "lalla" << endl;
    }
    else {
        int a[] = {4, 9, 7}, b[1] = {7};
        ListNode *ls1 = createList(a, 3);
        ListNode *ls2 = createList(b, 1);
//    showList(ls1);
//    showList(ls2);
        Solution s = Solution();
        ListNode *res = s.addTwoNumbers(ls1, ls2);
        showList(res);
    }
}