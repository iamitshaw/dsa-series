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
/* get number_of_cars */
int32_t number_of_cars;
std::cin >> number_of_cars;

/* get maximum_speed_of_cars */
std::vector<int32_t> cars_maximum_speed(number_of_cars);
for (int32_t i{0}; i < number_of_cars; i++) {
std::cin >> cars_maximum_speed.at(i);
}

/* evaluate count of cars_moving_with_maximum_speed */
int32_t cars_moving_with_max_speed{1};
int32_t previous_car_speed{cars_maximum_speed.at(0)};

for (int32_t i{1}; i < number_of_cars; i++) {
if (previous_car_speed >= cars_maximum_speed.at(i)) {
/* update permissible_car_speed for following cars */
cars_moving_with_max_speed += 1;
previous_car_speed = {cars_maximum_speed.at(i)};
}
}

/* print appropriate message */
std::cout << cars_moving_with_max_speed << std::endl;
}
return 0;
}