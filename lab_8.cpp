#include <iostream>
#include <iomanip>
using namespace std;
#define SurName 18

struct stud
{
    int personal_number;
    char surname[SurName];
    int hours_underLoad;
    bool equals(stud& y)
    {
        return personal_number == y.personal_number && surname == y.surname && hours_underLoad == y.hours_underLoad;
    }
};

struct Node
{
    stud d;
    Node* next;
};

void output(Node* u)
{
    Node* p = u;

    while (p)
    {
        cout << "Personal Number: " << p->d.personal_number << endl;
        cout << "Input surname : " << p->d.surname << endl;
        cout << "Number of hours under load: " << p->d.hours_underLoad << endl;
        cout << "\n";
        p = p->next;
    }
    cout << endl;
}

void output_any(Node* u, int n)
{
    Node* p = u;

    for (int i = 0; i < n - 1; i++)
    {
        p = p->next;
    }
    cout << "Personal Number: " << p->d.personal_number << endl;
    cout << "Input surname: " << p->d.surname << endl;
    cout << "Number of hours under load: " << p->d.hours_underLoad << endl;
    cout << "\n";
}

void add_head(Node** Begin)
{
    if (*Begin == NULL)
    {
        *Begin = new Node;
        stud d;
        cout << "Personal Number: ";
        cin >> (*Begin)->d.personal_number;
        cout << "Input surname: ";
        cin >> (*Begin)->d.surname;
        cout << "Number of hours under load: ";
        cin >> (*Begin)->d.hours_underLoad;
        (*Begin)->next = NULL;
    }
    else
    {
        stud d;
        cout << "Personal Number: ";
        cin >> d.personal_number;
        cout << "Input surname: ";
        cin >> d.surname;
        cout << "Number of hours under load: ";
        cin >> d.hours_underLoad;

        Node* t = new Node;
        t->d = d;
        t->next = *Begin;
        *Begin = t;
    }
}

void add_end(Node** Begin)
{
    if (*Begin == NULL)
    {
        *Begin = new Node;

        Node d;
        cout << "\nSchool numbers : ";
        cin >> (*Begin)->d.personal_number;
        cout << "Input surname: ";
        cin >> (*Begin)->d.surname;
        cout << "Amount of children : ";
        cin >> (*Begin)->d.hours_underLoad;
        (*Begin)->next = NULL;
        cout << "\n";
    }
    else
    {
        stud d;
        cout << "\nSchool numbers : ";
        cin >> d.personal_number;
        cout << "Input surname: ";
        cin >> d.surname;
        cout << "Amount of children : ";
        cin >> d.hours_underLoad;
        cout << "\n";

        Node* t, * newt = new Node;
        for (t = *Begin; t->next; t = t->next)
            ;
        newt->d = d;
        newt->next = NULL;
        t->next = newt;
    }
}

void delet(Node*& Begin, int n)
{
    Node* delet = Begin;
    Node* temp = Begin;
    for (int i = 0; i < n - 1; i++)
    {
        delet = temp;
        temp = temp->next;
    }
    if (n == 1)
    {
        Begin = Begin->next;
    }
    delet->next = temp->next;
    delete temp;
}
void Next(Node* u, int n)
{
    return output_any(u, n + 1);
}
void Previous(Node* u, int n)
{
    return output_any(u, n - 1);
}

void swapNodes(Node** u, int pos1, int pos2)
{
    Node* p = *u;
    Node* b = *u;

    stud x, y;
    for (int i = 0; i < pos1 - 1; i++)
    {
        p = p->next;
    }
    x = p->d;

    for (int i = 0; i < pos2 - 1; i++)
    {
        b = b->next;
    }
    y = b->d;

    if (x.equals(y))
        return;

    Node* prevX = NULL, * currX = *u;
    while (currX && !currX->d.equals(x))
    {
        prevX = currX;
        currX = currX->next;
    }

    Node* prevY = NULL, * currY = *u;
    while (currY && !currY->d.equals(y))
    {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;

    if (prevX != NULL)
        prevX->next = currY;
    else
        *u = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        *u = currX;

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}
int main()
{

    Node* header = NULL;

    int k = 0;

    int Variant = 1;
    while (Variant != 0)
    {
        cout << "\n\nChoose action: \n"
            << endl;
        cout << "1. Print list\n" << "2. Add to front\n" << "3. Add to apend\n" << "4. Delete elements\n" << "5. Get Nth element\n"
            << "6. Get size of list\n" << "7. Delete list\n" << "8. Next element:\n" << "9. Previous elements\n" << "10. Swap elements\n"
            << "0. Exit\n"
            << endl;
        cin >> Variant;

        switch (Variant)
        {
        case 0:
            Variant = 0;
            break;
        case 1:
            cout << "\n";
            output(header);
            break;

        case 2:
            add_head(&header);
            k++;
            break;

        case 3:
            add_end(&header);
            k++;
            break;

        case 4:
            cout << "\nInput element number to delete : ";
            int d;
            cin >> d;
            if (d > k)
            {
                cout << "\nElement is missing\n\n";
                continue;
            }
            delet(header, d);
            cout << "\n"
                << d << " Element deleted!\n\n";
            k--;
            break;

        case 5:
            cout << "\nEnter the element number you want to display: ";
            int p;
            cin >> p;
            if (p > k)
            {
                cout << "\nElement is missing!\n\n";
                continue;
            }
            output_any(header, p);
            break;

        case 6:
            cout << "\nCurrent number of elemets in the list: " << k << "\n\n";
            break;

        case 7:
            header = NULL;
            k = 0;
            cout << "\nThe list is cleared!\n\n";
            break;
        case 8:
            cout << "Input element number :";
            int next;
            cin >> next;
            Next(header, next);
            break;

        case 9:
            cout << "Input element number :";
            int previous;
            cin >> previous;
            Previous(header, previous);
            break;

        case 10:
            cout << "Input elements position to swap" << endl;
            int pos1, pos2;

            cout << "Input position 1" << endl;
            cin >> pos1;

            cout << "Input position 2" << endl;
            cin >> pos2;

            swapNodes(&header, pos1, pos2);
            break;
        default:
            cout << "Input numbers from 1 to 10!\n\n";
            break;
        }
    }

    return 0;
}
