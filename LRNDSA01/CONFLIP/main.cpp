#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get test_case */
    int32_t test_case;
    std::cin >> test_case;

    while (test_case--) {
        /* get number_of_games */
        int32_t number_of_games;
        std::cin >> number_of_games;

        while (number_of_games--) {
            /* get initial_state_of_coins */
            int32_t initial_state_of_coins;
            std::cin >> initial_state_of_coins;

            /* get number_of_coins */
            int32_t number_of_coins;
            std::cin >> number_of_coins;

            /* get query_on_coin_face */
            int32_t query_on_coin_face;
            std::cin >> query_on_coin_face;

            /* evaluate head_faced_coins & tail_faced_coins */
            int32_t head_faced_coins;
            int32_t tail_faced_coins;

            if (number_of_coins % 2 == 0) {
                /* if number_of_coins are even */
                head_faced_coins = number_of_coins / 2;
                tail_faced_coins = number_of_coins / 2;
            } else {
                /* if number_of_coins are odd */
                if (initial_state_of_coins == 1) {
                    head_faced_coins = (number_of_coins - 1) / 2;
                    tail_faced_coins = (number_of_coins + 1) / 2;
                } else {
                    head_faced_coins = (number_of_coins + 1) / 2;
                    tail_faced_coins = (number_of_coins - 1) / 2;
                }
            }

            /* print appropriate message */
            if (query_on_coin_face == 1) {
                std::cout << head_faced_coins << std::endl;
            } else {
                std::cout << tail_faced_coins << std::endl;
            }
        }
    }
    return 0;
}