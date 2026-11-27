#include <iostream>

/** @brief Wrapper for an element in a list */
template <typename T>
class ListNode {
    public:
        ListNode() {};
        ListNode(T value, ListNode* prev);
        ~ListNode();
        ListNode* Next;
        ListNode* Prev;
        T Value;
};

template <typename T> 
class List {
    public:
        List();
        List(T* values, int size);
        ~List();
        int GetCount();
        T* First();
        T* Last();
        T* At(int index);
        void Print(bool reverse);
        void Prepend(T value);
        void Append(T value);
    private:
        int Count;
        ListNode<T>* GetLastNode();
        ListNode<T>* head = nullptr;
};