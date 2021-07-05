
/* Include Guard */

#ifndef _GENERATE_DIGITS_H_
#define _GENERATE_DIGITS_H_

#include <bits/stdc++.h>

/* time-complexity - O(numberOfDigits) */
int main(int argc, char* argv[]) {

    /* get test-case */
    size_t testCase{0};
    std::cin >> testCase;

    /* navigate through each testCase */
    while (testCase--){

        /* get digit count */
        int64_t numberOfDigits;
        std::cin >> numberOfDigits;

        /* get most-significant-digits */
        size_t d0, d1;
        std::cin >> d0 >> d1;

        int64_t sumOfDigits{d0 + d1};

        /* generate digits-sum */
        for (int64_t i{2}; i < numberOfDigits; i++) {
            int64_t next_digit{sumOfDigits % 10};
            sumOfDigits += next_digit;
        }

        /* print result */
        std::cout << ((sumOfDigits%3 == 0)? "YES": "NO") << std::endl;
    }
    return 0;
}

#endif