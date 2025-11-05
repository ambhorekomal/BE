#include <iostream>
using namespace std;

// Recursive function to get nth Fibonacci number
int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Iterative function to get nth Fibonacci number
int fib_iterative(int n) {
    if (n <= 1) return n;
    int prev1 = 1, prev2 = 0, current;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// Iterative function to print full Fibonacci series
void print_fib(int n) {
    if (n < 0) return;
    cout << "Fibonacci series up to " << n << ": ";
    int prev2 = 0, prev1 = 1, current;
    
    for (int i = 0; i <= n; i++) {
        if (i == 0) current = 0;
        else if (i == 1) current = 1;
        else {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        cout << current << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") using Iteration = " << fib_iterative(n) << endl;
    cout << "Fibonacci(" << n << ") using Recursion = " << fib_recursive(n) << endl;
    print_fib(n);

    return 0;
}
