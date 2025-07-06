class LinkedListNode {
public:
    int data;
    LinkedListNode* next;

    LinkedListNode(int data) : data(data), next(nullptr) {}
};

class MyLinkedList {
private:
    LinkedListNode* head;
    int listSize;

    LinkedListNode* goToIndex(int index) {
        LinkedListNode* curr = head;
        for (int i = 0; i < index && curr; ++i) {
            curr = curr->next;
        }
        return curr;
    }

public:
    MyLinkedList() : head(nullptr), listSize(0) {}

    int get(int index) {
        if (index < 0 || index >= listSize) return -1;
        LinkedListNode* node = goToIndex(index);
        return node ? node->data : -1;
    }

    void addAtHead(int val) {
        LinkedListNode* newNode = new LinkedListNode(val);
        newNode->next = head;
        head = newNode;
        listSize++;
    }

    void addAtTail(int val) {
        LinkedListNode* newNode = new LinkedListNode(val);
        if (!head) {
            head = newNode;
        } else {
            LinkedListNode* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newNode;
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
        } else {
            LinkedListNode* prev = goToIndex(index - 1);
            LinkedListNode* nodeToDelete = prev->next;
            prev->next = nodeToDelete->next;
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
    }
};
