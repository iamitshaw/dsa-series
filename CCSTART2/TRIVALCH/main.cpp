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

    /* check for triangle validity */
    if (a+b > c && a+c > b && c+b > a) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}