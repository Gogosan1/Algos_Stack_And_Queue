#include <iostream>
#include <list>
#include <locale.h>
#include <ctime>
const int array_size = 1000;

template <typename T>
struct stack_array
{
    T array[array_size];
    int counter_of_elm = 0;
    T* hop = nullptr;

    void add_element(T elm)
    {
        if (counter_of_elm == 0)
        {
            hop = &array[0];
            *hop = elm;
            counter_of_elm++;
        }
        else
        {
            if (counter_of_elm <= array_size)
            {
                hop++;
                *hop = elm;
                counter_of_elm++;
            }
            else
            {
                std::cout << "Ошибка. Переполнение стека.\n";
            }
        }
    }

    T get_element()
    {
        if (counter_of_elm > 0)
        {
            T elm;
            elm = *hop;
            hop--;
            counter_of_elm--;
            if (counter_of_elm == 0)
            {
                hop = nullptr;
                return array[0];
            }
            return elm;
        }
        else
        {
            std::cout << "Ошибка. Нечего извлекать из стека.\n";
            return -1; // кидать ошибку
        }
    }
};



template <typename T>
struct stack_list
{
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* topPtr;

    stack_list() : topPtr(nullptr) {}

    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = topPtr;
        topPtr = newNode;
    }

private: void pop() {
        if (!isEmpty()) {
            Node* temp = topPtr;
            topPtr = topPtr->next;
            delete temp;
        }
        else {
            std::cout << "Стек пуст!" << std::endl;
        }
    }

public:  T top() {
        if (!isEmpty()) {
            T dat = topPtr->data;
            pop();
            return dat;
        }
        else {
            std::cout << "Стек пуст!";
            return -1; // 
        }
    }

    bool isEmpty() {
        return topPtr == nullptr;
    }

    ~stack_list() {
        while (topPtr != nullptr) {
            Node* temp = topPtr;
            topPtr = topPtr->next;
            delete temp;
        }
    }
};

template <typename T>
struct queue_array
{
    T array[array_size];
    int counter_of_elm = 0;
    T* first = nullptr;
    T* last = nullptr;

    void add_element(T elm)
    {
        if (counter_of_elm == 0)
        {
            first = &array[0];
            last = &array[0];
            *last = elm;
            counter_of_elm++;
        }
        else
        {
            if (counter_of_elm == array_size)
            {
                std::cout << "Ошибка переполнение очереди.\n";
            }
            else
            {///
                if (last == &array[array_size])
                {
                    last -= array_size;
                    *last = elm;
                    counter_of_elm++;
                }
                else
                {
                    last++;
                    *last = elm;
                    counter_of_elm++;
                }
            }
        }
    }

    T get_element()
    {
        if (counter_of_elm > 0)
        {
            // пограничный случай, когда остался один элм в очереди.
            if (counter_of_elm == 1)
            {
                T elm;
                elm = *first;
                first = nullptr;
                last = nullptr;
                counter_of_elm--;
                return elm;
            }
            else
            {
                // пограничный случай, когда указатель на первый равен последнему элм в массиве.
                if (first == &array[array_size])
                {
                    first -= array_size;
                    counter_of_elm--;
                    return array[array_size];
                }
                else
                {
                    T elm = *first;
                    first++;
                    counter_of_elm--;
                    return elm;
                }
            }
        }
        else
        {
            std::cout << "Ошибка. В очереди нет элементов для извлечения.\n";
        }

    }

};

template <typename T>
struct queue_list
{
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontPtr; //начало очереди 
    Node* endPtr; //конец очереди 


    queue_list() : frontPtr(nullptr), endPtr(nullptr) {}

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontPtr = newNode;
            endPtr = newNode;
        }
        else {
            endPtr->next = newNode;
            endPtr = newNode;
        }
    }

private: void dequeue() {
        if (!isEmpty()) {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
        }
        else {
            std::cout << "Queue is empty!" << std::endl;
        }
    }

public:  T front() {
        if (!isEmpty()) {
            T dat = frontPtr->data;
            dequeue();
            return dat;
        }
        else {
            std::cout << "Queue is empty!";
        }
    }

    bool isEmpty() {
        return frontPtr == nullptr;
    }

    ~queue_list() {
        while (frontPtr != nullptr) {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
        }
    }

};

int main()
{
    unsigned long long start_time = clock();
    setlocale(LC_ALL, "");
    stack_array<int> stack_arr;
    queue_array<int> queue_arr;
    stack_list<int> stack_lst;
    queue_list<int> queue_lst;
  
    for (int i = 0; i < array_size; i++)
    {
        stack_arr.add_element(i);
    }

    for (int i = 0; i < array_size; i++)
    {
        stack_arr.get_element();
    }

    for (int i = 0; i < array_size; i++)
    {
        stack_lst.push(i);
    }

    for (int i = 0; i < array_size; i++)
    {
        stack_lst.top();
       // stack_lst.pop();
    }
}