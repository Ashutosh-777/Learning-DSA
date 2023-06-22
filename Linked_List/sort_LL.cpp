/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 void swap_nodes(ListNode** head_ref, ListNode* node1, ListNode* node2) {
    if (node1 == node2) {
        return;
    }
 
    ListNode* prev1 = nullptr;
    ListNode* current_node = *head_ref;
    while (current_node != nullptr && current_node != node1) {
        prev1 = current_node;
        current_node = current_node->next;
    }
 
    ListNode* prev2 = nullptr;
    current_node = *head_ref;
    while (current_node != nullptr && current_node != node2) {
        prev2 = current_node;
        current_node = current_node->next;
    }
 
    if (current_node == nullptr) {
        return;
    }
 
    if (prev1 == nullptr) {
        *head_ref = node2;
    } else {
        prev1->next = node2;
    }
 
    if (prev2 == nullptr) {
        *head_ref = node1;
    } else {
        prev2->next = node1;
    }
 
    ListNode* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}
ListNode* Solution::insertionSortList(ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }
    ListNode* newNode = new ListNode(INT_MIN);
    newNode->next=head;
    head = newNode;
    ListNode* prev = head;
    ListNode* next = head->next;
    ListNode* temp = head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    length--;
    while(length--){
        while(next!=NULL){
        if(prev->val>next->val){
            swap_nodes(&head,prev,next);
           next = prev->next;
        }else{
            prev=prev->next;
            next=prev->next;
        }
        }
        prev = head;
        next=prev->next;
    }
    return head->next;
}
