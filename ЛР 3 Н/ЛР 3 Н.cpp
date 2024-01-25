#include <iostream>
#include <time.h>

using namespace std;

struct Node {
    double data;
    Node* next;
    Node(double value) : data(value), next(nullptr)
    {}
};

Node* sozdanie(int size);
void ydalenie(Node*& head);
void pechat(Node* head);

int main()
{
    setlocale(0, "");
    int n, num, i;
    cout << "Введите количество элементов в списке: ";
    cin >> n;
    Node* spicok = sozdanie(n);
    cout << "Исходный список: ";
    pechat(spicok);
    cout << "Удаление из списка элементов с чётными номерами:\n";
    ydalenie(spicok);
    pechat(spicok);
}

Node* sozdanie(int size)
{
    if (size <= 0)
    {
        return nullptr;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Введите элементы списка:" << endl;
    double value;
    for (int i = 0; i < size; i++)
    {
        cout<<"Элемент " << i + 1 << ": ";
        cin >> value;
        Node* newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void ydalenie(Node*& head) 
{
    if (head == NULL)               // Если список пустой, ничего не делаем
    {
        cout << "Список пуст\n";
        return;
    }

    int i = 1;
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != NULL)
    { 
        if (i % 2 == 0)    // Если элемент с чётным номером
        {
            Node* temp = curr;
            if (prev)
            {
                prev->next = curr->next; // Пропускаем текущий элемент, обновляя ссылки
            }
            else
            {
                head = curr->next;
            }
            curr = curr->next;
            delete temp;
        }
        else
        {
            prev = curr;                // Переходим к следующему элементу
            curr = curr->next;
        }
        i++;
    }
}

void pechat(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}