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
        /* get number_of_row */
        int32_t number_of_row;
        std::cin >> number_of_row;

        /* get number_of_column */
        int32_t number_of_column;
        std::cin >> number_of_column;

        /* get number_of_plant_cells */
        int32_t number_of_plant_cell;
        std::cin >> number_of_plant_cell;

        /* get plant_cells location */
        std::set<std::pair<int32_t, int32_t>> plant_cell;

        int32_t row_cell, column_cell;
        for (int32_t i{0};i < number_of_plant_cell;i++) {
            std::cin >> row_cell;
            std::cin >> column_cell;

            plant_cell.insert({row_cell-1, column_cell - 1});
        }

        /* evaluate minimum fence */
        int32_t min_fence_required {0};
        auto cell_location{plant_cell.begin()};

        for (const auto& cell: plant_cell) {
            min_fence_required += 4;

            /* top neighbour */
            if ((cell.first - 1) >= 0) {
                cell_location=plant_cell.find({cell.first-1,cell.second});
                if (cell_location != plant_cell.end()) {
                    min_fence_required -= 1;
                }
            }
            /* bottom neighbour */
            if ((cell.first + 1) < number_of_row) {
                cell_location=plant_cell.find({cell.first+1,cell.second});
                if (cell_location != plant_cell.end()) {
                    min_fence_required -= 1;
                }
            }
            /* left neighbour */
            if ((cell.second - 1) >= 0) {
                cell_location=plant_cell.find({cell.first,cell.second-1});
                if (cell_location != plant_cell.end()) {
                    min_fence_required -= 1;
                }
            }
            /* right neighbour */
            if ((cell.second + 1) < number_of_column) {
                cell_location=plant_cell.find({cell.first,cell.second+1});
                if (cell_location != plant_cell.end()) {
                    min_fence_required -= 1;
                }
            }
        }

        /* print appropriate message */
        std::cout << min_fence_required << std::endl;
    }
    return 0;
}