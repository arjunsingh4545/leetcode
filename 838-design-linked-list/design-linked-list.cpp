class LinkedListNode {
public:
    int data;
    std::unique_ptr<LinkedListNode> next;

    LinkedListNode(int data) : data(data), next(nullptr) {}
};

class MyLinkedList {
private:
    std::unique_ptr<LinkedListNode> head;
    LinkedListNode* tail; // raw pointer to tail (non-owning)
    int listSize;

    LinkedListNode* goToIndex(int index) {
        LinkedListNode* curr = head.get();
        for (int i = 0; i < index && curr; ++i)
            curr = curr->next.get();
        return curr;
    }

public:
    MyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    int get(int index) {
        if (index < 0 || index >= listSize) return -1;
        return goToIndex(index)->data;
    }

    void addAtHead(int val) {
        auto newNode = std::make_unique<LinkedListNode>(val);
        if (!head) tail = newNode.get();
        newNode->next = std::move(head);
        head = std::move(newNode);
        listSize++;
    }

    void addAtTail(int val) {
        auto newNode = std::make_unique<LinkedListNode>(val);
        LinkedListNode* newTail = newNode.get();

        if (!head) {
            head = std::move(newNode);
            tail = newTail;
        } else {
            tail->next = std::move(newNode);
            tail = newTail;
        }

        listSize++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > listSize) return;
        if (index == 0) return addAtHead(val);
        if (index == listSize) return addAtTail(val);

        LinkedListNode* prev = goToIndex(index - 1);
        auto newNode = std::make_unique<LinkedListNode>(val);
        newNode->next = std::move(prev->next);
        prev->next = std::move(newNode);
        listSize++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= listSize) return;

        if (index == 0) {
            head = std::move(head->next);
            if (listSize == 1) tail = nullptr;
        } else {
            LinkedListNode* prev = goToIndex(index - 1);
            auto nodeToDelete = std::move(prev->next);
            prev->next = std::move(nodeToDelete->next);
            if (index == listSize - 1) tail = prev;
        }

        listSize--;
    }

    void printList() {
        LinkedListNode* curr = head.get();
        while (curr) {
            std::cout << curr->data << " -> ";
            curr = curr->next.get();
        }
        std::cout << "null\n";
    }
};

