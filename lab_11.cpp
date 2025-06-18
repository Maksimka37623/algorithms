#include <iostream>
#include <windows.h>
using namespace std;
#define SurName 18

struct stud
{
    int personal_number;
    char surname[SurName];
    int hours_underLoad;
    bool equals(stud& y)
    {
        return personal_number == y.personal_number &&
            strcmp(surname, y.Namename) ==Name&&
            hours_underLoad, y.hours_underLoad == 0;
    }
    void studoutput()
    {
        cout << "Personal Number: " << personal_number << endl;
        cout << "Surname: " << surname << Namel;
        cout << "Number of hours under load: " << hours_underLoad << endl;
        cout << "\n";
    }
    void studinput()
    {
        cout << "Personal Number: ";
        cin >> personal_number;
        cout << "Surname: ";
        cin >> surname;
        cout << "Number of hours under load: ";
        cin >> hours_underLoad;
        cout << "\n";
    }
};
struct Node
{
    stud data;
    double prior;
    Node* next;
    static Node* newNode(stud d)
    {
        Node* Temp = new Node();
        Temp->data = d;
        Temp->prior = d.amount_of_children;
        Temp->next = NULL;
        return Temp;
    }
};
struct priorQueue
{
    Node* front;
    Node* rear;
public:
    priorQueue()
    {
        front = rear = NULL;
    }

    void enQueue(const stud& x) {
        Node* Temp = Node::newNode(x);
        if (!front) {

            front = rear = Temp;
        }
        else {

            Node* t = front;
            while (t->next)
                t = t->next;
            t->next = Temp;
            rear = Temp;
        }
    }
    void delQueue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* Temp = front;
        front = front->next;
        if (front == NULL){
            rear = NULL;
        }
        delete (Temp);
    }
    stud peek()
    {
        if (front == NULL)
            throw(0);
        return front->data;
    }
    void pop()
    {
        Node* Temp = front;
        front = front->next;
        free(Temp);
    }
    void push(stud d)
    {
        Node* start = front;
        Node* Temp = Node::newNode(d);
        double p = d.amount_of_children;
        if (front == NULL)
        {
            front = rear = Temp;
            return;
        }
        if (front->prior > p)
        {
            Temp->next = front;
            front = Temp;
        }
        else
        {
            while (start->next != NULL &&
                start->next->prior < p)
            {
                start = start->next;
            }
            Temp->next = start->next;
            start->next = Temp;
        }
    }
    int isEmpty()
    {
        return front == NULL;
    }
    int size()
    {
        if (front == NULL)
            throw(0);
        int Size = 0;
        Node* Temp = front;
        while (Temp != NULL)
        {
            Size++;
            Temp = Temp->next;
        }
        return Size;
    }
    void print()
    {
        if (front == NULL)
        {
            cout << "prior queue is empty" << endl;
            return;
        }
        Node* Temp = front;
        while (Temp != NULL)
        {
            Temp->data.studout();
            Temp = Temp->next;
        }
    }
    void erase()
    {
        rear = NULL;
        while (front != NULL)
        {
            Node* Temp = front;
            front = front->next;
            free(Temp);
        }
    }
};
int main()
{
    priorQueue pq;
    int variant = 1;
    while (variant != 0)
    {
        cout << "Choose action:\n"<< endl;
        cout << "1.Push element with prior" << "2. Pop element with prior" << "3. Get front element" << "4. Get size of Queue" 
        << "5. Clear Queue" << "6. Enqueue element" << "7. delQueue element" << "8. Print Queue"
        << "0. Exit\n" << endl;
        cin >> variant;
        switch (variant)
        {
        case 0:
            variant = 0;
            break;
        case 1:
            cout << "\n";
            stud newdata;
            newdata.studin();
            pq.push(newdata);
            break;

        case 2:
            pq.pop();
            break;

        case 3:
            stud front;

            try
            {
                front = pq.peek();
                front.studout();
            }
            catch (int exception)
            {
                cout << "Queue is empty" << endl;
            }

            break;

        case 4:
            try
            {
                int size = pq.size();
                cout << "size of queue is: " << size << endl;
            }
            catch (int exception)
            {
                cout << "Deque is empty" << endl;
            }
            break;

        case 5:
            pq.erase();
            break;
        case 6:
            cout << "\n";
            stud new_data;
            new_data.studin();
            pq.enQueue(new_data);
            break;
        case 7:
            pq.delQueue();
            break;
        case 8:
            pq.print();
            break;
        default:
            cout << "Input numbers from 1 to 8!\n\n";
            break;
        }
    }
    return 0;
}
