#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get N */
    int32_t N;std::cin >> N;

    /* get elements */
    std::vector<int32_t> array(N);
    for (int32_t i{0};i < N;i++) {
        std::cin >> array.at(i);
    }

    /* reverse array sequence */
    int32_t leftIndex{0}, rightIndex{N-1};
    while (leftIndex <= rightIndex) {
        std::swap(array[leftIndex], array[rightIndex]);
        leftIndex += 1;rightIndex -= 1;
    }

    /* print message */
    for (int32_t i{0};i < N;i++) {
        std::cout << array.at(i) << " ";
    }
    return 0;
}