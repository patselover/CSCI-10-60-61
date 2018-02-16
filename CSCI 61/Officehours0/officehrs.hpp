#ifndef OFFICEHRS_H
#define OFFICEHRS_H
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
    class questions
    {
    public:
        // CONSTRUCTOR
        questions();
        // CONSTANT
        std::string topic() const{return _topic;}
        unsigned int difficutly() const{return _difficutly;}
    private:
        unsigned int _difficutly;
        std::string _topic;
    };
    
    class student
    {
    public:
        // CONSTRUCTOR
        student(unsigned int, unsigned int);
        // MODIFICATION
        unsigned int time_in_line;
        unsigned int help_time_needed;
        unsigned int over_time = 0;
        void set_question(std::multimap<unsigned int,questions>);
        // CONSTANT
        unsigned int arrival() const{ return arrival_time;}
        std::string get_topic() const{return _question_asked.topic();}
        unsigned int get_diff() const {return _question_asked.difficutly();}
    private:
        unsigned int arrival_time;
        questions _question_asked;
    };
    
    std::ostream & operator << (std::ostream & out, student source){
        out<<source.get_topic()<<" "<< source.get_diff();
        return out;
    }
}



#endif // OFFICEHRS_H
