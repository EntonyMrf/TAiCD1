#include <iostream>
#include <algorithm>

using namespace std;

// Структура для узла дерева
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Функция для создания нового узла дерева
Node* Create_Node(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Ошибка при выделении памяти!" << endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функция для построения идеально сбалансированного бинарного дерева
Node* Build_Balanced_Tree(int arr[], int start, int end) {
    // Проверка базового случая
    if (start > end) {
        return NULL;
    }

    // Находим середину массива и делаем её корнем нового узла дерева
    int mid = (start + end) / 2;
    Node* root = Create_Node(arr[mid]);

    // Рекурсивно строим левое и правое поддерево
    root->left = Build_Balanced_Tree(arr, start, mid - 1);
    root->right = Build_Balanced_Tree(arr, mid + 1, end);

    return root;
}

// Функция для печати дерева (обход в инфиксном порядке)
void Print_Tree(Node* root) {
    if (root == NULL) {
        return;
    }
    Print_Tree(root->left);
    cout << root->data << " ";
    Print_Tree(root->right);
}

int main()
{
    setlocale(0, "");
    int n;
    int max = INT_MIN;
    cout << "Введите количество элементов: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите элементы: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    sort(arr, arr + n);

    Node* root = Build_Balanced_Tree(arr, 0, n - 1);

    cout << "Идеально сбалансированное бинарное дерево: ";
    Print_Tree(root);

    cout << "\nМаксимальный элемент в дереве: " << max << "\n";
}