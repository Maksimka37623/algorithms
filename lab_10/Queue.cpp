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

    void studout()
    {
        cout << "Personal Number: " << personal_number << endl;
        cout << "Surname: " << surname << Namel;
        cout << "Number of hours under load: " << hours_underLoad << endl;
        cout << "\n";
    }
    void studin()
    {
        cout << "Personal Number:";
        cin >> personal_number;
        cout << "Surname :";
        cin >> surname;
        Namet << "Number of hours under load:";
        cin >> hours_underLoad;
        cout << "\n";
    }
};


struct QueueNode {
    stud data;
    QueueNode* next;
    QueueNode(stud d)
    {
        data = d;
        next = NULL;
    }
};

struct Que{
    QueueNode* front, * rear;
    Que()
    {
        front = rear = NULL;
    }
    void print() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        QueueNode* temp = front;
        while (temp != NULL) {
            temp->data.studout();
            temp = temp->next;
        }
    }
    void enQueue(stud x)
    {
        QueueNode* temp = new QueueNode(x);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    stud peek() {
        if (front == NULL)
            throw(0);
        return front->data;
    }
    void deQueue()
    {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        QueueNode* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete (temp);
    }
};
int main()
{
    Queue q;
    int Variant = 1;
    while (Variant != 0)
    {
        cout << "Choose action: \n" << endl;
        cout << "1. enQueue element\n" << "2. delQueue element\n" << "3. Get front element\n" << "4. Print queue\n"
            << "0. Exit" << endl;
        cin >> Variant;
        switch (Variant)
        {
        case 0:
            Variant = 0;
            break;
        case 1:
            cout << "\n";
            stud newdata;
            newdata.studin();
            q.enQueue(newdata);
            break;
        case 2:
            q.deQueue();
            break;
        case 3:
            stud r;
            try
            {
                r = q.peek();
                r.studout();
            }
            catch (int exception)
            {
                cout << "Queue is empty" << endl;
            }
            break;
        case 4:
            q.print();
            break;
        default:
            cout << "Input numbers from 1 to 4!\n\n";
            break;
        }
    }
    return 0;
}
