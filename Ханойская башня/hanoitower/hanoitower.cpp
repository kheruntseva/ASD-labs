#include <iostream>
using namespace std;

void hanoi(int n, int from, int to, int other) {
    setlocale(LC_ALL,"rus");
    if (n == 1) {
        cout << "Переместить диск 1 с " << from << " на " << to << " стержень\n";
        return;
    }

    hanoi(n - 1, from, other, to);

    cout << "Переместить диск " << n << " с " << from << " на " << to << " стержень\n";

    hanoi(n - 1, other, to, from);
}

int main() {
    setlocale(LC_ALL, "rus");
    int N, k;

    cout << "Введите количество дисков N: ";
    cin >> N;

    cout << "Введите номер конечного стержня k (2 или 3): ";
    cin >> k;

    if (k < 2 || k > 3) {
        cout << "Номер стержня должен быть 2 или 3.\n";
        return 1;
    }

    int i = 1;
    int vspog = 5 - k;

    hanoi(N, i, k, vspog);

    return 0;
}