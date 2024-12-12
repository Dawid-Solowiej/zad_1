#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class List
{
private:
    struct Node
    {
        Node(T val) : value(val), next(nullptr), prev(nullptr) {}
        T value;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    size_t length;

public:
    List() noexcept : head(nullptr), tail(nullptr), length(0) {}

    ~List()
    {
        while (head != nullptr)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }


    size_t size() const noexcept
    {
        return length;
    }

    void pushFront(T value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        else
            tail = newNode;
        head = newNode;
        length++;
    }

    void pushBack(T value)
    {
        Node* newNode = new Node(value);
        newNode->prev = tail;
        if (tail != nullptr)
            tail->next = newNode;
        else
            head = newNode;
        tail = newNode;
        length++;
    }

    T popFront()
    {
        if (head == nullptr)
            throw std::runtime_error("List is empty, cannot popFront.");

        Node* tmp = head;
        T val = tmp->value;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete tmp;
        length--;
        return val;
    }

    T popBack()
    {
        if (tail == nullptr)
            throw std::runtime_error("List is empty, cannot popBack.");

        Node* tmp = tail;
        T val = tmp->value;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
        delete tmp;
        length--;
        return val;
    }
};
