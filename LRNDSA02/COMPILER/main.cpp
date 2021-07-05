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
        /* get expression_string */
        std::string expression_string;
        std::cin >> expression_string;

        /* evaluate longest_valid_prefix */
        std::stack<char> s;int32_t longest_valid_prefix{0};
        uint32_t string_length{expression_string.length()};
        for (int32_t i{0};i < string_length;i++) {
            if (expression_string.at(i) == '<') {
                /* if character is opening_bracket */
                s.push(expression_string.at(i));
            }else {
                /* if  character is closing bracket */
                if (!s.empty()) {
                    /* if its corresponding opening
                     * bracket has available in stack */
                    s.pop();
                    if (s.empty()) {
                        /* update longest_valid_prefix value since
                         * expression_string is valid till index i */
                        longest_valid_prefix = {i + 1};
                    }
                }else {
                    break;
                }
            }
        }
        /* print longest_valid_prefix of expression_string */
        std::cout << longest_valid_prefix << std::endl;
    }
    return 0;
}