#include "List.h"
#include <stdexcept>

template <typename T> 
List<T>::List() {
    this->Count = 0;
}

template <typename T> 
List<T>::List(T* values, int size) {
    this->Count = 0;
    std::cout << "Size of values: " << size << '\n';
    for(int i = 0; i < size; ++i) {
        this->Add(values[i]);
    }
}

template <typename T> 
List<T>::~List() {
    while(this->head != nullptr) {
        ListNode<T>* next = this->head->next;
        delete this->head;
        this->head = next;
    }
}

template <typename T> 
int List<T>::GetCount() {
    return this->Count;
}

template <typename T> 
void List<T>::Add(T value) {
    std::cout << "Adding: " << value << '\n';
    if(this->head == nullptr) {
        this->head = new ListNode<T>(value, nullptr);
    } else {
        // ListNode<T>* item = this->head;
        // while(item->Next != nullptr) {
        //     item = item->Next;
        // }
        ListNode<T>* item = this->GetLastNode();
        item->Next = new ListNode<T>(value, item);
    }
    this->Count += 1;
}

template <typename T>
T* List<T>::First() {
    return &(this->head->Value);
}

template <typename T>
T* List<T>::Last() {
    return &((this->GetLastNode())->Value);
}

template <typename T>
T* List<T>::At(int index) {
    if(index >= this->Count) {
        throw std::runtime_error("Index out of bounds of collection");
    }
    int i = 0; 
    ListNode<T>* item = this->head;   
    while(i <= index) {
        if(i == index) return &(item->Value);
        item = item->Next;
        ++i;
    }
    return nullptr;
}

template <typename T>
void List<T>::Print(bool reverse) {
    ListNode<T>* item;
    int i;
    std::cout << "List:\n"; 
    if(!reverse) {
        i = 0;
        item = this->head;
        while(item != nullptr) {
            std::cout << '[' << i << "] = " << item->Value << '\n';
            item = item->Next;
            i++;
        }
    } else {
        i = this->Count - 1;
        item = this->GetLastNode();
        while(item != nullptr) {
            std::cout << '[' << i << "] = " << item->Value << '\n';
            item = item->Prev;
            i--;
        }
    }
}

template <typename T>
ListNode<T>* List<T>::GetLastNode() {
    ListNode<T>* item = this->head;
    while(item->Next != nullptr) {
        item = item->Next;
    }
    return item;
}

template <typename T>
ListNode<T>::ListNode(T value, ListNode* prev) {
    this->Value = value;
    this->Prev = prev;
}

template <typename T>
ListNode<T>::~ListNode() {
    std::cout << "List Node destructing\n";
}


int main() {
    std::cout << "Starting Test for List\n";
    int* values = new int[5] {1,2,3,4,5};
    List<int>* list = new List(values, 5);
    list->Add(100);

    std::cout << " List Count: " << list->GetCount() << '\n';
    std::cout << " First Item: " << *(list->First()) << '\n';
    std::cout << "  Last Item: " << *(list->Last()) << '\n';
    std::cout << "At Index #2: " << *(list->At(2)) << '\n';
    list->Print(false);
    list->Print(true);

    return 0;
}