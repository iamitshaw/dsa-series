#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin.tie(nullptr);

    /* get size_array_A */
    int32_t size_array_A;
    std::cin >> size_array_A;

    /* get size_array_B */
    int32_t size_array_B;
    std::cin >> size_array_B;

    int32_t temp;

    /* get elements of array_A */
    std::vector<std::pair<int32_t, int32_t>> array_A(size_array_A);
    for (int32_t i{0}; i < size_array_A; i++) {
        std::cin >> temp;array_A.at(i) = {temp, i};
    }

    /* get elements of array_B */
    std::vector<std::pair<int32_t, int32_t>> array_B(size_array_B);
    for (int32_t i{0}; i < size_array_B; i++) {
        std::cin >> temp;array_B.at(i) = {temp, i};
    }

    /* sort array_A & array_B */
    std::sort(array_A.begin(), array_A.end());
    std::sort(array_B.begin(), array_B.end());

    int32_t i,j;
    for (i={0}; i < size_array_B; i++) {
        /* print appropriate  message */
        std::cout << array_A.at(0).second << " ";
        std::cout << array_B.at(i).second << "\n";
    }

    for (j={1}; j < size_array_A;j++) {
        /* print appropriate  message */
        std::cout << array_A.at(j).second << " ";
        std::cout << array_B.at(i-1).second << "\n";
    }
    return 0;
}