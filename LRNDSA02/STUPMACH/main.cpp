#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get test_case */
    int32_t test_case;
    std::cin >> test_case;

    while (test_case--) {
        /* get number_of_boxes */
        int32_t number_of_boxes;
        std::cin >> number_of_boxes;

        /* get token_capacity_of_each_box */
        std::vector<int32_t> token_capacity_of_box(number_of_boxes);
        for (int32_t i{0}; i < number_of_boxes; i++) {
            std::cin >> token_capacity_of_box.at(i);
        }

        /* evaluate maximum_token_count
         * that can be placed into boxes */
        int64_t maximum_token_count{token_capacity_of_box.at(0)};
        int32_t minimum_token{token_capacity_of_box.at(0)};

        for (int32_t i{1};i < number_of_boxes;i++) {
            if (token_capacity_of_box.at(i) < minimum_token) {
                minimum_token = token_capacity_of_box.at(i);
            }
            /* update maximum_token_count */
            maximum_token_count += minimum_token;
        }
        /* print maximum_token_count */
        std::cout << maximum_token_count << std::endl;
    }
    return 0;
}