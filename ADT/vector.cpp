// double Vector Vector
#include <iostream>
using namespace std;

struct Node {
    int value;
    int index;
    Node* next;
    Node* prev;

    Node(int val, int ind, Node* nxt = nullptr, Node* prv = nullptr): value(val), index(ind), next(nxt), prev(prv) {}
};

class Vector {
private:
    Node* head;

public:
    Vector();
    Vector(const Vector&);
    ~Vector();
    Vector &operator=(const Vector &);
    void insertAtBeginning(const int&);
    void insertAtEnd(const int&);
    void deleteFromBeginning();
    void deleteFromEnd();
    void print() const;
    void clear();
    bool empty() const;
    int size() const;
    int getNorm() const;
};

Vector::Vector(): head(nullptr) {}

Vector::Vector(const Vector& other): head(nullptr) {
    Node* current = other.head;

    while (current) {
        insertAtEnd(current->value);
        current = current->next;
    }
}

Vector::~Vector() {
    clear();
}

Vector& Vector::operator=(const Vector& other) {
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

void Vector::insertAtBeginning(const int& x) {
    Node* new_node = new Node(x, 0, head);
    if (head) {
        head->prev = new_node;
    }

    Node* current = head;
    int ind = 1;
    while (current) {
        current->index = ind;
        ++ind;
        current = current->next;
    }

    head = new_node;
}

void Vector::insertAtEnd(const int& x) {
    Node* current = head;
    int ind = 0;
    while (current) {
        ++ind;
        current = current->next;
    }

    Node* new_node = new Node(x, ind, nullptr);

    if (!head) {
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

void Vector::deleteFromBeginning() {
    if (!head) {
        cout << "Vector is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    delete temp;

    Node* current = head;
    int ind = 0;
    while (current) {
        current->index = ind;
        ++ind;
        current = current->next;
    }
}

void Vector::deleteFromEnd() {
    if (!head) {
        cout << "Vector is empty\n";
        return;
    }

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* last = head;
    while (last->next) {
        last = last->next;
    }

    last->prev->next = nullptr;
    delete last;
}

void Vector::print() const {
    if (!head) {
        cout << "Vector is empty\n";
        return;
    }

    Node* current = head;
    while (current) {
        cout << current->value << " " << current->index << "\n";
        current = current->next;
    }
}

void Vector::clear() {
    while (head) {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}

bool Vector::empty() const {
    return head == nullptr;
}

int Vector::size() const {
	Node* current = head;
    int result = 0;

	while (current) {
		++result;
		current = current->next; 
	}

    return result;
}

int Vector::getNorm() const {
	Node* current = head;
    int result = 0;

	while (current) {
		result += abs(current->value);
		current = current->next; 
	}

    return result;
}

int main() {
    Vector v;
    
    v.insertAtEnd(20);
    v.insertAtEnd(30);
    v.insertAtBeginning(10);
    v.insertAtBeginning(40);
    v.insertAtBeginning(50);

    cout << "Vector after insertions\n";
    v.print();
    cout << "Vector size: " << v.size() << "\n";

    v.deleteFromEnd();
    cout << "\nVector after deleting from the end\n";
    v.print();

    cout << "\nVector size: " << v.size() << "\n";

    cout << "\nVector norm: " << v.getNorm() << "\n";
    return 0;
}