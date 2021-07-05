#include <bits/stdc++.h>

/* structure of TastyDish */
struct TastyDish {
    int64_t distance;
    int64_t people_to_eat;
};

/* structure of tribal-clan */
struct TribalClan {
    int64_t distance;
    int64_t people_to_convince;
    int64_t population;
};

bool is_possible_with(std::vector<TastyDish>& tasty_dish,
                      std::vector<TribalClan>& clan,
                      int64_t number_of_people) {
    /* index for tasty_dish & tribal_clans */
    int32_t i{0}, j{0};

    /* get number_of_dishes & number_of_clans */
    int32_t B = tasty_dish.size();
    int32_t C = clan.size();

    while (i < B) {
        if (j < C) {
            /* if tribal_clans are on Journey to ByteLand */
            if (tasty_dish[i].distance < clan[j].distance) {
                /* if i-th tasty_dish comes first on Journey to ByteLand */
                number_of_people -= tasty_dish[i].people_to_eat;
                i += 1;
            } else {
                /* if j-th tribal_clan comes first on Journey to ByteLand */
                if (number_of_people >= clan[j].people_to_convince) {
                    number_of_people += clan[j].population;
                }
                j += 1;
            }
        } else {
            /* if tribal_clans aren't on Journey to ByteLand */
            number_of_people -= tasty_dish[i].people_to_eat;
            i += 1;
        }
    }

    /* at the end of the Journey, if
     * one or more people are left */
    return number_of_people >= 1;
}

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get test_case */
    int32_t test_case;
    std::cin >> test_case;

    while (test_case--) {
        /* get distance of ByteLand from Chef's Town */
        int32_t X;std::cin >> X;

        /* get number_of_dishes on
         * path of tasty-dishes */
        int32_t B;std::cin >> B;

        /* get tasty-dish information */
        std::vector<TastyDish> tasty_dish(B);
        for (int32_t i{0};i < B;i++) {
            std::cin >> tasty_dish[i].distance;
            std::cin >> tasty_dish[i].people_to_eat;
        }

        /* get number_of_clans */
        int32_t C;std::cin >> C;

        /* get tribal_clan-related-information */
        std::vector<TribalClan> tribal_clan(C);
        for (int32_t i{0};i < C;i++) {
            std::cin >> tribal_clan[i].distance;
            std::cin >> tribal_clan[i].people_to_convince;
            std::cin >> tribal_clan[i].population;
        }

        /* evaluate maximum_people_required
         * to completely eat tasty_dishes */
        int64_t max_people_required{1};
        for (int32_t i{0};i < B;i++) {
            max_people_required += tasty_dish[i].people_to_eat;
        }

        /* evaluate minimum_people_required */
        int64_t temp_min_people{1}, temp_max_people{max_people_required};

        while (temp_min_people <= temp_max_people) {
            /* check if mid_value is minimum_required_people */
            int64_t mid{temp_min_people + (temp_max_people - temp_min_people) / 2};

            bool is_possible_I{is_possible_with(tasty_dish, tribal_clan, mid)};
            bool is_possible_II{is_possible_with(tasty_dish,tribal_clan,mid-1)};

            if (is_possible_I && !is_possible_II) {
                /* if minimum_required_people has been found */
                max_people_required = mid;break;
            } else if (!is_possible_I && !is_possible_II) {
                /* if mid is far right of
                 * minimum_required_people */
                temp_min_people = mid + 1;
            } else if (is_possible_I) {
                /* if mid is far left of
                 * minimum_required_people */
                temp_max_people = mid - 1;
            }
        }

        /* print appropriate message */
        std::cout << max_people_required << std::endl;
    }
    return 0;
}