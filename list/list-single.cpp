#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int val, Node* nxt = nullptr): value(val), next(nxt) {}
};

class List {
private:
    Node* head;

public:
    List();
    List(const List&);
    ~List();
    List &operator=(const List &);
    void insertAtBeginning(const int&);
    void insertAtEnd(const int&);
    void insertAtPosition(const int&, const int&);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(const int&);
    void print() const;
    void clear();
    bool empty() const;
};

List::List(): head(nullptr) {}

List::List(const List& other): head(nullptr) {
    Node* current = other.head;

    while (current) {
        insertAtEnd(current->value);
        current = current->next;
    }
}

List::~List() {
    clear();
}

List& List::operator=(const List& other) {
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

void List::insertAtBeginning(const int& x) {
    Node* new_node = new Node(x, head);
    head = new_node;
}

void List::insertAtEnd(const int& x) {
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

void List::insertAtPosition(const int& x, const int& position) {
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

void List::deleteFromBeginning() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void List::deleteFromEnd() {
    if (!head) {
        cout << "List is empty\n";
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

void List::deleteFromPosition(const int& position) {
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

void List::print() const {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }

    cout << "\n";
}

void List::clear() {
    while (head) {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}

bool List::empty() const {
    return head == nullptr;
}

int main() {
    List l;
    
    l.insertAtEnd(20);
    l.insertAtEnd(30);
    l.insertAtBeginning(10);
    l.insertAtPosition(40, 3);

    cout << "List after insertions\n";
    l.print();

    l.deleteFromBeginning();
    cout << "Linked list after deleting from beginning\n";
    l.print();

    l.deleteFromEnd();
    cout << "Linked list after deleting from end\n";
    l.print();

    l.deleteFromPosition(1);
    cout << "Linked list after deleting from  position 1\n";
    l.print();

    l.clear();
    cout << "Linked list after clear\n";
    l.print();

    return 0;
}