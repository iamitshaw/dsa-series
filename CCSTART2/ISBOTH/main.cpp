#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get number */
    int32_t N;std::cin >> N;

    if ((N % 5 == 0) && (N % 11 == 0)) {
        std::cout << "BOTH\n";
    } else if ((N % 5 == 0) || (N % 11 == 0)) {
        std::cout << "ONE\n";
    } else {
        std::cout << "NONE\n";
    }
    return 0;
}