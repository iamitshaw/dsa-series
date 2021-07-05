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
        /* get number_of_activities */
        int32_t number_of_activities;
        std::cin >> number_of_activities;

        /* get users_origin */
        std::string users_origin;
        std::cin >> users_origin;

        /* evaluate total_laddu_earned */
        int32_t total_laddu_earned{0};

        while (number_of_activities--){
            /* get user_activity */
            std::string user_activity;
            std::cin >> user_activity;

            if (user_activity == "CONTEST_WON") {
                /* contest-won */
                size_t rank;
                std::cin >> rank;

                /* for contest-won */
                total_laddu_earned += 300;

                /* for bonus if any */
                if (rank <= 20) {
                    total_laddu_earned += (20 - rank);
                }
            } else if (user_activity == "TOP_CONTRIBUTOR") {
                /* top contributor on discussion board */
                total_laddu_earned += 300;
            } else if (user_activity == "BUG_FOUND") {
                /* bug-finding */
                size_t severity;
                std::cin >> severity;
                total_laddu_earned += severity;
            } else if (user_activity == "CONTEST_HOSTED") {
                /* contest-hosted */
                total_laddu_earned += 50;
            } else {
                /* throw a runtime_error */
                assert(false);
            }
        }

        if (users_origin == "INDIAN") {
            /* maximum month for indian users */
            std::cout << (total_laddu_earned / 200) << std::endl;
        } else {
            /* maximum month for non-indian users */
            std::cout << (total_laddu_earned / 400) << std::endl;
        }
    }
    return 0;
}