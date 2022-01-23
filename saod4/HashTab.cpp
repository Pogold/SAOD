#include "HashTab.h"

regex reg("([\\d]{3})([ABCDEFGHIJKLMNOPQRSTUVWXYZ]{1})([\\d]{2})");

int HashTable::HashFunctionHorner(const string& s, int table_size, const int key)// хэш-функция строка которую будут хэшировать,размер таблицы,
{
    int hash_result = 0;
    for (int i = 0; s[i] != 0; ++i)
    {
        hash_result = (key * hash_result + s[i]) % table_size; //деление по модулю или с остатком
    }
    //hash_result = (hash_result * 2 + 1) % table_size;
    return hash_result; //номер этого ключа в массиве
}

HashTable::HashTable()
{
    size = default_size;
    arr = new Cell[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = Cell();
    }
}

HashTable::~HashTable()
{

    for (int i = 0; i < size; ++i)
    {
        arr[i].clear();
    }
    delete[] arr;
}

void HashTable::add(string key)
{
    int hashindex = HashFunctionHorner(key, size, 3); //высчитываем номер ячейки где будет храниться ключ
   
    if (arr[hashindex].hashexist(key))
    {
        cout << "Такой ключ уже существует" << endl;
    }
    else { arr[hashindex].push_back(key); }
}

void HashTable::find()
{
    int ch;
    cout << "Как вы хотите искать (1-по ключу /2-по номеру)?" << endl;
    cin >> ch;
    while (cin.fail() || (ch < 1) || (ch > 2)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "Неверно!" << endl;
        cout << "Введите ключ:" << endl;
        cin >> ch;
    }

    if (ch == 1) {
        string key = inputKey();
        int hashindex = HashFunctionHorner(key, size, 3);

        if (arr[hashindex].hashexist(key))
        {
            cout << "Элемент " << hashindex << endl;
            arr[hashindex].ShowCell();
        }
        else { cout << "Такого ключа нет " << endl; }

    }
    else  if (ch == 2) {
        int num = inputNum();
        if (arr[num].GetSize() != 0) {
            arr[num].ShowCell();
        }
        else { cout << "Элемент не найден" << endl; }
    }
}

string HashTable::inputKey()
{
    string key;
    cout << "Введите ключ:" << endl;
    cin >> key;
    while (cin.fail() || (key.size() != 6) || (regex_match(key, reg) == false)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "Неверно!" << endl;
        cout << "Введите ключ:" << endl;
        cin >> key;
    }

    return key;
}

int HashTable::inputNum()
{
    int num = 0;
    cout << "Введите номер элемента:" << endl;
    cin >> num;
    while (cin.fail() || (num < 0) || (num > (size - 1))) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "Неверно!" << endl;
        cout << "Введите ключ:" << endl;
        cin >> num;
    }
    return num;
}

void HashTable::Print()
{

    for (int i = 0; i < size; ++i)
    {
        cout << "Элемент " << i << endl;
        arr[i].ShowCell();
        cout << endl;
        cout << endl;
    }
}

void HashTable::del()
{
    int ch;
    cout << "Как вы хотите удалить (1-по ключу /2-по номеру)?" << endl;
    cin >> ch;
    while (cin.fail() || (ch < 1) || (ch > 2)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "Неверно!" << endl;
        cout << "Введите ключ:" << endl;
        cin >> ch;
    }

    if (ch == 1)
    {
        string key = inputKey();
        int hashindex = HashFunctionHorner(key, size, 3);

        if (arr[hashindex].removeAt(key))
        {
            cout << endl;
            cout << "Элемент удален" << endl;
            cout << endl;
        }
        else {
            cout << endl;
            cout << "Элемент не удален" << endl;
            cout << endl;
        }

    }
    else if (ch == 2) {
        int num = inputNum();
        arr[num].ShowCell();


        int select = 0;
        if (arr[num].GetSize() != 1) {
            cout << endl;
            cout << "Какой вы хотите удалить элемент по номеру?" << endl;

            cin >> select;
            while (cin.fail() || (select < 0) || (select > (size - 1))) {
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail(), '/n');
                cout << "Неверно!" << endl;
                cout << "Введите номер заново:" << endl;
                cin >> select;
            }
        }
        else { select = 0; }

        if (arr[num].removeAt(arr[num][select]))
        {
            cout << endl;
            cout << "Элемент удален" << endl;
            cout << endl;
        }
        else {
            cout << endl;
            cout << "Элемент не удален" << endl;
            cout << endl;
        }
    }



}