#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get number */
    int32_t N;std::cin >> N;

    /* draw star-pattern */
    for (int32_t i{1};i <= N;i++) {
        for (int32_t j{1};j <= N;j++) {
            if (j <= N-i) {
                std::cout << " ";
            } else {
                std::cout << "*";
            }
        }
        /* move cursor to next-line */
        std::cout << "\n";
    }
    return 0;
}