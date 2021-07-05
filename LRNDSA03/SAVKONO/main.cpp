#include <bits/stdc++.h>

int32_t main(int32_t  argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get test_case */
    int32_t test_case;
    std::cin >> test_case;

    while (test_case--) {
        /* get number_of_soldiers */
        int32_t number_of_soldiers;
        std::cin >> number_of_soldiers ;

        /* get strength_of_pain */
        int32_t strength_of_pain;
        std::cin >> strength_of_pain;

        /* get strength_of_soldier in priority_queue */
        std::priority_queue<int32_t> priorityQueue;
        int32_t strength_of_soldier;

        for (int32_t i{0};i < number_of_soldiers;i++) {
            std::cin >> strength_of_soldier;
            priorityQueue.push(strength_of_soldier);
        }

        /* evaluate minimum_attack */
        int32_t minimum_attack{0};
        bool can_be_defeated{false};

        while (!priorityQueue.empty()) {
            /* get strength_of_soldier_to_fight pain */
            int32_t strength_of_soldier_to_fight{priorityQueue.top()};

            /* update number_of_attack happened */
            minimum_attack += 1;

            /* decrease strength_of_pain */
            strength_of_pain -= strength_of_soldier_to_fight;

            if (strength_of_pain <= 0) {
                /* if pain has been defeated then
                 * no further fight is required */
                can_be_defeated = {true};break;
            } else {
                priorityQueue.pop();

                /* if soldier is left with enough strength to fight */
                if ((strength_of_soldier_to_fight / 2) > 0) {
                    priorityQueue.push(strength_of_soldier_to_fight / 2);
                }
            }
        }

        /* print appropriate message */
        if (can_be_defeated) {
            std::cout << minimum_attack << std::endl;
        } else {
            std::cout << "Evacuate" << std::endl;
        }
    }
    return 0;
}