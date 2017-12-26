cmake_minimum_required(VERSION 3.7)
project(codeforces)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TheatreSquare.h Watermelon.h Way_Too_Long_Words.h Next_round.h String_Task.h Domino_piling.h Team.h Bit++.h Random_Array.h Football.h Petya_and_Strings.h Helpful_Maths.h Taxi.h Tram.h yuanqiao.h M_N_array.h MaxSubArray.h Sasha_and_Sticks.h Petya_and_Exam.h Strange_Radiation.h Misha_Grisha_and_Underground.h Vasya_and_Shifts.h Next_Permutation.h xiaoxin.h test.h dp_money.h road_kou.h block_ali.h)
add_executable(codeforces ${SOURCE_FILES})