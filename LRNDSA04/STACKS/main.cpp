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
        /* get number_of_disks */
        int32_t number_of_disks;
        std::cin >> number_of_disks;

        /* get disk radius */
        std::vector<int32_t> disk_radius(number_of_disks);
        for (int32_t i{0};i < number_of_disks;i++) {
            std::cin >> disk_radius.at(i);
        }

        /* evaluate number_of_stacks & stacks_top */
        int32_t number_of_stacks{0};
        std::vector<int32_t> stack_top;

        for (int32_t i{0};i < number_of_disks;i++) {
            auto it{std::upper_bound(stack_top.begin(),
                                     stack_top.end(),disk_radius.at(i))};
            if (it != stack_top.end()) {
                /* update stack_top with
                 * smaller radius disk */
                *it = disk_radius.at(i);
            } else {
                /* if disk radius is greater than
                 * every stacks top disk radius */
                stack_top.push_back(disk_radius.at(i));
                number_of_stacks += 1;
            }
        }

        /* print appropriate message */
        std::cout << number_of_stacks << " ";
        for (const auto& stack_top_radius: stack_top) {
            std::cout << stack_top_radius << " ";
        }
        /* move cursor to next-line */
        std::cout << "\n";
    }
    return 0;
}