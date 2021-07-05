#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get number */
    int32_t N;std::cin >> N;

    /* evaluate factors_of_N */
    int32_t total_distinct_factors{0};
    std::vector<int32_t> factors_of_N;

    for (int32_t i{1};i <= N;i++) {
        if (N % i == 0) {
            total_distinct_factors += 1;
            factors_of_N.push_back(i);
        }
    }

    /* print message */
    std::cout << total_distinct_factors << "\n";

    for (const auto& factor: factors_of_N) {
        std::cout << factor << " ";
    }
    return 0;
}