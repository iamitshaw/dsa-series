#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get number_of_contests */
    int32_t number_of_contests;
    std::cin >> number_of_contests;

    /* get total_time_instances when
     * wormholes_of_type_V can be used */
    int32_t wormholes_of_type_V;
    std::cin >> wormholes_of_type_V;

    /* get total_time_instances when
     * wormholes_of_type_W can be used */
    int32_t wormholes_of_type_W;
    std::cin >> wormholes_of_type_W;

    /* get start-time & end-time of each contest */
    std::vector<std::pair<int32_t, int32_t>> contest_time(number_of_contests);
    for (int32_t i{0};i < number_of_contests;i++) {
        /* store start-time of i_th contest */
        std::cin >> contest_time.at(i).first;

        /* store end-time of i_th contest */
        std::cin >> contest_time.at(i).second;
    }

    /* get time_instances_of_wormholes which are of type V */
    std::vector<int32_t> time_instance_of_V(wormholes_of_type_V);
    for (int32_t i{0}; i < wormholes_of_type_V; i++) {
        std::cin >> time_instance_of_V.at(i);
    }

    /* sort time instances of wormholes_of_type_V in increasing order */
    std::sort(time_instance_of_V.begin(), time_instance_of_V.end());

    /* get time_instances_of_wormholes which are of type W */
    std::vector<int32_t> time_instances_of_W(wormholes_of_type_W);
    for (int32_t i{0}; i < wormholes_of_type_W; i++) {
        std::cin >> time_instances_of_W.at(i);
    }

    /* sort time instances of wormholes_of_type_W in increasing order */
    std::sort(time_instances_of_W.begin(), time_instances_of_W.end());

    int64_t min_interval {INT32_MAX};

    for (int32_t i{0};i < number_of_contests;i++) {
        /* for contest-start-time */
        auto it1{std::upper_bound(time_instance_of_V.begin(),
                                  time_instance_of_V.end(), contest_time[i].first)};
        it1 -= 1;

        /* for contest-end-time */
        auto it2{std::lower_bound(time_instances_of_W.begin(),
                                  time_instances_of_W.end(), contest_time[i].second)};

        if (it1 != (time_instance_of_V.begin() + wormholes_of_type_V)
        && it2 != (time_instances_of_W.begin() + wormholes_of_type_W)) {

            /* find minimum time interval */
            int64_t temp_time_required{*it2 - *it1 + 1};

            if (temp_time_required < min_interval) {
                min_interval = temp_time_required;
            }
        }
    }

    /* print appropriate message */
    std::cout << min_interval << std::endl;

    return 0;
}