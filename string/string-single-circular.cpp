#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* next;

    Node(int val, Node* nxt = nullptr): value(val), next(nxt) {}
};

class String {
private:
    Node* head;

public:
    String();
    String(const char*);
    String(const String&);
    ~String();
    String &operator=(const String &);
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


String::String(): head(nullptr) {}

String::String(const char* other): head(nullptr) {
    char x = other[0];
    int k = 1;

    while (x != '\0') {
        insertAtEnd(x);
        x = other[k++];
    }
}

String::String(const String& other): head(nullptr) {
    Node* current = other.head;

    if (current) {
        insertAtEnd(current->value);
        current = current->next;
    }

    while (current != other.head) {
        insertAtEnd(current->value);
        current = current->next;
    }
}

String::~String() {
    clear();
}

String& String::operator=(const String& other) {
    if (this != &other) {
        clear();
        Node *current = other.head;

        if (current) {
            insertAtEnd(current->value);
            current = current->next;
        }

        while (current) {
            insertAtEnd(current->value);
            current = current->next;
        }
    }

    return *this;
}

void String::insertAtBeginning(const int& x) {
    Node* new_node = new Node(x, head);

    if (!head) {
        new_node->next = new_node;
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    last->next = new_node;
    head = new_node;
}

void String::insertAtEnd(const int& x) {
    Node* new_node = new Node(x, head);

    if (!head) {
        new_node->next = new_node;
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next != head)
        last = last->next;

    last->next = new_node;
}

void String::insertAtPosition(const int& x, const int& position) {
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

void String::deleteFromBeginning() {
    if (!head) {
        cout << "String is empty\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    Node* temp = head;
    head = head->next;
    last->next = head;
    delete temp;
}

void String::deleteFromEnd() {
    if (!head) {
        cout << "String is empty\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* pre_last = head;
    while (pre_last->next->next != head) {
        pre_last = pre_last->next;
    }

    delete pre_last->next;
    pre_last->next = head;
}

void String::deleteFromPosition(const int& position) {
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

void String::print() const {
    if (!head) {
        cout << "String is empty\n";
        return;
    }

    Node* current = head;
    do {
        cout << current->value << " ";
        current = current->next;
    } while (current != head);

    cout << "\n";
}

void String::clear() {
    if (!head) {
        return;
    }

    Node* current = head;

    do {
        Node* temp = current->next;
        delete current;
        current = temp;
    } while (current != head);

    head = nullptr;
}

bool String::empty() const {
    return head == nullptr;
}

int main() {
    String s1, s2("bc");
    s1.insertAtBeginning('b');
    s1.insertAtBeginning('a');
    s1.insertAtEnd('c');
    s1.insertAtPosition('d', 3);

    s1.print();
    return 0;    
}