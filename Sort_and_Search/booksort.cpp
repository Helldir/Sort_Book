#include "booksort.h"


bool operator ==(Word first, Word second){
    if (first.T == second.T)
        return 1;
    else
        return 0;
}

struct compare{//компататор для сортировки
    inline bool operator() (const Word& first, const Word& second)
    {
        return (first.a < second.a);
    }
};

//реализация бинарного поиска слов, в отсортированном множестве по кол-ву повторений
int BookSort::Search(Word in){
    if (book.empty())
        return 0;
    alphiter = book.begin();
    if (in.T == alphiter->T)
        return 1;
    vector <Word> ::iterator alphiter2 = book.end();
    while(1)
    {
        if(in.T == alphiter->T){
            alphiter->a++;
            return 1;
        }
        alphiter++;
        if (alphiter == alphiter2)
            return 0;
        if(in.T == alphiter2->T){
            alphiter->a++;
            return 1;
        }
        alphiter2--;
        if(alphiter == alphiter2)
            return 0;
    }
    return 0;
}

void BookSort::push(Word in){
    alphiter = book.end();
    book.push_back(in);
}

void BookSort::Sort(){
    sort(book.begin(), book.end(), compare());
    reverse(book.begin(), book.end());
}

void BookSort::Conclusion()
{
    alphiter = book.begin();
    ofstream outfile("Sorted_Book.txt");
    ostream_iterator<string> ositer(outfile);
    cout << "Word: " << book.end()->T << " " <<
            "Repeats: " << alphiter->a << endl;
    for (int i = 0; i < 100; i++)
    {
        outfile << "Word: " << alphiter->T << " " <<
                   "Repeats: " << alphiter->a << endl;
        alphiter++;
    }
}
