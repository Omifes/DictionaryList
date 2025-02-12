#include "DictionaryList.h"

template <typename KeyType, typename ValueType>
DictionaryList<KeyType, ValueType>::DictionaryList() : head(nullptr), tail(nullptr), count(0) {}

template <typename KeyType, typename ValueType>
DictionaryList<KeyType, ValueType>::DictionaryList(const DictionaryList& other) : head(nullptr), tail(nullptr), count(0) {
    Node* current = other.head;
    while (current != nullptr) {
        insertItem(current->key, current->value);
        current = current->next;
    }
}

template <typename KeyType, typename ValueType>
DictionaryList<KeyType, ValueType>::DictionaryList(DictionaryList&& other) noexcept : head(other.head), tail(other.tail), count(other.count) {
    other.head = nullptr;
    other.tail = nullptr;
    other.count = 0;
}

template <typename KeyType, typename ValueType>
DictionaryList<KeyType, ValueType>& DictionaryList<KeyType, ValueType>::operator=(const DictionaryList& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            insertItem(current->key, current->value);
            current = current->next;
        }
    }
    return *this;
}

template <typename KeyType, typename ValueType>
DictionaryList<KeyType, ValueType>& DictionaryList<KeyType, ValueType>::operator=(DictionaryList&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        tail = other.tail;
        count = other.count;
        other.head = nullptr;
        other.tail = nullptr;
        other.count = 0;
    }
    return *this;
}

template <typename KeyType, typename ValueType>
DictionaryList<KeyType, ValueType>::~DictionaryList() {
    clear();
}

template <typename KeyType, typename ValueType>
void DictionaryList<KeyType, ValueType>::insertItem(const KeyType& key, const ValueType& value) {
    Node* newNode = new Node(key, value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        Node* current = head;
        while (current != nullptr && current->key < key) {
            current = current->next;
        }
        if (current != nullptr && current->key == key) {
            delete newNode;
            return;
        }
        if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (current == nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }
    count++;
}

template <typename KeyType, typename ValueType>
bool DictionaryList<KeyType, ValueType>::searchItem(const KeyType& key) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}
template <typename KeyType, typename ValueType>
bool DictionaryList<KeyType, ValueType>::deleteItem(const KeyType& key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            deleteNode(current);
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename KeyType, typename ValueType>
void DictionaryList<KeyType, ValueType>::deleteNode(Node* node) {
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }
    else {
        head = node->next;
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }
    else {
        tail = node->prev;
    }
    delete node;
    count--;
}

template <typename KeyType, typename ValueType>
void DictionaryList<KeyType, ValueType>::clear() {
    while (head != nullptr) {
        deleteNode(head);
    }
}

template <typename KeyType, typename ValueType>
void DictionaryList<KeyType, ValueType>::merge(const DictionaryList& other) {
    Node* current = other.head;
    while (current != nullptr) {
        insertItem(current->key, current->value);
        current = current->next;
    }
}

template <typename KeyType, typename ValueType>
void DictionaryList<KeyType, ValueType>::outAll() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->key << ": " << current->value << std::endl;
        current = current->next;
    }
}

template class DictionaryList<std::string, int>;
template class DictionaryList<std::string, std::string>;