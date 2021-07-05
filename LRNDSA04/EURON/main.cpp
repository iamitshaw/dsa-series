#include <bits/stdc++.h>

/* merge the two sorted sub-arrays - left and right sub-array */
template <typename T>
int64_t merge_subarray(std::vector<T>& array, int32_t left, int32_t mid, int32_t right) {

    /* find the size of left sub-array and right sub-array */
    int32_t size_of_left_subarray {(mid - left + 1)};
    int32_t size_of_right_subarray {right - (mid + 1) + 1};

    /* allocate memory for left sub-array and right sub-array  */
    std::vector<T> left_subarray(size_of_left_subarray);
    std::vector<T> right_subarray(size_of_right_subarray);

    /* copy the content of left sub-array */
    for (int32_t i{0};i < size_of_left_subarray;i++) {
        left_subarray[i] = array[left + i];
    }

    /* copy the content of right sub-array */
    for (int32_t i{0};i < size_of_right_subarray;i++) {
        right_subarray[i] = array[mid + 1 + i];
    }

    /* initial index for left sub-array, right
     * sub-array and merged-array respectively */
    int32_t i{0}, j{0}, k{left};
    int64_t inversion_count {0};

    /* merge the left_subarray and right_subarray in sorted order */
    while (i < size_of_left_subarray && j < size_of_right_subarray) {
        if (left_subarray[i] <= right_subarray[j]) {
            array[k++] = left_subarray[i++];
        } else {
            array[k++] = right_subarray[j++];

            /* since left_sub_array & right_sub_array both
             * are sorted hence every element to right of
             * i-th element will also form inversion_pair */
            inversion_count += (size_of_left_subarray - i);
        }
    }

    /* if any element of the left sub-array is being
     * unprocessed then copy the remaining elements */
    while (i < size_of_left_subarray) {
        array[k++] = left_subarray[i++];
    }

    /* if any element of the right sub-array is being
     * unprocessed then copy the remaining elements */
    while (j < size_of_right_subarray) {
        array[k++] = right_subarray[j++];
    }
    return inversion_count;
}

/* recursive merge sort algorithm */
template <typename T>
int64_t get_inversion_count(std::vector<T>& array, int32_t right_index, int32_t left_index= 0) {
    int64_t inversion_count{0};
    if (left_index < right_index) {
        auto mid_index{left_index + (right_index - left_index)/2};

        /* sort left sub-array array[left_index..mid_index] */
        inversion_count += get_inversion_count(array, mid_index, left_index);

        /* sort right sub-array array[mid_index+1..right_index] */
        inversion_count += get_inversion_count(array, right_index, mid_index + 1);

        /* merge two sorted sub-arrays */
        inversion_count += merge_subarray(array, left_index, mid_index, right_index);
    }
    return inversion_count;
}

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get size_of_array */
    int32_t size_of_array;
    std::cin >> size_of_array;

    /* get array elements */
    std::vector<int32_t> array(size_of_array);
    for (int32_t i{0};i < size_of_array;i++) {
        std::cin >> array.at(i);
    }

    /* evaluate inversion_count */
    int64_t inversion_count{get_inversion_count(array, size_of_array-1)};

    /* print appropriate message */
    std::cout << inversion_count << std::endl;

    return 0;
}