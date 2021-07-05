#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get first_number */
    int32_t A;std::cin >> A;

    /* get second_number */
    int32_t B;std::cin >> B;

    /* get third_number */
    int32_t C;std::cin >> C;

    /* determine second_largest */
    int32_t second_max;
    if (A > B) {
        if (B > C) {
            second_max = B;
        } else {
            if (A > C) {
                second_max = C;
            } else {
                second_max = A;
            }
        }
    } else {
        if (A > C) {
            second_max = A;
        } else {
            if (B > C) {
                second_max = C;
            } else {
                second_max = B;
            }
        }
    }

    /* print message */
    std::cout << second_max << "\n";
    return 0;
}