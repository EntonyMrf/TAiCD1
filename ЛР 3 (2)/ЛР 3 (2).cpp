#include <iostream>
#include <string>
#include <windows.h>

using namespace std;


struct Node {
    string data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void insertAtPosition(string value, int position)
    {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
            return;
        }

        if (position == 1) {
            newNode->prev = NULL;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            Node* temp = head;
            int currentPosition = 1;

            while (currentPosition < position - 1 && temp != NULL) {
                temp = temp->next;
                currentPosition++;
            }

            if (temp == NULL) {
                cout << "Неправильный номер\n";
                delete newNode;
                return;
            }

            newNode->prev = temp;
            newNode->next = temp->next;

            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }

            temp->next = newNode;

            if (temp == tail) {
                tail = newNode;
            }
        }
    }

    void pechat() {
        if (head == NULL) {
            cout << "Список пуст\n";
            return;
        }

        Node* temp = head;
        cout << "Ваш список: ";
        while (temp != NULL) {
            cout << "\"" << temp->data << "\" ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    DoublyLinkedList List;
    string value, mas[100];
    int position, size, size2;

    cout << "Введите количество строк: ";
    cin >> size;
    cin.ignore();

    for (int i = 1; i < size + 1; i++)
    {
        cout << "Введите строку для добавления: ";
        getline(cin, value);
        List.insertAtPosition(value, i);
        mas[i] = value;
    }
    List.pechat();
    cout << "После добавления элементов: " << endl;
    size2 = size + 1;
    for (int i = 1; i < size + 1; i++)
    {
        if (i % 2 == 1)
        {
            List.insertAtPosition(mas[i], size2);
            size2++;
        }
    }
    List.pechat();
    return 0;
}