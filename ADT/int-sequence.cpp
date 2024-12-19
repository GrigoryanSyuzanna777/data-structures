#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int val, Node* nxt = nullptr): value(val), next(nxt) {}
};

class IntSequence {
private:
    Node* head;

public:
    IntSequence();
    IntSequence(const IntSequence&);
    IntSequence(const int arr[], int size);
    ~IntSequence();
    IntSequence &operator=(const IntSequence &);
    void insertAtBeginning(const int&);
    void insertAtEnd(const int&);
    void insertAtPosition(const int&, const int&);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(const int&);
    void print() const;
    void clear();
    bool empty() const;
    IntSequence& removeAllAppearances(int x);
};

IntSequence::IntSequence(): head(nullptr) {}

IntSequence::IntSequence(const IntSequence& other): head(nullptr) {
    Node* current = other.head;

    while (current) {
        insertAtEnd(current->value);
        current = current->next;
    }
}

IntSequence::IntSequence(const int arr[], int size): head(nullptr) {
    for (int i = 0; i < size; ++i) {
        insertAtEnd(arr[i]);
    }
}

IntSequence::~IntSequence() {
    clear();
}

IntSequence& IntSequence::operator=(const IntSequence& other) {
    if (this != &other) {
        clear();
        Node *current = other.head;
        while (current)
        {
            insertAtEnd(current->value);
            current = current->next;
        }
    }

    return *this;
}

void IntSequence::insertAtBeginning(const int& x) {
    Node* new_node = new Node(x, head);
    head = new_node;
}

void IntSequence::insertAtEnd(const int& x) {
    Node* new_node = new Node(x, nullptr);

    if (!head) {
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next)
        last = last->next;

    last->next = new_node;
}

void IntSequence::insertAtPosition(const int& x, const int& position) {
    if (position < 0) {
        cout << "Position should be >= 0\n";
        return;
    }

    if (position == 0) {
        insertAtBeginning(x);
        return;
    }

    Node* new_node =  new Node(x);

    Node* prev_node = head;
    int k = 0;
    while (k < position - 1 && prev_node) {
        prev_node = prev_node->next;
        ++k;
    }

    if (!prev_node) {
        cout << "Position out of range\n";
        delete new_node;
        return;
    }

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void IntSequence::deleteFromBeginning() {
    if (!head) {
        cout << "IntSequence is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void IntSequence::deleteFromEnd() {
    if (!head) {
        cout << "IntSequence is empty\n";
        return;
    }

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* pre_last = head;
    while (pre_last->next->next) {
        pre_last = pre_last->next;
    }

    delete pre_last->next;
    pre_last->next = nullptr;
}

void IntSequence::deleteFromPosition(const int& position) {
    if (position < 0) {
        cout << "Position should be >= 0\n";
        return;
    }

    if (position == 0) {
        deleteFromBeginning();
        return;
    }

    Node* prev_node = head;
    int k = 0;
    while (k < position - 1 && prev_node) {
        prev_node = prev_node->next;
        ++k;
    }

    if (!prev_node || !prev_node->next) {
        cout << "Position out of range\n";
        return;
    }

    Node* node_to_delete = prev_node->next;
    prev_node->next = node_to_delete->next;
    delete node_to_delete;
}

void IntSequence::print() const {
    if (!head) {
        cout << "IntSequence is empty\n";
        return;
    }

    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }

    cout << "\n";
}

void IntSequence::clear() {
    while (head) {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}

bool IntSequence::empty() const {
    return head == nullptr;
}

IntSequence& IntSequence::removeAllAppearances(int x) {
    Node* current = head;
    int position = 0;
    while (current) {
        if (current->value == x) {
            current = current->next;
            deleteFromPosition(position);
            continue;
        }
        ++position;
        current = current->next;
    }

    return *this;
}

int main() {
    IntSequence s;
    
    s.insertAtEnd(2);
    s.insertAtEnd(3);
    s.insertAtEnd(2);
    s.insertAtEnd(1);
    s.insertAtBeginning(1);
    s.insertAtPosition(4, 3);
    s.insertAtBeginning(1);
    s.insertAtBeginning(3);
    s.insertAtBeginning(4);
    s.insertAtBeginning(3);
    s.insertAtBeginning(2);

    cout << "IntSequence after insertions\n";
    s.print();

    int x = 2;
    s.removeAllAppearances(x);
    cout << "Linked IntSequence after removing all " << x << " values: \n";
    s.print();

    return 0;
}