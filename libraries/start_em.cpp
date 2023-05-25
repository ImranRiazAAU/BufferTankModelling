#include "start_em.h"
#include <sstream>

bool got_param = false;
int month;
int day;
int hour;
int simulation_period;
int intervals;
int controller;
int tank_levels;
double tank_radius;
double tank_height;
double tank_area;
double tank_volume;
double mixing_levels;

void _read_param(std::istream &in);

void read_param() {
    auto env = getenv("START_DATA");
    if (env == nullptr) {
        _read_param(std::cin);
    } else {
        std::stringstream ss(env);
        _read_param(ss);
    }
}

void _read_param(std::istream &ss) {
    if (got_param) return;
    // month number (select from 1...12)
    ss >> month;
    // day number (select from 1...31 depending on the number of days in inserted month)
    ss >> day;
    // simulation starting hour for that day (select from 0...23)
    ss >> hour;
    // simulation period in days
    ss >> simulation_period;
    // number of intervals to reuse a strategy
    ss >> intervals;
    // tank levels
    ss >> tank_levels;
    // tank radius
    ss >> tank_radius;
    // tank height
    ss >> tank_height;
    // mixing levels
    ss >> mixing_levels;
    // value 0 is for stratego and 1 is for bb
    ss >> controller;
    got_param = true;
}

int get_month() {
    read_param();
    return month;
}

int get_day() {
    read_param();
    return day;
}

int get_hour() {
    read_param();
    return hour;
}

int get_simulation_period() {
    read_param();
    return simulation_period;
}

int get_intervals() {
    read_param();
    return intervals;
}

int get_selected_controller() {
    read_param();
    return controller;
}
int get_tank_levels() {
    read_param();
    return tank_levels;
}
double get_tank_volume() {
    read_param();
    tank_volume = 3.1416*tank_radius*tank_radius*tank_height;
    return tank_volume*1000;
}
double get_tank_area() {
    read_param();
    tank_area = (2*3.1416*tank_radius*tank_height) + (2*3.1416*tank_radius*tank_radius);
    return tank_area;
}