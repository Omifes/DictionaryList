#ifndef __DICTIONARY_LIST__
#define __DICTIONARY_LIST__

#include <iostream>
#include <string>

template <typename KeyType, typename ValueType>
class DictionaryList {
private:
    struct Node {
        KeyType key;
        ValueType value;
        Node* next;
        Node* prev;

        Node(KeyType k, ValueType v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

    void deleteNode(Node* node);
    
public:
    DictionaryList();
    DictionaryList(const DictionaryList& other);
    DictionaryList(DictionaryList&& other) noexcept;
    DictionaryList& operator=(const DictionaryList& other);
    DictionaryList& operator=(DictionaryList&& other) noexcept;
    ~DictionaryList();

    void insertItem(const KeyType& key, const ValueType& value);
    bool searchItem(const KeyType& key) const;
    bool deleteItem(const KeyType& key);
    void clear();
    void merge(const DictionaryList& other);
    void outAll() const;
};

#endif