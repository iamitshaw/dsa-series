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
        /* get number_of_food_type
         * available in ChefLand */
        int32_t number_of_food_type;
        std::cin >> number_of_food_type;

        /* allocate heap-memory */
        auto* number_of_stores = new int32_t[number_of_food_type];
        auto* cost_of_food = new int32_t[number_of_food_type];
        auto* number_of_people = new int32_t[number_of_food_type];

        /* get number_of_stores, number_of_people, cost_of_food */
        for (int32_t i{0}; i < number_of_food_type; i++) {
            std::cin >> number_of_stores[i];
            std::cin >> number_of_people[i];
            std::cin >> cost_of_food[i];
        }

        /* evaluate max_profit */
        int32_t max_profit{0};
        for (int32_t i{0}; i < number_of_food_type; i++) {
            int32_t people_at_each_store {number_of_people[i]/(number_of_stores[i] + 1)};
            int32_t profit_with_ith_food_type{people_at_each_store * cost_of_food[i]};

            /* if profit_with_ith_food_type obtained
             * is greater than max_profit then update */
            if (profit_with_ith_food_type > max_profit) {
                max_profit = profit_with_ith_food_type;
            }
        }

        /* print max_profit */
        std::cout << max_profit << std::endl;

        /* de-allocate heap memory */
        delete [] number_of_stores;
        delete [] cost_of_food;
        delete [] number_of_people;
    }
    return 0;
}