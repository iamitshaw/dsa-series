#include <bits/stdc++.h>

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* get potential_customers_count */
    int64_t potential_customers_count;
    std::cin >> potential_customers_count;

    /* get budget_of_potential_customers */
    std::vector<int32_t> budget_of_potential_customers(potential_customers_count);
    for (int32_t i{0}; i < potential_customers_count; i++) {
        std::cin >> budget_of_potential_customers.at(i);
    }

    /* sort budget_of_potential_customers */
    std::sort(budget_of_potential_customers.begin(), budget_of_potential_customers.end());

    /* evaluate maximum-revenue */
    int64_t maximum_revenue{0},i{0};
    for (const auto& potential_customer_budget: budget_of_potential_customers) {
        int64_t temp_revenue{potential_customer_budget * (potential_customers_count - i++)};
        if (temp_revenue > maximum_revenue) {
            maximum_revenue = temp_revenue;
        }
    }

    /* print appropriate message */
    std::cout << maximum_revenue << std::endl;

    return 0;
}