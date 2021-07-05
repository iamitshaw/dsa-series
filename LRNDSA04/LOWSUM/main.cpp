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
        /* get number_of_chefs */
        int32_t number_of_chefs;
        std::cin >> number_of_chefs;

        /* get number_of_queries */
        int32_t number_of_queries;
        std::cin >> number_of_queries;

        /* get chefs_motivation */
        std::vector<int64_t> chefs_motivation(number_of_chefs);
        for (int32_t i{0}; i < number_of_chefs;i++) {
            std::cin >> chefs_motivation.at(i);
        }

        /* get chefs_satisfaction */
        std::vector<int64_t> chefs_satisfaction(number_of_chefs);
        for (int32_t i{0};i < number_of_chefs;i++) {
            std::cin >> chefs_satisfaction.at(i);
        }

        /* sort chef_motivation & chefs_satisfaction */
        std::sort(chefs_motivation.begin(), chefs_motivation.end());
        std::sort(chefs_satisfaction.begin(), chefs_satisfaction.end());

        std::priority_queue<int64_t> pq;

        /* store smallest 10000 sum in
         * priority_queue if possible */
        for (const auto& motivation: chefs_motivation) {
            for (const auto& satisfaction: chefs_satisfaction) {
                int64_t temp_sum{motivation + satisfaction};
                if (pq.size() < 10000) {
                    /* if priority_queue has < 10000 elements */
                    pq.push(temp_sum);
                } else if (temp_sum < pq.top()) {
                    /* if smaller value is available than
                     * maximum element in priority_queue */
                    pq.pop();pq.push(temp_sum);
                } else {
                    /* no further temp_sum is going to
                     * be inserted into priority_queue */
                    break;
                }
            }
        }

        /* get set information v */
        std::vector<int64_t> v(pq.size());
        int64_t i{0};
        while (!pq.empty()) {
            v.at(i)=pq.top();
            pq.pop();i += 1;
        }

        /* process queries */
        while (number_of_queries--) {
            /* get index */
            int32_t index;
            std::cin >> index;

            /* print appropriate message */
            std::cout << v.at(v.size()-index) << "\n";
        }
    }
    return 0;
}