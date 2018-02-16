#ifndef OFFICEHRS_H
#define OFFICEHRS_H
#include <cstdlib>
#include <chrono>
#include <stdlib.h> //includes rand
#include <time.h> // includes time
namespace main_savitch_8A
{
    class student
    {
    public:
        // CONSTRUCTOR
        student(unsigned int, unsigned int);
        // MODIFICATION
        unsigned int time_in_line;
        unsigned int help_time_needed;
        unsigned int over_time = 0;
        // CONSTANT
        unsigned int arrival() const{ return arrival_time;}
    private:
        unsigned int arrival_time;
    };
}


#endif // OFFICEHRS_H
