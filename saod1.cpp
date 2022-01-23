#include <iostream>
#include <cstdlib>

using namespace std;

const int n = 30;
void counti(int a[n]);
void input(int a[n]);
void method10(int a[n]);

int main()
{
    int ch, a[n];
    input(a);
    cout << "Choose function(1-counti , 2- method10):\n";
    cin >> ch;

    if (ch == 1) {
        counti(a);
    }
    if (ch == 2) {
        method10(a);
    }

    return 0;

}

void counti(int a[n])
{
    int i, c = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            c++;
        }
    }

    cout << "Count of odd elements is " << c;
}

void input(int a[n])
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }

    for (i = 0; i < n; i++)
    {
        cout << "a[" << i << "]=" << a[i] << " \n";;
    }
    cout << "Input done!\n";
}

void method10(int a[n])
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (a[i] % 10 == 0)
        {
            a[i] /= 10;
        }
    }

    for (i = 0; i < n; i++)
    {
        cout << "a[" << i << "]=" << a[i] << " \n";
    }
}
