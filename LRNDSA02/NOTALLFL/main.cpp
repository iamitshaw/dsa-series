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
        /* get total_cake_manufactured manufactured */
        int32_t total_cake_manufactured;
        std::cin >> total_cake_manufactured;

        /* get total_flavor_of_cake */
        int32_t total_flavor_of_cake;
        std::cin >> total_flavor_of_cake;

        /* create flavor_array */
        std::vector<int32_t> flavor_array(total_flavor_of_cake, 0);

        /* get cake_array */
        std::vector<int32_t> cake_array(total_cake_manufactured);
        for (int32_t i{0}; i < total_cake_manufactured; i++) {
            std::cin >> cake_array.at(i);
        }

        /* evaluate largest_subsegment */
        int32_t largest_subsegment{0};
        int32_t number_of_flavors_seen{0};
        int32_t temp_cake_subsegment{0};

        /* declare variable to store start
         * index of the current subsegment */
        int32_t j{0};

        for (int32_t i{0}; i < total_cake_manufactured; i++) {
            /* increase temp_cake_subsegment */
            temp_cake_subsegment += 1;

            if (flavor_array.at(cake_array.at(i) - 1) == 0) {
                /* if corresponding cake_flavor hasn't
                 * been seen in current subsegment */
                flavor_array.at(cake_array.at(i) - 1) += 1;
                number_of_flavors_seen += 1;

                /* if each flavor is inside subsegment */
                if (number_of_flavors_seen >= total_flavor_of_cake) {
                    do {
                        flavor_array.at(cake_array.at(j) - 1) -= 1;
                        temp_cake_subsegment -= 1;

                        /* decrease subsegment until a flavor
                         * isn't present in current subsegment */
                        if (flavor_array.at(cake_array.at(j) - 1) == 0) {
                            number_of_flavors_seen -= 1;

                            /* update start_index of current subsegment */
                            j += 1;break;
                        }

                        /* update start_index of current subsegment */
                        j += 1;
                    } while (true);
                }
            } else {
                flavor_array.at(cake_array.at(i) - 1) += 1;
            }

            /* if current subsegment is greater than
             * maximum subsegment found till now */
            if (temp_cake_subsegment > largest_subsegment) {
                largest_subsegment = temp_cake_subsegment;
            }
        }

        /* print appropriate message */
        std::cout << largest_subsegment << std::endl;
    }
    return 0;
}