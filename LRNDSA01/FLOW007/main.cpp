#include <bits/stdc++.h>

template <typename IntegerType>
IntegerType reverseNumber(IntegerType number) {
    IntegerType reverseValue{0};
    /* navigate through each digit */
    while (number != 0) {
        /* build reverseNumber */
        reverseValue = (reverseValue * 10) + (number % 10);

        /* eliminate processed digit */
        number /= 10;
    }
    return reverseValue;
}

int32_t main(int32_t argc, char* argv[]) {
    /* get test_case */
    int32_t test_case;
    std::cin >> test_case;

    while (test_case--) {
        /* get number */
        int32_t number;
        std::cin >> number;

        /* find out reverse number */
        std::cout << reverseNumber(number) << std::endl;
    }
    return 0;
}