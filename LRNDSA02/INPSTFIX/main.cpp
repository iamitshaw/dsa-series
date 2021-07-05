#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get test_case */
    int32_t test_case;
    std::cin >> test_case;

    /* create priority_table */
    std::unordered_map<char, int16_t> priority {
            {'+', 12}, {'-', 12},
            {'*', 13}, {'/', 13},
            {'^', 14}
    };

    while (test_case--) {
        /* get length_of_infix_expression */
        int32_t length_of_infix_expression;
        std::cin >> length_of_infix_expression;

        /* get infix_expression */
        std::string infix_expression;
        std::cin >> infix_expression;

        /* create stack container */
        std::stack<char> s;

        for (const auto& character: infix_expression) {
            if (isalpha(character)) {
                /* if character is an operand */
                std::cout << character;
            } else if (character == ')') {
                /* if character is a right parenthesis */
                while (s.top() != '(') {
                    std::cout << s.top();
                    s.pop();
                }

                /* pop left parenthesis */
                s.pop();
            } else {
                if (character != '(') {
                    /* if character is an operator */
                    while (!s.empty() && s.top() != '(' &&
                    priority[s.top()] >= priority[character]) {
                        std::cout << s.top();
                        s.pop();
                    }
                }

                /* push character on top of stack */
                s.push(character);
            }
        }

        /* output characters until stack is empty  */
        while (!s.empty()) {
            std::cout << s.top();
            s.pop();
        }

        /* traverse cursor to next line */
        std::cout << std::endl;
    }
    return 0;
}