#include <cstring>
#include <iostream>

using namespace std;

extern "C" {
void change_dir();
double get_room_temp(int room_id);
double get_envelop_temp(int room_id);
double get_floor_temp(int room_id);
int get_global_time();
int get_offset();
int get_month();
int get_day();
double get_return_temp(int room_id);
double get_forward_temp();
double get_consumed_power();
double get_tank_temp(int room_id);
int get_tank_levels();
double get_mixing_value();
double get_mixing_levels();
int get_mixing_levels_int();
}






