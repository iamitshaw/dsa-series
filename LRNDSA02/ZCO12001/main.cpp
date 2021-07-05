#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get length_of_bracket_sequence */
    int32_t bracket_sequence_length;
    std::cin >> bracket_sequence_length;

    /* get bracket sequence expression */
    std::vector<int16_t> bracket_expression(bracket_sequence_length);
    for (int32_t i{0}; i < bracket_sequence_length; i++) {
        std::cin >> bracket_expression.at(i);
    }

    std::stack<char> s;

    /* evaluate max_nesting_depth & max_sequence_length */
    int32_t max_nesting_depth{0},first_position_of_max_depth{0};
    int32_t max_sequence_length{0},first_position_of_max_length{0};
    int32_t temp_nesting_depth{0},temp_sequence_length{0};

    for (int32_t i{0}; i < bracket_sequence_length; i++) {
        /* increase temp_sequence_length */
        temp_sequence_length += 1;

        if (bracket_expression[i] == 1) {
            s.push('(');

            /* increase temp_nesting_depth */
            temp_nesting_depth += 1;

            if (temp_nesting_depth > max_nesting_depth) {
                /* update maximum_nesting_depth information */
                max_nesting_depth = temp_nesting_depth;
                first_position_of_max_depth = i;
            }
        } else {
            s.pop();temp_nesting_depth -= 1;

            /* if stack container is empty */
            if (s.empty()) {
                if (temp_sequence_length > max_sequence_length) {
                    /* update maximum sequence length information */
                    max_sequence_length = temp_sequence_length;
                    first_position_of_max_length = (i - temp_sequence_length + 1);
                }

                /* update length_sequence_count */
                temp_sequence_length = 0;
            }
        }
    }

    /* print appropriate message */
    std::cout << max_nesting_depth << " " << (first_position_of_max_depth + 1) << " ";
    std::cout << max_sequence_length << " " << (first_position_of_max_length + 1) << "\n";

    return 0;
}