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
    int Key;
    Node* left, * right;
};
struct BinTree
{
    Node* newNode(stud d)
    {
        Node* temp = new Node();
        temp->data = d;
        temp->Key = d.personal_number;
        temp->left = temp->right = NULL;
        return temp;
    }
    Node* root;
    BinTree()
    {
        root = NULL;
    }
    void inorder()
    {
        if (root == NULL)
        {
            cout << "Binary tree is empty" << endl;
            return;
        }
        inorRec(root);
    }
    void inorRec(Node* root)
    {
        if (root != NULL)
        {
            inorRec(root->left);
            root->data.studout();
            inorRec(root->right);
        }
    }
    void insert(stud data)
    {
        root = insertRec(root, data);
    }

    Node* insertRec(Node* node, stud data)
    {
        int Key = data.personal_number;
        if (node == NULL)
            return newNode(data);
        if (Key < node->Key)
            node->left = insertRec(node->left, data);
        else
            node->right = insertRec(node->right, data);
        return node;
    }
    Node* minValue(Node* node)
    {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
    void deleteNode(int Key)
    {
        root = deleteRec(root, Key);
    }
    Node* deleteRec(Node* root, int Key)
    {
        if (root == NULL)
            return root;
        if (Key < root->Key)
            root->left = deleteRec(root->left, Key);
        else if (Key > root->Key)
            root->right = deleteRec(root->right, Key);
        else
        {
            if (root->left == NULL and root->right == NULL)
                return NULL;
            else if (root->left == NULL)
            {
                Node* temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                Node* temp = root->left;
                free(root);
                return temp;
            }
            Node* temp = minValue(root->right);
            root->Key = temp->Key;
            root->right = deleteRec(root->right, temp->Key);
        }
        return root;
    }
    struct Node* searchRec(Node* root, int Key)
    {
        if (root == NULL || root->Key == Key)
            return root;
        if (root->Key < Key)
            return searchRec(root->right, Key);
        return searchRec(root->left, Key);
    }
    void search(int Key)
    {
        Node* search = searchRec(root, Key);
        if (search != NULL)
        {
            search->data.studout();
        }
        else
            cout << "There's no element at tree with entered School number" << endl;
    }
    int TotalNode(Node* root)
    {
        if (root == NULL)
            return 0;
        return 1 + TotalNode(root->left) + TotalNode(root->right);
    }
    void CountNodes()
    {
        int count = TotalNode(root);
        cout << "Amount of elements in tree: " << count << endl;
    }
    void delTreeRec(Node* node)
    {
        if (node == NULL) return;
        delTreeRec(node->left);
        delTreeRec(node->right);
        delete node;
    }
    void deleteTree() {
        delTreeRec(root);
    }
};
int main() {
    BinTree tree;
    int exit = 1;

    while (exit != 0)
    {
        cout << "Select operation with binary tree:" << endl;
        cout << "1 Add element to tree\n" <<  "2 Print tree in order traversal\n" << "3 Search for element" << "4 Delete element from tree\n"
        << "5 Delete tree\n" "6 Size of a tree" << "0 Exit" << endl;
        int menu;
        cin >> menu;
        switch (menu)
        {
        case 0:
            cout << "Exited successfully";
            exit = 0;
            break;
        case 1:
            cout << "Add element to a tree:" << endl;
            stud new_data;
            new_data.studin();
            tree.insert(new_data);
            break;
        case 2:
            tree.inorder();
            break;
        case 3:
            cout << "Enter School number " << endl;
            int id;
            cin >> id;
            tree.search(id);
            break;
        case 4:
            cout << "Enter School number to delete" << endl;
            int delNode;
            cin >> delNode;
            tree.deleteNode(delNode);
            break;
        case 5:
            tree.deleteTree();
            break;
        case 6:
            tree.CountNodes();
            break;
        default:
            cout << "Error" << endl;
            exit = 0;
        }
    }
}
