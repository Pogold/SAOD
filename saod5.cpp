#include <iostream>
#include <cmath>

using namespace std;


int getRandomNumber(int min, int max) //рандомная генерация 
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


int inputNum() { // проверка числа
    int num = 0;
    cin >> num;
    while (cin.fail() || (num <= 0)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "Неверно!" << endl;
        cout << "Введите заново:" << endl;
        cin >> num;
        return num;
    }


    return num;
}

void Fill(int *arr, int size) { // проверка числа

    for (int i = 0; i < size; i++)
    {
        
        int n = getRandomNumber(1, 99);
        arr[i]=n;
    }
    cout << "Массив заполнен" << endl;
}

void Find(int size,int* arr)
{
    cout << "Как вы хотите искать?(1-по номеру элемента/2-по значению)" << endl;
    int ch= inputNum();

    if ((ch != 1) && (ch != 2))
    {
        cout << "Неверно" << endl;
        return;
    }

    if (ch == 2)
    {
        cout << "Введите значение:" << endl;
        int f = inputNum();
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == f)
            {
                cout << i << ":  " << arr[i] << endl;
            }
        }
    } else if (ch == 1) {
        cout << "Введите номер:" << endl;
        int n= inputNum();
        if ( (n <0) || (n>size) )
        {
            cout << "Неверно" << endl;
            return;
        }
        else { cout << n << ":  " << arr[n] << endl; }
       
    }

}

// Сортировка расческой

void comb(int* data, int size)
{
    double factor = 1.2473309; // фактор уменьшения
    double step =(size-1); // шаг сортировки
    int temp=0;
    int count = 0;
    int srav = 0;
    while (step >= 1)
    {
        for (int i = 0; i + round(step) < size; i++)
        {
            int stepi = (round(i + step));
            if (data[i] > data[stepi])
            {
                temp = data[i];
                data[i] = data[stepi];
                data[stepi] = temp;
                count++;
            }
            srav++;
        }
        step /= factor;
    }
    cout << endl;
    cout << "Сортировка выполнена" << endl;
    cout << "Количество перестановок " << count <<endl;
    cout << "Количество сравнений " << srav << endl;
}

void del(int *&arr, int& size)
{
    if (size !=1){
    size--;
    int* newArray = new int[size];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i];
    }
    
    delete[] arr;
    arr = newArray;
    cout << "Элемент удален" << endl;
    }else { cout << "В массиве не может быть 0 элементов" << endl; }
}

void count(int*& arr, int& size)
{
    comb(arr, size);
    int count=0;
    cout << endl;
    cout << "Количество повторяющихся элементов:"  << endl;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                count++;
            }
            else  { cout << arr[i] << ":" << count+1 << endl; 
            count = 0;
            };
        }

 
       
   
}

void add(int *&arr, int& size)
{
    int v = 0;
    cout << "Введите значения элемента:" << endl;
    cin >> v;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), '/n');
        cout << "Неверно!" << endl;
        cout << "Введите заново:" << endl;
        cin >> v;
    }

    int *newArray = new int[size+1];

    for (int i = 0; i < size; i++)
    {     
        newArray[i] = arr[i];  
    }

    newArray[size] = v;
    size++; 
    delete[] arr;
    arr = newArray;
    cout << "Элемент добавлен" << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int v = 0;
    cout << "Введите количество элементов в массиве:" << endl;
    int size = inputNum();
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {  
        arr[i] = 0;
    }

    while (v != 8)
    {
        cout << endl;
        cout << "Меню:" << endl;
        cout << "1.Заполнить массив" << endl;
        cout << "2.Добавить элемент" << endl;
        cout << "3.Удалить элемент" << endl;
        cout << "4.Вывод массива" << endl;
        cout << "5.Поиск элемента" << endl;
        cout << "6.Сортировка" << endl;
        cout << "7.Вывод количества повторяющихся элементов" << endl;
        cout << "8.Выход" << endl;
        cout << endl;
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
        {   
          Fill(arr, size);   
        break;
        }

        case 2:
        {add(arr,size);
            break;
        }

        case 3:
        {  del(arr, size);
        break;
        }

        case 4:
        {
            cout << "Массив" << endl;
            for (int i = 0; i < size ; i++)
            {  
                cout << i <<":  " << "\t" << arr[i] <<endl ;
            }
            break;
        }

        case 5:
        {  Find(size, arr);
        break;
        }

        case 6:
        {
            comb(arr, size);
            break;
        }

        case 7:
        {count(arr, size);
            break;
        }


        case 8:
        {count(arr, size);
            break;
        }
        default:
        {   cout << "Значение должно быть от 1 до 8!" << endl;  }
        }

    }
    return  0;

    delete[] arr;
}



