#include <iostream>
#include <vector>

using namespace std;

// Function to compute the nth Fibonacci number
void fibonacci(int n) {
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Output the 100,000th Fibonacci number
    cout << "The 100,000th Fibonacci number is: " << fib[n] << endl;
}

int main() {
    int n = 100;
    fibonacci(n);
    return 0;
}
