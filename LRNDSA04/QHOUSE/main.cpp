#include <bits/stdc++.h>

int32_t binary_search(int32_t i, int32_t j, int32_t fixed_co_ordinate, bool is_search_for_x) {
    int32_t right_boundary{1000}, top_boundary{1000};
    while (i <= j) {
        int32_t mid{i + (j - i) / 2};
        std::string query_01, query_02;

        if (is_search_for_x) {
            std::fflush(stdout);
            std::cout << "? " << mid << " " << fixed_co_ordinate << std::endl;
            std::cin >> query_01;
            if(query_01 == "YES") {
                if (mid == right_boundary) {
                    return mid;
                } else {
                    std::fflush(stdout);
                    std::cout << "? " << mid + 1 << " " << fixed_co_ordinate << std::endl;
                    std::cin >> query_02;
                }
            }
        } else {
            std::fflush(stdout);
            std::cout << "? " << fixed_co_ordinate << " " << mid << std::endl;
            std::cin >> query_01;
            if(query_01 == "YES") {
                if (mid == top_boundary) {
                    return mid;
                } else {
                    std::fflush(stdout);
                    std::cout << "? " << fixed_co_ordinate << " " << mid + 1 << std::endl;
                    std::cin >> query_02;
                }
            }
        }

        /* if mid_point is inside house_boundary */
        if (query_01 == "YES") {
            if (query_02 == "NO") {
                /* if (mid+1)_point isn't
                 * inside house_boundary */
                return mid;
            } else {
                /* if (mid+1)_point is also
                 * inside house_boundary */
                i = {mid + 1};
            }
        } else {
            /* if mid_point is outside house_boundary */
            j = {mid - 1};
        }
    }
    return 0;
}

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int32_t x_left{1}, x_right{1000}, fixed_y{0};
    bool is_search_for_x{true};

    /* get X-co-ordinate of bottom-right corner of square */
    int32_t X {binary_search(x_left, x_right, fixed_y, is_search_for_x)};

    /* calculate area_of_square */
    int32_t area_of_square{4 * X * X};


    int32_t y_bottom{1}, y_top{1000}, fixed_x{0};
    is_search_for_x = {false};

    /* get Y-co-ordinate of triangle's top point */
    int32_t Y{binary_search(y_bottom, y_top, fixed_x, is_search_for_x)};
    int32_t height_of_triangle{Y - 2 * X};

    x_left = {X}, x_right = {1000}, fixed_y = {2 * X};
    is_search_for_x = {true};

    /* get X-co-ordinate of base's right point */
    int32_t base_of_triangle{binary_search(x_left, x_right, fixed_y, is_search_for_x)};

    /* calculate area_of_triangle */
    int32_t area_of_triangle{base_of_triangle * height_of_triangle};

    /* evaluate area_of_house */
    int32_t area_of_house{area_of_square + area_of_triangle};

    /* print appropriate message */
    fflush(stdout);
    std::cout << "! " << area_of_house << std::endl;
    return 0;
}