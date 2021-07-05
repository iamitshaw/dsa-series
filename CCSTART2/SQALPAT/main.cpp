#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get N */
    int32_t N;std::cin >> N;

    /* draw specified-pattern */
    for (int32_t i{1};i <= N;i++) {
        if (i % 2 != 0) {
            /* if odd-row is processed */
            for (int32_t j{1};j <= 5;j++) {
                /* each column has 5 elements */
                std::cout << (i-1)*5 + j << " ";
            }
        } else {
            /* if even-row is processed */
            for (int32_t j{5};j >= 1;j--) {
                /* each column has 5 elements */
                std::cout << (i-1)*5 + j << " ";
            }
        }

        /* move cursor to next line */
        std::cout << "\n";
    }
    return 0;
}