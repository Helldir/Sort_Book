#include "../Sort_Book/Sort_and_Search/booksort.h"


using namespace std;



int main(/*int argc, char *argv[]*/)
{
    setlocale(LC_ALL, "RUS");
    string Title;
    //если есть необходимость, можно добавить любой текстовый файл через полное имя, надо только раскомментить две строки внизу, и вместо
    //пути в инициализации потока вставить Title
    //cout << "Введите полное название книги, то есть путь к книге, начиная c /home: " << endl;
   // cin >> Title;
    ifstream infile("/home/helldir/Programming/Sort_Book/War_and_Peace.txt");
    istream_iterator <string> worditer(infile);
    BookSort newBook;
    Word newWord;
    newWord.T.clear();
    while (infile)
    {
        newWord.T += *worditer;//считывание потока по словам
        for ( string::iterator i = newWord.T.begin(); i != newWord.T.end(); ++i )
        if ( ispunct(*i) )
            *i = ' ';//обработка знаков препинания
        if (!(newBook.Search(newWord))){//поиск слова и подсчет количества повторений (реализовано в ф-ии поиска
            newBook.push(newWord);//добавление слова при отсутствии повторов
        }
        newWord.T.clear();
        worditer++;
    }
    newBook.Sort();
    newBook.Conclusion();
    return 0;
}
