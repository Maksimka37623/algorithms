#include <iostream>
#include <string>
#define P 13
using namespace std;

const int SurLen = 18;
struct stud
{
    int personal_number;
    char surname[SurLen];
    int hours_underLoad;
    void stud_out()
    {
        cout << personal_number << "\t" << surname << "\t" << hours_underLoad << "\t" << endl;
    }
};

int main()
{
    stud P1[P], P2[P], P3[P];
    for (int i = 0; i < P; i++)
    {
        cout << "Personal Number:";
        cin >> P1[i].personal_number;
        cout << "Surname:";
        cin >> P1[i].surname;
        cout << "Number of hours under load:";
        cin >> P1[i].hours_underLoad;
        P2[i] = P3[i] = P1[i];
    }

    int exit = 1;
    while (exit != 0)
    {
        cout << "Pick order of passenger info:" << endl;
        cout << "1-Sorted by Personal Number   \t 2- Sorted by Number of hours under load" << endl;
        cout << "3- in previous order \t 0- Exit" << endl;
        int menu;
        cin >> menu;
        switch (menu)
        {
        case 0:
            exit = 0;
            cout << "Exit successfully" << endl;
            break;

        case 1:
            for (int i = 0; i < P; i++)
            {
                for (int j = i + 1; j < P; j++)
                {
                    if (P2[i].personal_number > P2[j].personal_number)
                    {
                        swap(P2[i], P2[j]);
                    }
                }
            }

            for (int i = 0; i < P; i++)
            {
                P2[i].stud_out();
            }
            break;

        case 2:
            for (int i = 0; i < P; i++)
            {
                for (int j = i + 1; j < P; j++)
                {
                    if (P3[i].hours_underLoad > P3[j].hours_underLoad)
                    {
                        swap(P3[i], P3[j]);
                    }
                }
            }

            for (int i = 0; i < P; i++)
            {
                P3[i].stud_out();
            }
            break;

        case 3:
            for (int i = 0; i < P; i++)
            {
                P1[i].stud_out();
            }
            break;

        default:
            cout << "Error" << endl;
            exit = 0;
            break;
        }
    }
}
