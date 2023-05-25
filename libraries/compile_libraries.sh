#!/bin/bash

g++ $1 -std=c++17 -fPIC -shared connectUPPAALCTRL.cpp  -o connectUPPAALCTRL.so
g++ $1 -std=c++17 -fPIC -shared data_reader.cpp -o data_reader.so
g++ $1 -std=c++17 -fPIC -shared -I./libstrategy/install/include -I./libstrategy/build/external/include/ useStrategy.cpp ./libstrategy/build/lib/libstrategy.a -o useStrategy.so
g++ $1 -std=c++17 -fPIC -shared libParam.cpp  -o libParam.so
g++ $1 -std=c++17 -fPIC -shared start_em.cpp  -o start_em.so
g++ $1 -std=c++17 -fPIC -shared weights.cpp  -o weights.so
g++ $1 -std=c++17 -fPIC -shared store_data.cpp  -o store_data.so

