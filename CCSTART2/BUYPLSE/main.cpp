#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get number_of_pens */
    int32_t a;std::cin >> a;

    /* get number_of_pencils */
    int32_t b;std::cin >> b;

    /* get price_of_pen */
    int32_t x;std::cin >> x;

    /* get price_of_pencil */
    int32_t y;std::cin >> y;

    /* evaluate total_price */
    int32_t total_price{a*x + b*y};

    /* print message */
    std::cout << total_price << "\n";
    return 0;
}