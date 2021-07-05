#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /*get number_of_points */
    int32_t number_of_points;
    std::cin >> number_of_points;

    /* after adding dummy points */
    number_of_points *= 2;const int32_t upper_limit {500};

    /* get coOrdinates of points */
    auto* coOrdinatePoint = new std::pair<int32_t, int32_t>[number_of_points];
    for (int32_t i{0};i < number_of_points;i += 2) {
        std::cin >> coOrdinatePoint[i].first;
        std::cin >> coOrdinatePoint[i].second;

        /* dummy points are added for each
         * specified point at upper_boundary */
        coOrdinatePoint[i+1].first = coOrdinatePoint[i].first;
        coOrdinatePoint[i+1].second = upper_limit;
    }

    /* sort coOrdinate points based on x-coOrdinate */
    std::sort(coOrdinatePoint, (coOrdinatePoint + number_of_points));

    /* information on stack: {index, y-coOrdinate} */
    std::stack<std::pair<int32_t, int32_t>> s;

    /* get right-boundary_value of x-coOrdinate for each point */
    auto* right_boundary = new int32_t[number_of_points];

    const int32_t right_limit {100000};

    for (int32_t i{0};i < number_of_points;i++) {
        while (!s.empty() && s.top().second > coOrdinatePoint[i].second) {
            right_boundary[s.top().first] = coOrdinatePoint[i].first;
            s.pop();
        }
        s.push({i, coOrdinatePoint[i].second});
    }

    /* for left_over points */
    while (!s.empty()) {
        right_boundary[s.top().first] = right_limit;
        s.pop();
    }

    /* get left-boundary_value of x-coOrdinate for each point */
    auto* left_boundary = new int32_t[number_of_points];

    const int32_t left_limit {0};

    for (int32_t i{number_of_points-1};i >= 0;i--) {
        while (!s.empty() && s.top().second > coOrdinatePoint[i].second) {
            left_boundary[s.top().first] = coOrdinatePoint[i].first;
            s.pop();
        }
        s.push({i, coOrdinatePoint[i].second});
    }

    /* for left_over points */
    while (!s.empty()) {
        left_boundary[s.top().first] = left_limit;
        s.pop();
    }

    /* obtain maximum area out of useful rectangles */
    int32_t max_area{0};

    for (int32_t i{0};i < number_of_points;i++) {
        /* evaluate width and height of rectangle */
        int32_t width{right_boundary[i] - left_boundary[i]};
        int32_t height{coOrdinatePoint[i].second};

        /* evaluate temp_area of rectangle */
        int32_t temp_area{width * height};

        /* find maximum area of rectangle */
        max_area = {std::max(max_area, temp_area)};
    }

    /* print appropriate message */
    std::cout << max_area << std::endl;

    /* de-allocate heap-memory */
    delete [] coOrdinatePoint;

    return 0;
}