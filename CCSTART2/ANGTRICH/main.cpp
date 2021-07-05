#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get first_angle */
    int32_t a;std::cin >> a;

    /* get second_angle */
    int32_t b;std::cin >> b;

    /* get third_angle */
    int32_t c;std::cin >> c;

    /* print message */
    if (a>0 && b>0 && c>0 && a+b+c == 180) {
        /* if triangle is possible */
        std::cout << "YES\n";
    } else {
        /* if triangle isn't possible */
        std::cout << "NO\n";
    }
    return 0;
}