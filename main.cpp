#include "DictionaryList.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    DictionaryList<std::string, int> dict;

    // Добавление элементов
    dict.insertItem("apple", 1);
    dict.insertItem("banana", 2);
    dict.insertItem("orange", 3);
    dict.insertItem("kiwi", 4);

    // Вывод всех элементов
    std::cout << "Содержимое словаря:" << std::endl;
    dict.outAll();

    // Поиск элемента
    std::cout << "Поиск 'banana': " << (dict.searchItem("banana") ? "найдено" : "не найдено") << std::endl;
    std::cout << "Поиск 'grape': " << (dict.searchItem("grape") ? "найдено" : "не найдено") << std::endl;

    // Удаление элемента
    dict.deleteItem("orange");
    std::cout << "После удаления 'orange':" << std::endl;
    dict.outAll();

    // Очистка словаря
    dict.clear();
    std::cout << "После очистки словаря:" << std::endl;
    dict.outAll();

    return 0;
}
