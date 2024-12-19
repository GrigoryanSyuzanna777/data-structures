// Single List Glossary
#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char* value;
    Node* next;

    Node(const char* val = nullptr, Node* nxt = nullptr) : value(nullptr), next(nxt) {
        if (val) {
            value = new char[strlen(val) + 1]; 
            strcpy(value, val);
        } 
    }

    ~Node() {
        delete[] value;
    }
};

class Glossary {
private:
    Node* head;

public:
    Glossary();
    Glossary(const Glossary&);
    ~Glossary();
    Glossary &operator=(const Glossary &);
    void insertAtBeginning(const char*);
    void insertAtEnd(const char*);
    void insertAtPosition(const char*, int);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(int);
    void print() const;
    void clear();
    bool empty() const;
    bool isAlphabeticalOrder() const;
};

Glossary::Glossary(): head(nullptr) {}

Glossary::Glossary(const Glossary& other): head(nullptr) {
    Node* current = other.head;

    while (current) {
        insertAtEnd(current->value);
        current = current->next;
    }
}

Glossary::~Glossary() {
    clear();
}

Glossary& Glossary::operator=(const Glossary& other) {
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

void Glossary::insertAtBeginning(const char* x) {
    Node* new_node = new Node(x, head);
    head = new_node;
}

void Glossary::insertAtEnd(const char* x) {
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

void Glossary::insertAtPosition(const char* x, int position) {
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

void Glossary::deleteFromBeginning() {
    if (!head) {
        cout << "Glossary is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void Glossary::deleteFromEnd() {
    if (!head) {
        cout << "Glossary is empty\n";
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

void Glossary::deleteFromPosition(int position) {
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

void Glossary::print() const {
    if (!head) {
        cout << "Glossary is empty\n";
        return;
    }

    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }

    cout << "\n";
}

void Glossary::clear() {
    while (head) {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}

bool Glossary::empty() const {
    return head == nullptr;
}

bool Glossary::isAlphabeticalOrder() const {
    if (!head) {
        return true;
    }

    Node* current = head;

    while (current->next) {
        int result = strcmp(current->value, current->next->value);
        if (result > 0)
            return false;
        
        current = current->next;
    }

    return true;
}

int main() {
    Glossary g;

    g.insertAtBeginning("cocoa");
    g.insertAtBeginning("banana");
    g.insertAtEnd("orange");
    g.insertAtPosition("apple", 0);

    cout << "Glossary after insertions\n";
    g.print();

    g.deleteFromBeginning();
    cout << "\nGlossary after deleting from beginning\n";
    g.print();

    cout << "\nGlossary is alphabetical: " << (g.isAlphabeticalOrder() ? "true" : "false") << "\n";

    // l.deleteFromPosition(1);
    // cout << "\nGlossary after deleting from  position 1\n";
    // l.print();

    // l.clear();
    // cout << "\nGlossary after clear\n";
    // l.print();

    return 0;
}