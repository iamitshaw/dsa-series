#include <bits/stdc++.h>

/* driver-program */
int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get testCase */
    size_t testCase;
    std::cin >> testCase;

    /* loop through each testCase */
    while (testCase--) {
        /* get string */
        std::string string;
        std::cin >> string;

        int32_t length{(int32_t)string.length()};
        int32_t leftIndex{0}, rightIndex{length-1};

        /* create frequency-table */
        std::vector<int32_t> first_table(26, 0);
        std::vector<int32_t> second_table(26, 0);

        while (leftIndex < rightIndex) {
            first_table[string[leftIndex]-'a']++;
            second_table[string[rightIndex]-'a']++;
            leftIndex += 1;rightIndex -= 1;
        }

        /* check characters & its frequency */
        bool is_lapindrome{true};

        for (size_t i{0};i < 26;i++) {
            if (first_table[i] != second_table[i]) {
                is_lapindrome = {false};break;
            }
        }

        /* print message */
        std::cout << (is_lapindrome? "YES": "NO") << std::endl;
    }
    return 0;
}