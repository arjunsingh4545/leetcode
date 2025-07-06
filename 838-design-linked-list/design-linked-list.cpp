class LinkedListNode {
public:
    int data;
    std::shared_ptr<LinkedListNode> next;

    LinkedListNode(int data) : data(data), next(nullptr) {}
};


class MyLinkedList {
private:
    std::shared_ptr<LinkedListNode> head;
    std::shared_ptr<LinkedListNode> tail;
    int listSize;

    std::shared_ptr<LinkedListNode> goToIndex(int index) {
        auto curr = head;
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
        auto newNode = std::make_shared<LinkedListNode>(val);
        newNode->next = head;
        head = newNode;
        if (listSize == 0) tail = head;
        listSize++;
    }

    void addAtTail(int val) {
        auto newNode = std::make_shared<LinkedListNode>(val);
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

        auto prev = goToIndex(index - 1);
        auto newNode = std::make_shared<LinkedListNode>(val);
        newNode->next = prev->next;
        prev->next = newNode;
        listSize++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= listSize) return;

        if (index == 0) {
            head = head->next;
            if (listSize == 1) tail = nullptr;
        } else {
            auto prev = goToIndex(index - 1);
            auto nodeToDelete = prev->next;
            prev->next = nodeToDelete->next;
            if (nodeToDelete == tail) tail = prev;
        }

        listSize--;
    }

    // Smart pointers handle destruction automatically
};
