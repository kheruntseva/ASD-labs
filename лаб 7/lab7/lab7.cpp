#include <iostream>
using namespace std;

int main() 
{

    setlocale(LC_ALL, "Rus");

    int N;
    cout << "Введите количество элементов: ";
    cin >> N;

    if (N <= 0) 
    {
        cout << "Последовательность должна содержать хотя бы один элемент." << endl;
        return 1;
    }

   
    int* arr = new int[N];
    int* dp = new int[N]; //макс. длина лис, которая заканчивается на текущем элементе
    int* prev = new int[N]; //индексы предыдущих элементов

    cout << "Введите элементы последовательности: ";
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
        dp[i] = 1;    
        prev[i] = -1;    
    }

    int maxLength = 1, lastIndex = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLength)
        {
            maxLength = dp[i];
            lastIndex = i;
        }
    

    }

    int* lis = new int[maxLength];
    int index = maxLength - 1;
    while (lastIndex != -1) 
    {
        lis[index--] = arr[lastIndex];
        lastIndex = prev[lastIndex];
    }

    cout << "Длина LIS: " << maxLength << endl;
    cout << "LIS: ";
    for (int i = 0; i < maxLength; i++) 
    {
        cout << lis[i] << " ";
    }
    cout << endl;

  
    delete[] arr;
    delete[] dp;
    delete[] prev;
    delete[] lis;

    return 0;
}
