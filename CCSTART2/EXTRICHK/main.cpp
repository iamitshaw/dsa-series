#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get first_side */
    int32_t a;std::cin >> a;

    /* get second_side */
    int32_t b;std::cin >> b;

    /* get third_side */
    int32_t c;std::cin >> c;

    /* print message */
    if (a+b > c && a+c > b && b+c > a) {
        /* if triangle formation is possible */
        if (a == b && b == c) {
            /* equilateral triangle
             * has each side equal */
            std::cout << "1\n";
        } else if (a==b || b==c || c==a) {
            /* isosceles triangle
             * has two sides equal */
            std::cout << "2\n";
        } else {
            /* scalene triangle has
             * each side unequal */
            std::cout << "3\n";
        }
    } else {
        /* if triangle can't be
         * formed from a, b, c */
        std::cout << "-1\n";
    }
    return 0;
}