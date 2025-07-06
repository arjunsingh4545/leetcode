class LinkedListNode {
public:
    int data;
    LinkedListNode* next;

    LinkedListNode(int data) : data(data), next(nullptr) {}
};

class MyLinkedList {
private:
    LinkedListNode* head;
    LinkedListNode* tail; // new
    int listSize;

    LinkedListNode* goToIndex(int index) {
        LinkedListNode* curr = head;
        for (int i = 0; i < index && curr; ++i)
            curr = curr->next;
        return curr;
    }

public:
    MyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    int get(int index) {
        if (index < 0 || index >= listSize) return -1;
        return goToIndex(index)->data;
    }

    void addAtHead(int val) {
        LinkedListNode* newNode = new LinkedListNode(val);
        newNode->next = head;
        head = newNode;
        if (listSize == 0) tail = head; // initialize tail
        listSize++;
    }

    void addAtTail(int val) {
        LinkedListNode* newNode = new LinkedListNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > listSize) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == listSize) {
            addAtTail(val);
            return;
        }

        LinkedListNode* prev = goToIndex(index - 1);
        LinkedListNode* newNode = new LinkedListNode(val);
        newNode->next = prev->next;
        prev->next = newNode;
        listSize++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= listSize) return;

        if (index == 0) {
            LinkedListNode* temp = head;
            head = head->next;
            delete temp;
            if (listSize == 1) tail = nullptr; // clear tail if list is empty
        } else {
            LinkedListNode* prev = goToIndex(index - 1);
            LinkedListNode* nodeToDelete = prev->next;
            prev->next = nodeToDelete->next;
            if (nodeToDelete == tail) tail = prev; // update tail if last node is deleted
            delete nodeToDelete;
        }

        listSize--;
    }


    ~MyLinkedList() {
        while (head) {
            LinkedListNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};
