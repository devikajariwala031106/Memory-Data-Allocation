#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *Head;

public:
    LinkedList()
    {
        Head = nullptr;
    }

    void InsertAtBeginning(int ele)
    {
        Node *newNode = new Node;
        newNode->data = ele;
        newNode->next = Head;
        Head = newNode;
    }

    void append(int ele)
    {
        Node *newNode = new Node;
        newNode->data = ele;
        newNode->next = nullptr;

        if (Head == nullptr)
        {
            Head = newNode;
            return;
        }

        Node *temp = Head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void search(int ele)
    {
        Node *temp = Head;
        int position = 0;
        while (temp != nullptr)
        {
            if (temp->data == ele)
            {
                cout << ele << " element is at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << ele << " element is not in the list " << endl;
    }

    void Delete(int ele)
    {
        Node *temp = Head;
        Node *prev = nullptr;

        while (temp != nullptr && temp->data != ele)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << ele << " element is not found  " << endl;
            return;
        }
        if (prev == nullptr)
        {
            Head = Head->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
        cout << ele << " element is deleted " << endl;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = Head;
        Node *nextNode = nullptr;

        while (current != nullptr)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        Head = prev;
        cout << "List is reversed " << endl;
    }

    void display()
    {
        Node *temp = Head;
        if (temp == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        cout << "List is : ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList()
    {
        Node *temp;
        while (Head != nullptr)
        {
            temp = Head;
            Head = Head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;
    int choice, ele;

    do
    {
        cout << "----DYNAMIC MEMORY ALLOCATION----" << endl;
        cout << "1. Insert at beginning " << endl;
        cout << "2. Append at end " << endl;
        cout << "3. Search " << endl;
        cout << "4. Delete " << endl;
        cout << "5. Reverse " << endl;
        cout << "6. Display " << endl;
        cout << "0. Exit.. " << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Element : ";
            cin >> ele;
            list.InsertAtBeginning(ele);
            break;

        case 2:
            cout << "Enter Element : ";
            cin >> ele;
            list.append(ele);
            break;

        case 3:
            cout << "Enter Element : ";
            cin >> ele;
            list.search(ele);
            break;

        case 4:
            cout << "Delete Element : ";
            cin >> ele;
            list.Delete(ele);
            break;

        case 5:
            list.reverse();
            break;

        case 6:
            list.display();
            break;

        case 0:
            cout << "Exit... " << endl;
            break;

        default:
            cout << "Invalid choice..... " << endl;
        }

    } while (choice != 0);

    return 0;
}
