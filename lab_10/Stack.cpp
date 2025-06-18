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
struct StackNode
{
    stud data;
    StackNode* next;
};

void print(StackNode* head)
{
    if (head == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    while (head != NULL)
    {
        head->data.studout();
        head = head->next;
    }
}

StackNode* newNode(stud data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int Empty(StackNode* root)
{
    return !root;
}

void push(StackNode** root, stud data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

void pop(StackNode** root)
{
    if (Empty(*root)) {
        cout << "stack is empty" << endl;
        return;
    }
    *root = (*root)->next;
}

stud peek(StackNode* root)
{
    if (Empty(root))
        throw(0);
    return root->data;
}
int main()
{
    StackNode* root = NULL;
    int Variant = 1;
    while (Variant != 0)
    {
        cout << "Choose action: \n" << endl;
        cout << "1. Push element" << "2. Pop element" << "3. Get root element" << "4. Print Stack"
            << "0. Exit\n" << endl;
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
            push(&root, newdata);
            break;
        case 2:
            pop(&root);
            break;
        case 3:
            stud r;
            try
            {
                r = peek(root);
                r.studout();
            }
            catch (int exception)
            {
                cout << "Stack is empty" << endl;
            }
            break;
        case 4:
            print(root);
            break;
        default:
            cout << "Input numbers from 1 to 4!\n\n";
            break;
        }
    }
    return 0;
}
