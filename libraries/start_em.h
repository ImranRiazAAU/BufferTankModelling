#include <cstring>
#include <iostream>

extern "C" {
int get_month();
int get_day();
int get_hour();
int get_simulation_period();
int get_intervals();
int get_selected_controller();
int get_tank_levels();
double get_tank_volume();
double get_tank_area();
}

