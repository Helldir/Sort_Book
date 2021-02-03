#ifndef BOOKSORT_H
#define BOOKSORT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <clocale>
#include <algorithm>
#include <cstdlib>

using namespace std;
//заголовок класса сортировки

struct Word{
    string T; //структура хранящая слово и кол-во повторений
    int a;
};

class BookSort
{
private:
    vector <Word> book;
    vector <Word> :: iterator alphiter;
public:
    int Search(Word in);//поиск слова
    void push(Word in);//добавления нового слова
    void Sort();//сортировка слов по количеству повторений
    void Conclusion();//создание и вывод файла
};

#endif // BOOKSORT_H
