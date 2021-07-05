#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get number_of_chefs */
    int32_t number_of_chefs;
    std::cin >> number_of_chefs;

    /* get total_seniority_levels */
    int32_t total_seniority_levels;
    std::cin >> total_seniority_levels;

    /* get seniority_of_chefs in queue */
    auto* seniority_of_chefs = new int32_t[number_of_chefs];
    for (int32_t i{0};i < number_of_chefs;i++) {
        std::cin >> seniority_of_chefs[i];
    }

    const int32_t modulo_value{1000000007};
    int64_t total_fearfulness{1};

    std::stack<std::pair<int32_t, int32_t>> s;

    for (int32_t i{number_of_chefs - 1};i >= 0;i--) {
        while (!s.empty() && seniority_of_chefs[i] <= s.top().first) {
            s.pop();
        }

        if (s.empty()) {
            /* empty stack signifies junior chef isn't
             * present for chef under consideration */
            total_fearfulness *= 1;
        } else {
            /* non-empty stack signifies that junior chef
             * is present for chef under consideration */
            total_fearfulness = ((total_fearfulness % modulo_value) *
                    ((s.top().second - i + 1) % modulo_value)) % modulo_value;
        }
        s.push({seniority_of_chefs[i], i});
    }

    /* print appropriate message */
    std::cout << total_fearfulness << std::endl;

    /* de-allocate heap memory */
    delete [] seniority_of_chefs;

    return 0;
}