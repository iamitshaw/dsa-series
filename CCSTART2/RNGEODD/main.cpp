#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get left_bound */
    int32_t left;std::cin >> left;

    /* get right_bound */
    int32_t right;std::cin >> right;

    /* let left_bound start
     * at odd index element */
    if (left % 2 == 0) {
        left += 1;
    }

    /* print odd elements */
    for (int32_t i{left}; i <= right; i += 2) {
        std::cout << i << " ";
    }
    return 0;
}