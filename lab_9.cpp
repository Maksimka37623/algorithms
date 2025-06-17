#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#define SurLen 20

struct stud {
    int personal_number;
    char surname[SurLen];
    int hours_underLoad;
    bool equals(const stud& y) const {
        return personal_number == y.personal_number
            && strcmp(surname, y.surname) == 0
            && hours_underLoad == y.hours_underLoad;
    }
};

struct Node {
    stud d;
    Node* prev;
    Node* next;
    Node(const stud& data) : d(data), prev(nullptr), next(nullptr) {}
};

void printList(Node* head) {
    cout << "----DoublyLinkedList----\n";
    for (Node* p = head; p; p = p->next) {
        cout << "Personal Number: " << p->d.personal_number << endl;
        cout << "Surname: " << p->d.surname << endl;
        cout << "Number of hours under load: " << p->d.hours_underLoad << endl;
        cout << endl;
    }
}

void append(Node*& head, Node*& Tail) {
    stud d;
    cout << "Personal Number: "; cin >> d.personal_number;
    cout << "Surname: "; cin >> d.surname;
    cout << "Number of hours under load: "; cin >> d.hours_underLoad;
    Node* new_node = new Node(d);
    if (!head) head = Tail = new_node;
    else {
        Tail->next = new_node;
        new_node->prev = Tail;
        Tail = new_node;
    }
    cout << endl;
}

void delList(Node*& head, Node*& Tail) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    Tail = nullptr;
}

void delNode(Node*& head, Node*& Tail, int pos) {
    if (!head || pos <= 0) return;
    Node* cur = head;
    for (int i = 1; cur && i < pos; ++i) cur = cur->next;
    if (!cur) return;
    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    else Tail = cur->prev;
    delete cur;
}

int Sizeof(Node* head) {
    int cnt = 0;
    for (Node* p = head; p; p = p->next) ++cnt;
    return cnt;
}

Node* getNod(Node* head, int k) {
    if (k <= 0) return nullptr;
    Node* cur = head;
    for (int i = 1; cur && i < k; ++i) cur = cur->next;
    return cur;
}
void cloneList(Node* srcHead, Node*& destHead, Node*& destTail) {
    destHead = destTail = nullptr;
    for (Node* cur = srcHead; cur; cur = cur->next) {
        Node* new_node = new Node(cur->d);
        if (!destHead) destHead = destTail = new_node;
        else {
            destTail->next = new_node;
            new_node->prev = destTail;
            destTail = new_node;
        }
    }
}

void mergeLists(Node*& head1, Node*& Tail1, Node* head2, Node* Tail2) {
    if (!head1) head1 = head2, Tail1 = Tail2;
    else if (head2) {
        Tail1->next = head2;
        head2->prev = Tail1;
        Tail1 = Tail2;
    }
}

void insBefore(Node*& head, Node*& Tail, int pos) {
    int n = Sizeof(head);
    if (pos < 1 || pos > n) { cout << "Invalid position\n"; return; }
    stud d;
    cout << "Personal Number: "; cin >> d.personal_number;
    cout << "Surname: "; cin >> d.surname;
    cout << "Number of hours under load: "; cin >> d.hours_underLoad;
    Node* new_node = new Node(d);
    Node* cur = head;
    for (int i = 1; i < pos; ++i) cur = cur->next;
    new_node->prev = cur->prev;
    new_node->next = cur;
    if (cur->prev) cur->prev->next = new_node;
    else head = new_node;
    cur->prev = new_node;
}

int search(Node* head) {
    stud key;
    cout << "Enter element to search: ";
    cout << "Personal Number: "; cin >> key.personal_number;
    cout << "Surname: "; cin >> key.surname;
    cout << "Number of hours under load: "; cin >> key.hours_underLoad;
    Node* cur = head;
    int pos = 1;
    while (cur) {
        if (cur->d.equals(key)) return pos;
        cur = cur->next;
        ++pos;
    }
    return 0;
}

void splitList(Node* head, int p, int q) {
    int n = Sizeof(head);
    if (p + q > n) { cout << "Ratio exceeds length\n"; return; }
    Node* cur = head;
    for (int i = 1; i < p; ++i) cur = cur->next;
    Node* head2 = cur->next;
    cur->next = nullptr;
    if (head2) head2->prev = nullptr;
    printList(head);
    cout << "----Second part----\n";
    printList(head2);
}

void swapAdjacent(Node*& head, Node*& Tail, int pos) {
    Node* x = getNod(head, pos);
    if (!x || !x->next) return;
    Node* y = x->next;
    if (x->prev) x->prev->next = y;
    else head = y;
    if (y->next) y->next->prev = x;
    else Tail = x;
    x->next = y->next;
    y->prev = x->prev;
    y->next = x;
    x->prev = y;
}

int main() {
    Node* head = nullptr, * Tail = nullptr;
    Node* cloneHead = nullptr, * cloneTail = nullptr;
    Node* head2 = nullptr, * Tail2 = nullptr;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << left << setw(15) << "1 Clone list" << setw(15) << "7 insBefore" << "\n";
        cout << setw(15) << "2 Append" << setw(15) << "8 Search" << "\n";
        cout << setw(15) << "3 Size" << setw(15) << "9 Split" << "\n";
        cout << setw(15) << "4 Delete node" << setw(15) << "10 Print" << "\n";
        cout << setw(15) << "5 Merge" << setw(15) << "11 delList" << "\n";
        cout << setw(15) << "6 Get Kth" << setw(15) << "12 SwapAdj" << "\n";
        cout << setw(15) << "0 Exit" << "\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cloneList(head, cloneHead, cloneTail);
            printList(cloneHead);
            break;
        case 2: append(head, Tail); break;
        case 3: cout << "Size: " << Sizeof(head) << "\n"; break;
        case 4: {
            int pos; cout << "Position: "; cin >> pos;
            delNode(head, Tail, pos);
            break;
        }
        case 5: {
            cout << "Build second list (1-append, other-exit):\n";
            int f;
            while (cin >> f && f == 1) append(head2, Tail2);
            mergeLists(head, Tail, head2, Tail2);
            break;
        }
        case 6: {
            int k; cout << "K: "; cin >> k;
            Node* kn = getNod(head, k);
            if (kn) {
                cout << "Personal Number     : " << kn->d.personal_number << endl;
                cout << "Surname: " << kn->d.surname << endl;
                cout << "Number of hours under load: " << kn->d.hours_underLoad << endl;
            }
            else {
                cout << "No such element" << endl;
            }
            break;
        }
        case 7: {
            int pos; cout << "Pos: "; cin >> pos;
            insBefore(head, Tail, pos);
            break;
        }
        case 8: {
            int res = search(head);
            if (res) cout << "Found at " << res << "\n";
            else cout << "Not found\n";
            break;
        }
        case 9: {
            int p, q; cout << "p: "; cin >> p;
            cout << "q: "; cin >> q;
            splitList(head, p, q);
            break;
        }
        case 10: printList(head); break;
        case 11: delList(head, Tail); break;
        case 12: {
            int pos; cout << "Pos: "; cin >> pos;
            swapAdjacent(head, Tail, pos);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
