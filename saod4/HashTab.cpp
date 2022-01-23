#include "HashTab.h"

regex reg("([\\d]{3})([ABCDEFGHIJKLMNOPQRSTUVWXYZ]{1})([\\d]{2})");

int HashTable::HashFunctionHorner(const string& s, int table_size, const int key)// ���-������� ������ ������� ����� ����������,������ �������,
{
    int hash_result = 0;
    for (int i = 0; s[i] != 0; ++i)
    {
        hash_result = (key * hash_result + s[i]) % table_size; //������� �� ������ ��� � ��������
    }
    //hash_result = (hash_result * 2 + 1) % table_size;
    return hash_result; //����� ����� ����� � �������
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
    int hashindex = HashFunctionHorner(key, size, 3); //����������� ����� ������ ��� ����� ��������� ����
   
    if (arr[hashindex].hashexist(key))
    {
        cout << "����� ���� ��� ����������" << endl;
    }
    else { arr[hashindex].push_back(key); }
}

void HashTable::find()
{
    int ch;
    cout << "��� �� ������ ������ (1-�� ����� /2-�� ������)?" << endl;
    cin >> ch;
    while (cin.fail() || (ch < 1) || (ch > 2)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "�������!" << endl;
        cout << "������� ����:" << endl;
        cin >> ch;
    }

    if (ch == 1) {
        string key = inputKey();
        int hashindex = HashFunctionHorner(key, size, 3);

        if (arr[hashindex].hashexist(key))
        {
            cout << "������� " << hashindex << endl;
            arr[hashindex].ShowCell();
        }
        else { cout << "������ ����� ��� " << endl; }

    }
    else  if (ch == 2) {
        int num = inputNum();
        if (arr[num].GetSize() != 0) {
            arr[num].ShowCell();
        }
        else { cout << "������� �� ������" << endl; }
    }
}

string HashTable::inputKey()
{
    string key;
    cout << "������� ����:" << endl;
    cin >> key;
    while (cin.fail() || (key.size() != 6) || (regex_match(key, reg) == false)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "�������!" << endl;
        cout << "������� ����:" << endl;
        cin >> key;
    }

    return key;
}

int HashTable::inputNum()
{
    int num = 0;
    cout << "������� ����� ��������:" << endl;
    cin >> num;
    while (cin.fail() || (num < 0) || (num > (size - 1))) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "�������!" << endl;
        cout << "������� ����:" << endl;
        cin >> num;
    }
    return num;
}

void HashTable::Print()
{

    for (int i = 0; i < size; ++i)
    {
        cout << "������� " << i << endl;
        arr[i].ShowCell();
        cout << endl;
        cout << endl;
    }
}

void HashTable::del()
{
    int ch;
    cout << "��� �� ������ ������� (1-�� ����� /2-�� ������)?" << endl;
    cin >> ch;
    while (cin.fail() || (ch < 1) || (ch > 2)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "�������!" << endl;
        cout << "������� ����:" << endl;
        cin >> ch;
    }

    if (ch == 1)
    {
        string key = inputKey();
        int hashindex = HashFunctionHorner(key, size, 3);

        if (arr[hashindex].removeAt(key))
        {
            cout << endl;
            cout << "������� ������" << endl;
            cout << endl;
        }
        else {
            cout << endl;
            cout << "������� �� ������" << endl;
            cout << endl;
        }

    }
    else if (ch == 2) {
        int num = inputNum();
        arr[num].ShowCell();


        int select = 0;
        if (arr[num].GetSize() != 1) {
            cout << endl;
            cout << "����� �� ������ ������� ������� �� ������?" << endl;

            cin >> select;
            while (cin.fail() || (select < 0) || (select > (size - 1))) {
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail(), '/n');
                cout << "�������!" << endl;
                cout << "������� ����� ������:" << endl;
                cin >> select;
            }
        }
        else { select = 0; }

        if (arr[num].removeAt(arr[num][select]))
        {
            cout << endl;
            cout << "������� ������" << endl;
            cout << endl;
        }
        else {
            cout << endl;
            cout << "������� �� ������" << endl;
            cout << endl;
        }
    }



}