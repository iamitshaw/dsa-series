#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get N */
    int32_t N;std::cin >> N;

    /* get K */
    int32_t K;std::cin >> K;

    /* get array elements */
    std::vector<int32_t> array(N);
    for (int32_t i{0};i < N;i++) {
        std::cin >> array.at(i);
    }

    /* linear-search algorithm */
    bool is_found_K{false};
    for (int32_t i{0};i < N;i++) {
        if (array.at(i) == K) {
            is_found_K = {true};break;
        }
    }

    /* print message */
    std::cout << (is_found_K? "1": "-1");
    return 0;
}