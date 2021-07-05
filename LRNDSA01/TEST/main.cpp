#include <bits/stdc++.h>

int32_t main(int32_t rgc,char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get number */
    int32_t number;

    /* process number until 42 is entered */
    while (std::cin >> number && number != 42) {
        std::cout << number << std::endl;
    }
    return 0;
}