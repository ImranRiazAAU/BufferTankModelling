#include <cstring>
#include <iostream>

using namespace std;

extern "C" {
double get_stratego_control_choice(double *discrete_time, double *room_temps, int reuse, int intervals, int strategy_num, double* mixing_value);
double get_bb_control_choice(double *room_temps, double target_temp);
}
