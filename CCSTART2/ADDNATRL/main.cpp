#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get number */
    int64_t N;std::cin >> N;

    /* determine sum_of_first
     * [N] natural numbers */
    int64_t total_sum{(N*(N+1))/2};

    /* print message */
    std::cout << total_sum << "\n";
    return 0;
}