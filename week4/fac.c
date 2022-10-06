int factorial(int n) {
    // 5 * 4 * 3 * 2 * 1
    int res = 1;

    while (n >= 1) {
        res = res * n ;
        n = n - 1;
    }

    return res;
}
