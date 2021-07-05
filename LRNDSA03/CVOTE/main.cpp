#include <bits/stdc++.h>

int32_t main(int argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get number_of_chefs */
    int32_t number_of_chefs;
    std::cin >> number_of_chefs;

    /* get number_of_emails */
    int32_t number_of_emails;
    std::cin >> number_of_emails;

    /* dictionary to store the name_of_chef
     * & corresponding country information */
    std::map<std::string, std::string> dict;

    std::string name_of_chef;
    std::string country_of_chef;

    for (int32_t i{0};i < number_of_chefs;i++) {
        std::cin >> name_of_chef;
        std::cin >> country_of_chef;
        dict.insert({name_of_chef, country_of_chef});
    }

    std::map<std::string, int32_t> chefs_info;
    std::map<std::string, int32_t> countries_info;

    for (const auto& item: dict) {
        /* dictionary to store chef's
         * name & count as chef_of_the_year */
        chefs_info.insert({item.first, 0});

        /* dictionary to store country's
         * name & count as chef_of_the_year */
        countries_info.insert({item.second, 0});
    }

    /* process email information */
    for (int32_t i{0};i < number_of_emails;i++) {
        /* get name_of_chef */
        std::cin >> name_of_chef;

        auto temp {chefs_info.find(name_of_chef)};
        temp->second += 1;

        /* get country of specified chef */
        auto country {dict.find(name_of_chef)};

        temp = {countries_info.find(country->second)};
        temp->second += 1;
    }

    /* evaluate individual_chef who has got
     *  maximum vote as chef_of_the_year */
    int32_t individual_max_vote{0};
    std::string chef_of_the_year;

    for (const auto& item: chefs_info) {
        if (item.second > individual_max_vote) {
            individual_max_vote = item.second;
            chef_of_the_year = item.first;
        }
    }

    /* evaluate country whose chefs has got
     * maximum vote for chef_of_the_year */
    int32_t country_max_vote{0};
    std::string country_of_the_year;

    for (const auto& item: countries_info) {
        if (item.second > country_max_vote) {
            country_max_vote = item.second;
            country_of_the_year = item.first;
        }
    }

    /* print appropriate message */
    std::cout << country_of_the_year << std::endl;
    std::cout << chef_of_the_year << std::endl;

    return 0;
}