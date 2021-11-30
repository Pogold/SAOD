// saod2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

    void pop_front();//удаление первого  элемента 
    void pop_back();//удаление последнего  элемента 
    void push_back(T data); //добавление элемента в конец списка
    int GetSize() { return Size; }; //нахождение кол-ва элементов  в списке
    void clear();//очистка списка
    T& operator[] (const int index );//поиск элемента
    void push_front(T data); //вставка ноды в начало
    void insert(T value, int index); //вставка внутрь списка
    void removeAt(int index);//удаление элемента по индексу

    void input(); //интерфейс
    void add();
    void del();

private:

    template<typename T> //создание шаблоного класса

    class Node // класс узла
    {
    public:
        Node *pNext;//указатель на следующий узел
        T data; //значение узла

        Node(T data = T(), Node* pNext = nullptr) // конструктор ноды присваение значения и адреса
        {
            this->data = data;
            this->pNext = pNext;
        };

    };

    int Size;
    Node<T> *head; //голова списка первый элемент
};

template<typename T>
List<T>::List() //конструктор списка
{
    Size = 0;
    head = nullptr;
}

template<typename T>//деструктор списка
List<T>::~List()
{
    cout << "Произошел деструктор."<<endl;
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head; //временная нода для удаления (записываем в переменную изначальную голову)
    head = head->pNext;//теперь голова следующий элемент от старой головы
    delete temp; //удалить старую голову
    Size--; //уменишаем размер списка на один так как удаляем голову

}

template<typename T>
void List<T>::pop_back() //удаление последнего элемента
{
    removeAt(Size - 1);
}

template<typename T>
void List<T>::push_back(T data) //добавление элемента в конец списка
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;
        while(current->pNext!=nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
void List<T>::clear()
{
    while (Size)// когда число равно 0=false (так как в вайле булевая переменная) в остальных случаях (!-=0) тру

    {
        pop_front();
    }
}

template<typename T>
T& List<T>::operator[](const int index ) //поиск элемента
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data,head); //присваем новой голове адрес старой и вводим данные для нее
    Size++;

}

template<typename T>
void List<T>::insert(T value, int index)
{ if(index==0)
{
    push_front(value);
}
else {
    Node<T>* previous = this->head; //временный указатель

    for (int i = 0; i < index - 1; i++)// находим адрес предыдущего элемента от которого хотим заменить
    {
        previous = previous->pNext;
    }
    Node<T>* newNode = new Node<T>(value, previous->pNext); //создаем ноду 
    previous->pNext = newNode;//заполняем адрес для нового элемента
    Size++;
}


}

template<typename T>
void List<T>::removeAt(int index) //удаление элемента по индексу
{
    if(index==0)
    {
        pop_front();
    }
    else {

        Node<T>* previous = this->head; //временный указатель

        for (int i = 0; i < index - 1; i++)// находим адрес предыдущего элемента от которого хотим заменить
        {
            previous = previous->pNext;
        }
        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
void List<T>::input()
{
    int s = 0;
    clear();
    cout << "Введите количество элементов в списке:";
    cin >> s;

    if (s>0){
    int  value = 0;
    for (int i = 0; i < s; i++)
    {
        cout << "Введите значение [" << i << "] элемента:";
        cin >> value;
        push_back(value);
    }

    } 
    else { cout << "В списке должен быть хотя бы 1 элемент!" << endl; }
}

template<typename T>
void List<T>::add()
{
    int n = 0, val = 0;
    cout << "Введите номер элемента для вставки:";
    cin >> n;

    if ((n > 0) && (n <= (GetSize()+1)))
    {
        cout << "Введите значение элемента для вставки:";
        cin >> val;
        insert(val, n);
    }
    else { cout << "Некорректно!" << endl; }
    

}

template<typename T>
void List<T>::del()
{
int n = 0;
cout << "Введите номер элемента,который хотите удалить:";
cin >> n;
if((n>=0) && (n <=GetSize()))
{
    removeAt(n);
}
else { cout << "Некорректно!" << endl; }
}

int main()
{
    setlocale(LC_ALL, "ru");//подключаем русский язык
    
    List<int> lst; //создание списка
    int f = 1;

    while(f!=0)
    {
        cout << "Меню:" << endl;
        cout << "1.Заполнить список"<<endl;
        cout << "2.Добавить элемент" << endl;
        cout << "3.Удалить элемент" << endl;
        cout << "4.Отсортированный массив" << endl;
        cout << "5.Вывод списка" << endl;
        cout << "6.Выход" << endl;

        int v=0;

        cin >> v;
        switch (v)
        {

        case 1:
        {   lst.input();
            break;
        
        }

        case 2:
        { lst.add();
        break;
        }

        case 3:
        { lst.del();
        break;
        }

        case 4:
        {  

            if(lst.GetSize()==0){ cout << "Список пуст." << endl; }
            else{ cout << "Последовательности четных и нечетных элементов:" << endl; }

        for (int i = 0; i <= (lst.GetSize()-1); i++)
        {
            if (lst[i] % 2 == 0)
            {
                
                cout << lst[i] << ' ';
            }
        }
        cout << endl;

        for (int i = 0; i <= (lst.GetSize() - 1); i++)
        {
            if (lst[i] % 2 != 0)
            {
                
                cout << lst[i] << ' ';
            }
        }
        cout << endl;
        break;
        }

        case 5:
        {  
            if (lst.GetSize() == 0) 
        { cout << "Список пуст" << endl; }

        else 
        { cout << "Вывод списка:" << endl; }
            for (int i = 0; i < lst.GetSize(); i++)
            {
                cout <<  "Значение [" << i << "] элемента:" << lst[i] <<endl;
            }
            break;
        }

        case 6:
        {  
         f = 0;
        break;
        }

        default:
        {
            cout << "Значение должно быть от 1 до 7!" << endl;
        }

        }

    }

    return 0;
}