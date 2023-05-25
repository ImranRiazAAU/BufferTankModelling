#include <libstrategy/SimpleTree.h>
#include <fstream>
#include <stdio.h>
#include "useStrategy.h"
#include <string>
#include <cstdint>
#include <filesystem>
#include <iostream>

const double min_heat_for_first_interval = 0.625;
const double heat_jump_in_each_level = 0.1875;
const int total_intensity_levels = 11;
const int ROOMS = 4;

double
get_stratego_control_choice(double *discrete_time, double *room_temps, int reuse, int intervals, int strategy_num, double* mixing_value) {
    auto env = getenv("STRATEGY_DIR");
    std::string strategy_path = "./";
    if(env) {
        strategy_path = env;
    }
    auto ml_env = getenv("MIXING_LEVELS");
    //printf("\n MIXING_LEVELS env in use strategy is %s\n", ml_env);
    std::cerr << " MIXING_LEVELS env in use strategy is " << ml_env << std::endl;
    string mix = ml_env;
    double mixing_levels = std::stod(mix);
    std::cerr << " MIX in use strategy is " << mixing_levels << std::endl;
    string strategy_number = to_string(strategy_num); 
    std::ifstream strategy_input_file((strategy_path + "/strategy.json"));
    if (strategy_input_file) 
        std::cerr << "Strategy file found in " << strategy_path << std::endl;
    else 
        std::cerr << "Strategy file not found in " << strategy_path << std::endl;
    SimpleTree strategy = SimpleTree::parse(strategy_input_file, false, false, 0);
    double consumed_power;
    size_t best = -1;
    double best_value = std::numeric_limits<double>::infinity();
    std::ofstream strategy_choice_log;
    strategy_choice_log.open((strategy_path+"/control_choices_log.txt"), ios::app);
    int count=0;
    for (size_t action = 1; action <= (total_intensity_levels*mixing_levels+mixing_levels); ++action) {
        double action_value = strategy.value(discrete_time, room_temps, action);
        if (action == total_intensity_levels*mixing_levels+mixing_levels)
            strategy_choice_log << action_value << "\n";
        else
            strategy_choice_log << action_value << " ";
        if (best_value > action_value) {
            best_value = action_value;
            best = action;
        }
    }
    strategy_choice_log << "Best value is = " << best_value << " and best action is = " << best << "\n";
    strategy_choice_log.close();
    strategy_input_file.close();
    /*if (best != -1) {
        if (best != total_intensity_levels) {
            consumed_power = min_heat_for_first_interval + heat_jump_in_each_level * (best - 1);
        } else {
            consumed_power = 0;
        }
    } else {
        consumed_power = -1;
    }*/
    size_t mix_value=-1;
    size_t intensity_level = -1;
    if (best != -1) {
        if (best <= (total_intensity_levels)*mixing_levels) {
            if (best%total_intensity_levels!=0)
                intensity_level = best%total_intensity_levels;
            else
                intensity_level = total_intensity_levels;
            mix_value = (best-1)/total_intensity_levels;
            *mixing_value = mix_value;
            consumed_power = min_heat_for_first_interval + heat_jump_in_each_level * (intensity_level - 1);
        } else {
            consumed_power = 0;
            mix_value = (best-1)%total_intensity_levels;
            *mixing_value = mix_value;
        }
        std::cerr <<" mixing value before division by mixing_levels is "<<*mixing_value<< std::endl;
        *mixing_value=*mixing_value/(mixing_levels-1);
        std::cerr <<" mixing value after division by mixing_levels is "<<*mixing_value<<" and mixing levels are "<<mixing_levels<< std::endl;
    } else {
        consumed_power = -1;
    }
    std::ofstream em_temps_and_control_choice;
    em_temps_and_control_choice.open((strategy_path+"/temps_and_choice.txt"), ios::app);
    em_temps_and_control_choice << best << " " << consumed_power << " " << *discrete_time << " " << room_temps[0] << " "
                                << room_temps[1] << " " << room_temps[2] << " " << room_temps[3] << " " << room_temps[4]
                                <<" "<<*mixing_value<<" "<<mixing_levels<< "\n";
    em_temps_and_control_choice.close();
    //std::cerr << "In use strategy reuse is "<<reuse<<" intervals is "<<intervals<<" strategy number is "<<strategy_number<< std::endl;
    std::cerr << "In use strategy reuse is "<<reuse<<" intervals is "<<intervals<<" strategy number is "<<strategy_number<<" best is "<<best<<" (intensity level -1 is) "<<intensity_level-1<<" mixing value is "<<*mixing_value<<" consumed_power_is "<<consumed_power<< std::endl;
    if (reuse == intervals)
        std::filesystem::rename(strategy_path +"/strategy.json", strategy_path +"/strategy" + strategy_number + ".json");
    return consumed_power;
}

double get_bb_control_choice(double *room_temps, double target_temp) {
    int make_pump_on = 0;
    for (int i = 0; i < ROOMS; i++) {
        if (room_temps[i] < target_temp) {
            make_pump_on = 1;
        }
    }
    return make_pump_on * (min_heat_for_first_interval + heat_jump_in_each_level * (total_intensity_levels - 1));
}






