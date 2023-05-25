#include <cstring>
#include <iostream>

extern "C" {
void save_cost_and_discomfort(double discomfort, double cost);
void save_floor_temp(double th, int room_id, const char *model, int global_time);
void save_envelop_temp(double te, int room_id, const char *model, int global_time);
void save_tank_related_data(double *Tb, double TF, double m_hp, double m_hf, double cp, double heat_pro,const char *model, int tank_levels, double mass, double area1, double area2);
}