#include <bits/stdc++.h>

/* time-complexity - O(1) */
int main(int argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get test_case */
    int32_t test_case{0};
    std::cin >> test_case;

    while (test_case--) {
        /* get digit_count */
        int64_t number_of_digits;
        std::cin >> number_of_digits;

        /* get most_significant_digits */
        int32_t d0, d1;
        std::cin >> d0 >> d1;

        /* get sum_of_initial_two_digits */
        int32_t sum_of_digits{d0 + d1};int64_t total_sum{0};

        if (number_of_digits == 2) {
            total_sum = sum_of_digits;
        } else {
            /* get sum_of_non_cyclic_digits */
            int32_t initial_sum{sum_of_digits + sum_of_digits % 10};

            /* get number of complete cycles */
            int64_t number_of_cycles{(number_of_digits - 3) / 4};

            /* get cycle_digits */
            int32_t first_term{(2 * sum_of_digits) % 10};
            int32_t second_term{(4 * sum_of_digits) % 10};
            int32_t third_term{(8 * sum_of_digits) % 10};
            int32_t fourth_term{(6 * sum_of_digits) % 10};

            /* get cycle-sum */
            int64_t cycle_sum{number_of_cycles*(first_term+second_term+third_term+fourth_term)};

            /* get left-over-digits */
            int64_t left_over_digits{number_of_digits - ((number_of_cycles * 4) + 3)};

            /* initialize left-over-sum */
            int32_t index{2}, left_over_sum{0};

            /* obtain left-over-sum */
            for (int64_t i{1}; i <= left_over_digits; i++) {
                left_over_sum += (index * sum_of_digits) % 10;index *= 2;
            }

            /* evaluate digits_sum */
            total_sum = {initial_sum + cycle_sum + left_over_sum};
        }

        /* print appropriate result */
        std::cout << ((total_sum%3 == 0)? "YES": "NO") << std::endl;
    }
    return 0;
}