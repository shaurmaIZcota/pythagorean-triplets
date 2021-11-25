#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>
using namespace std;


bool is_prime(int a) {
    if (a == 2) { return true; }
    if (a % 2 == 0 ) { return false; }
    for (int i = 3; i <= sqrt(a); i += 2) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}



bool is_reciprocal(int a, int b) {
    if (a % b == 0 || b % a == 0) { return false; }
    if (!is_prime(a + b)) { return false; }
    return true;
}


int main()
{
    long int max;
    
    setlocale(LC_ALL, "Russian");
    cout << "Программа вычисления пифагоровых троек\n";
    cout << "Введите максимальное число: ";
    cin >> max;
    int *arr = new int[max];
    int j;
    double sum, k;
    long long int x, y, z;
    for (int i = 1; i <= max*max; i++) {
        for (j = i; j <= max*max; j++){
            if (is_reciprocal(i, j)) {
                x = 2*i*j;
                y = abs(i*i-j*j);
                z = i*i+j*j;
                cout << "{" << x << ";" << y << ";" << z << "}" << endl;
                if (x * x + y * y == z * z) {
                    cout << "Проверка пройдена"<<endl;
                }
                else { 
                    cout << "Ошибка!" << endl;
                    system("pause");
                }
                if (z < 0) {
                    cout << "Переполнение буфера" << endl;
                    system("pause");
                }
            }
        }
    }

    system("pause");
}
