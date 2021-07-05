#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get N */
    int64_t N;std::cin >> N;

    /* determine sum_of_first N odd numbers */
    int64_t odd_numbers_total{N * N};

    /* determine sum_of_first N even numbers */
    int64_t even_numbers_total{N * (N + 1)};

    /* print message */
    std::cout << odd_numbers_total << " " ;
    std::cout << even_numbers_total << "\n";
    return 0;
}