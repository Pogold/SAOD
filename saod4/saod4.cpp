#include <string>
#include <iostream>
#include <fstream>
#include "HashTab.h"
using namespace std;

int getRandomNumber(int min, int max) //рандомная генерация 
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

string KeyGenerator() { //генератор ключей
    string key="      ";

    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    string nums = "0123456789";
;
  for (int i = 0; i < 6; i++)
        {
           
            int n = getRandomNumber(0,9);
            int let = getRandomNumber(0, 24);

            if(i==3){
                key[i] = letters[let];
            } else { key[i] = nums[n]; }
        }

    return key;
}

int inputCount() { // проверка на количество ключей
    int num = 0;
    cout << "Введите количество ключей для генерации:" << endl;
    cin >> num;
    while (cin.fail() || (num <= 0) ) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "Неверно!" << endl;
        cout << "Введите ключ:" << endl;
        cin >> num;
    }
    return num;

    return num;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int v = 0;

    HashTable H;
    string Keys;

    while (v!= 7)
    {
        cout << endl;
        cout << "Меню:" << endl;
        cout << "1.Заполнить хэш-таблицу" << endl;
        cout << "2.Добавить элемент" << endl;
        cout << "3.Удалить элемент" << endl;
        cout << "4.Вывод хэш-таблицы" << endl;
        cout << "5.Поиск элемента" << endl;
        cout << "6.Таблица коллизий" << endl;
        cout << "7.Выход" << endl;

        cin >> v;
        while (cin.fail() || (v <= 0) || (v > 8)) {
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail(), '/n');
            cout << "Неверно!" << endl;
            cout << "Введите заново:" << endl;
            cin >> v;
        }

        switch (v)
        {

        case 1: 
        {   int count = inputCount();
            for (int i = 0; i < count; i++)
        { H.add(KeyGenerator()); }
        cout << "Заполнение хэш-таблицы завершено." << endl;
        break;
        }

        case 2:
        { 
            string tempkey = H.inputKey();
        H.add(tempkey);
        cout << H.HashFunctionHorner(tempkey,H.GetSize(), 3) << ":  " << tempkey << endl;
        break;
        }

        case 3:
        {  H.del();
        break;
        }

        case 4:
        {
            cout << "Вывод таблицы:" << endl;
            H.Print();
            break;
        }

        case 5:
        {  H.find();
            break;
        }

        case 6:
        {
            string path = "table.txt";
                fstream fs;
                fs.open(path, fstream::out | fstream::in | fstream::trunc);
                if(!fs.is_open())
                {
                    cout << "Ошибка открытия файла" << endl;
                }else { cout << "Файл открыт" << endl; }
                
                for (int i = 0; i < H.GetSize(); i++)
                {
                    if(H.arr[i].GetSize()>=2)
                    { 
                    fs /*<< i << "   "*/ << H.arr[i].GetSize()-1 << "\n";
                    } else { fs /*<< i << "   "*/ << "0" << "\n"; }
                }
                cout << "Запись" << endl;
                fs.close();
                cout << "Файл закрыт" << endl;
            break;
        }

        case 7:
        {

            break;
        }

        default:
        {   cout << "Значение должно быть от 1 до 7!" << endl;  }
        }

    }
    return  0;
}

