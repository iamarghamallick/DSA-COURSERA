// #include <iostream>
// #include <vector>
// using std::vector;

// long long get_fibonacci_partial_sum_naive(long long from, long long to) {
//     long long sum = 0;

//     long long current = 0;
//     long long next  = 1;

//     for (long long i = 0; i <= to; ++i) {
//         if (i >= from) {
//             sum += current;
//         }

//         long long new_current = next;
//         next = next + current;
//         current = new_current;
//     }

//     return sum % 10;
// }

// int main() {
//     long long from, to;
//     std::cin >> from >> to;
//     std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
// }


#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long get_fibonacci_huge(long long n, long long m) {
    long long remainder = n % get_pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }
    return res % m;
}

int getLastDigitOfSum(long long n, long long m) {
    long long result = 0;
    for(int i=n; i<=m; i++) {
        result += get_fibonacci_huge(i, 10);
    }
    return result % 10;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << fibonacci_sum_naive(n);
    std::cout << getLastDigitOfSum(n, m) << '\n';
}