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
        /* get number_of_penalty_shoot */
        int32_t number_of_penalty_shoot;
        std::cin >> number_of_penalty_shoot;

        /* get penalty_shoot_history */
        std::string penalty_shoot_history;
        std::cin >> penalty_shoot_history;

        int32_t goal_scored_by_team_A{0};
        int32_t goal_scored_by_team_B{0};

        /* number_of_penalty_shoot left by team_A & team_B */
        int32_t left_shoot_by_team_A{number_of_penalty_shoot};
        int32_t left_shoot_by_team_B{number_of_penalty_shoot};

        int32_t winner_determined_at_index{(2 * number_of_penalty_shoot) - 1};

        for (int32_t i{0};i < 2 * number_of_penalty_shoot; i+=1) {
            if (i%2 == 0) {
                /* penalty shoot taken by team_A */
                goal_scored_by_team_A += penalty_shoot_history.at(i) - 48;
                left_shoot_by_team_A -= 1;
            } else {
                /* penalty shoot taken by team_B */
                goal_scored_by_team_B += penalty_shoot_history.at(i) - 48;
                left_shoot_by_team_B -= 1;
            }


            /* check winning status of team_A */
            if (goal_scored_by_team_A > (goal_scored_by_team_B + left_shoot_by_team_B)) {
                /* if team_A is winner */
                winner_determined_at_index = {i};break;
            }/* check winning status of team_B */
            else if (goal_scored_by_team_B>(goal_scored_by_team_A+left_shoot_by_team_A)) {
                /* if team_B is winner */
                winner_determined_at_index = {i};break;
            }
        }

        /* print appropriate message */
        std::cout << (winner_determined_at_index + 1) << std::endl;
    }
    return 0;
}