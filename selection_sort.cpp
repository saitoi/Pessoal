#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void selection_sort(int *a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (a[j] < a[i])
                swap(a[i], a[j]);
}

int main(void) {
    int a[5] = {5, 4, 3, 2, 1};
    selection_sort(a, 5);

    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}