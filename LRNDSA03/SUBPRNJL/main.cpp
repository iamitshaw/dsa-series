#include <bits/stdc++.h>

template <typename I>
int32_t k_element(I iterator, int32_t offset) {
    /* evaluate element_K */

    /* offset represent index of element_K when
     * indexing starts at the current iterator */
    while (offset >= iterator->second) {
        offset -= iterator->second,++iterator;
    }

    /* evaluate F: number_of_occurrence of element_K */
    return iterator->second;
}

int32_t calculate_F(const std::map<int32_t ,int32_t>& map,
                    int32_t sub_array_size, int32_t offset) {
    if(offset <= (sub_array_size - offset)) {
        /* if distance of element_K is
         * smaller from end_of_sub_array */
        return k_element(map.rbegin(), offset);
    } else {
        /* if distance of element_K is
         * smaller from start_of_sub_array */

        /* update offset such that it represent element_K's
         * index in S when indexed from left-to-right in S */
        offset = sub_array_size - offset - 1;

        return k_element(map.begin(), offset);
    }
}

int32_t main(int32_t argc, char* argv[]){
    /* fast input-output */
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get test_case */
    int32_t test_case;
    std::cin >> test_case;

    while(test_case--){
        /* get array_size */
        int32_t array_size;
        std::cin >> array_size;

        /* get K */
        int32_t K;
        std::cin >> K;

        /* get array element */
        std::vector<int32_t> array(array_size);
        for(int32_t i{0};i < array_size;i++) {
            std::cin >> array.at(i);
        }

        int32_t number_of_beautiful_sub_array{0};
        for(int32_t i{0};i < array_size;i++) {
            std::map<int32_t, int32_t> map;
            for(int32_t j{i},sub_array_size{1}; j < array_size; j++,sub_array_size++) {
                /* update count of array[j] */
                map[array[j]] += 1;

                int32_t m=std::ceil(K/float(sub_array_size));

                /* offset represent element_K's index in S
                 * when indexed from right-to-left in S */
                int32_t offset=(m * sub_array_size - K) / m;

                /* evaluate F */
                int32_t F{calculate_F(map, sub_array_size, offset)};

                /* if F has occurred at-least once in
                 * sub-array then it is beautiful */
                if(map.count(F) > 0) {
                    number_of_beautiful_sub_array++;
                }
            }
        }

        /* print appropriate message */
        std::cout << number_of_beautiful_sub_array << std::endl;
    }
    return 0;
}