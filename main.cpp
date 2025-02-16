#include "DictionaryList.h"
#include <iostream>

using namespace std;

void testInsert(DictionaryList<string, int>& dict);
void testSearch(DictionaryList<string, int>& dict);
void testDelete(DictionaryList<string, int>& dict);
void testClear(DictionaryList<string, int>& dict);
void testOutAll(DictionaryList<string, int>& dict);
void testMerge(DictionaryList<string, int>& dict);

int main() {
    setlocale(LC_ALL, "Russian");

    DictionaryList<string, int> dict;

    testInsert(dict);
    testSearch(dict);
    testDelete(dict);
    testMerge(dict);
    testClear(dict);

    return 0;
}

void testInsert(DictionaryList<string, int>& dict) {
    cout << "Тестирование вставки элементов:" << endl;
    dict.insertItem("apple", 1);
    dict.insertItem("banana", 2);
    dict.insertItem("orange", 3);
    dict.insertItem("kiwi", 4);
    dict.insertItem("grape", 5);
    testOutAll(dict);
}

void testSearch(DictionaryList<string, int>& dict) {
    cout << "Тестирование поиска элементов:" << endl;
    cout << "Поиск 'banana': " << (dict.searchItem("banana") ? "найдено" : "не найдено") << endl;
    cout << "Поиск 'grape': " << (dict.searchItem("grape") ? "найдено" : "не найдено") << endl;
    cout << "Поиск 'watermelon': " << (dict.searchItem("watermelon") ? "найдено" : "не найдено") << endl;
}

void testDelete(DictionaryList<string, int>& dict) {
    cout << "Тестирование удаления элементов:" << endl;
    dict.deleteItem("orange");
    cout << "После удаления 'orange':" << endl;
    testOutAll(dict);

    dict.deleteItem("banana");
    cout << "После удаления 'banana':" << endl;
    testOutAll(dict);
}

void testClear(DictionaryList<string, int>& dict) {
    cout << "Тестирование очистки словаря:" << endl;
    dict.clear();
    cout << "После очистки словаря:" << endl;
    testOutAll(dict);
}

void testMerge(DictionaryList<string, int>& dict) {
    cout << "Тестирование объединения словарей:" << endl;
    DictionaryList<string, int> dict2;
    dict2.insertItem("mango", 6);
    dict2.insertItem("peach", 7);
    dict2.insertItem("banana", 8);

    cout << "Содержимое второго словаря перед объединением:" << endl;
    dict2.outAll();

    dict.merge(dict2);
    cout << "Содержимое первого словаря после объединения:" << endl;
    testOutAll(dict);
}

void testOutAll(DictionaryList<string, int>& dict) {
    cout << "Содержимое словаря:" << endl;
    dict.outAll();
}
