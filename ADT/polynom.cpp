// single List Polynom
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int val, Node* nxt = nullptr): value(val), next(nxt) {}
};

class Polynom {
private:
    Node* head;

public:
    Polynom();
    Polynom(const Polynom&);
    ~Polynom();
    Polynom &operator=(const Polynom &);
    void insertAtBeginning(const int&);
    void insertAtEnd(const int&);
    void insertAtPosition(const int&, const int&);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(const int&);
    void print() const;
    void clear();
    bool empty() const;
    Polynom calcualateDerivative() const;
};

Polynom::Polynom(): head(nullptr) {}

Polynom::Polynom(const Polynom& other): head(nullptr) {
    Node* current = other.head;

    while (current) {
        insertAtEnd(current->value);
        current = current->next;
    }
}

Polynom::~Polynom() {
    clear();
}

Polynom& Polynom::operator=(const Polynom& other) {
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

void Polynom::insertAtBeginning(const int& x) {
    Node* new_node = new Node(x, head);
    head = new_node;
}

void Polynom::insertAtEnd(const int& x) {
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

void Polynom::insertAtPosition(const int& x, const int& position) {
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

void Polynom::deleteFromBeginning() {
    if (!head) {
        cout << "Polynom is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void Polynom::deleteFromEnd() {
    if (!head) {
        cout << "Polynom is empty\n";
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

void Polynom::deleteFromPosition(const int& position) {
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

void Polynom::print() const {
    if (!head) {
        cout << "Polynom is empty\n";
        return;
    }

    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }

    cout << "\n";
}

void Polynom::clear() {
    while (head) {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}

bool Polynom::empty() const {
    return head == nullptr;
}

Polynom Polynom::calcualateDerivative() const {
    Polynom result;
    if (!head) {
        return result;
    }

    if (!head->next) {
        result.insertAtEnd(0);
        return result;
    }

    int degree = -1;
    Node* current = head;
    while (current) {
        ++degree;
        current = current->next;
    }

    current = head;
    while (current->next) {
        result.insertAtEnd(current->value * degree);
        current = current->next;
        --degree;
    }

    return result;
}

int main() {
    Polynom p;
    
    p.insertAtEnd(5);
    p.insertAtEnd(4);
    p.insertAtBeginning(2);
    p.insertAtPosition(45, 3);

    cout << "Polynom after insertions\n";
    p.print();

    Polynom derivative = p.calcualateDerivative();
    cout << "\nPolynom derivative: ";
    derivative.print();

    return 0;
}