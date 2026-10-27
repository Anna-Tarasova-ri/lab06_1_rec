// Масив a із 22 цілих елементів, значення з діапазону [-10; 35].
// Критерій: x > 0 або x не кратне 3.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;

// Критерій відбору елемента: додатний АБО не кратний 3
bool Satisfies(int x)
{
    return x > 0 || x % 3 != 0;
}

// Заповнює масив випадковими числами з діапазону [low; high], починаючи з індексу i
void Create(int a[], const int n, const int low, const int high, int i)
{
    if (i >= n)
        return;
    a[i] = low + rand() % (high - low + 1);
    Create(a, n, low, high, i + 1);
}

// Виводить елементи масиву, починаючи з індексу i (без переходу на новий рядок)
void Print(const int a[], const int n, int i)
{
    if (i >= n)
        return;
    cout << setw(4) << a[i];
    Print(a, n, i + 1);
}

// Повертає кількість елементів, що задовольняють критерій, починаючи з індексу i
int Count(const int a[], const int n, int i)
{
    if (i >= n)
        return 0;
    return (Satisfies(a[i]) ? 1 : 0) + Count(a, n, i + 1);
}

// Повертає суму елементів, що задовольняють критерій, починаючи з індексу i
int Sum(const int a[], const int n, int i)
{
    if (i >= n)
        return 0;
    return (Satisfies(a[i]) ? a[i] : 0) + Sum(a, n, i + 1);
}

// Замінює нулями елементи, що задовольняють критерій, починаючи з індексу i
void Zero(int a[], const int n, int i)
{
    if (i >= n)
        return;
    if (Satisfies(a[i]))
        a[i] = 0;
    Zero(a, n, i + 1);
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand((unsigned)time(NULL));

    const int n = 22;
    const int low = -10;
    const int high = 35;
    int a[n];

    Create(a, n, low, high, 0);
    cout << "Початковий масив:" << endl;
    Print(a, n, 0);
    cout << endl;

    // кількість і сума обчислюються ДО заміни елементів нулями
    cout << "Кількість елементів: " << Count(a, n, 0) << endl;
    cout << "Сума елементів: " << Sum(a, n, 0) << endl;

    Zero(a, n, 0);
    cout << "Модифікований масив:" << endl;
    Print(a, n, 0);
    cout << endl;

    return 0;
}