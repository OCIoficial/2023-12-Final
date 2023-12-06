#include<iostream>
#include<vector>
#include <numeric>

using namespace std;

int main() {
    u_int64_t n, c, v;
    cin >> n >> c >> v;
    u_int64_t lcm = std::lcm(c, v);
    string answer = (lcm / c <= n) && (lcm / v <= n) ? "SI" : "NO"; 
    std::cout << answer << std::endl;
    return 0;
}