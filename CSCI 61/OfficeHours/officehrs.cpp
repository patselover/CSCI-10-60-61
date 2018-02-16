#include "officehrs.h" // Provides bool_source, averager, office hour definitions
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides rand, RAND_MAX, size_t
#include <ctime>
#include <queue>
#include <stdlib.h>

namespace main_savitch_8A
{
    student::student(unsigned int arrival, unsigned int help_time){
        arrival_time = arrival; //arrival time creates new student
        help_time_needed = help_time; //only given a max help time of 15 minutes
    }
}
