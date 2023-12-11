#include<iostream>
#include<vector>
#include <stdlib.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    std::vector<int> numbers((n+2)/2, 0); // para que sea 1-indexed con rango de al menos [1, n/2]   
    for (int i = 0; i < n/2; i++) {
        int current;
        cin >> current;
        if (current <= n/2) {
            numbers[current]++;
        } else {
            numbers[ abs(n + 1 - current)]++;
        }
    }
    for (int i = 1; i <= n / 2; i++) {
        if (numbers[i] != 1) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "SI" << std::endl;
    return 0;
}