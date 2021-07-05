#include <bits/stdc++.h>

/* get trailing-zeroes of factorial(number) */
int32_t trailing_zeroes(int32_t number) {
    /* initial values */
    int32_t divisor{5}, quotient{number/divisor};
    int32_t total_trailing_zeroes{0};

    /* obtain trailing-zeroes */
    while (quotient != 0) {
        total_trailing_zeroes += quotient;
        divisor *= 5;
        quotient = number/divisor;
    }
    return total_trailing_zeroes;
}

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get test_case */
    int32_t test_case;
    std::cin >> test_case;

    while (test_case--) {
        /* get number */
        int32_t number;
        std::cin >> number;

        /* print trailing_zeroes */
        std::cout << trailing_zeroes(number) << std::endl;
    }
    return 0;
}