class MyLinkedList {
    struct ListNode{
            int val;
            ListNode* next;

            ListNode(int val1){
                val = val1;
                next = NULL;
            }
        };
        ListNode* head;
        int size;
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >=size){
            return -1;
        }
        ListNode* temp = head;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }   
        return temp->val;     
    }
    
    void addAtHead(int val) {
        ListNode* newhead = new ListNode(val);
        newhead->next = head;
        head = newhead;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newtail = new ListNode(val);
        if(head == nullptr){
            head = newtail;
            size++;
            return;
        }
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newtail;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index >size){
            return ;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        ListNode* temp = head;
        ListNode* newnode = new ListNode(val);
        for(int i=0; i<index-1; i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >=size){
            return ;
        }
        if(index == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        ListNode* temp = head;
        for(int i=0; i<index-1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */