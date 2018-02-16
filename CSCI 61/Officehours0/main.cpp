#include <iostream>   // Provides cout
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <queue>      // Provides queue
#include <stdlib.h>   // Provides Rand()
#include <chrono>     // Time for srand()
#include <map>        // Multimap
#include <fstream>    // Output for file
#include "officehrs.h"  // access to student and questoins classes

namespace main_savitch_8A
{
    student::student(unsigned int arrival, unsigned int help_time){
        arrival_time = arrival; //arrival time creates new student
        help_time_needed = help_time; //only given a max help time of 15 minutes
        _question_asked=questions();
    }
    
    questions::questions(){
        std::string a[] = {"Combinatorics","Statistics","Probability","Data Structures",
            "Object Oriented Programming","French","Communications","Chaos Theory","Calculus","English"};
        _topic = a[rand()%10];
        _difficutly = rand() % 100;
    }
}
