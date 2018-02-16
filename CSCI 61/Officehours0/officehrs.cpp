#include <iostream>   // Provides cout
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <queue>      // Provides queue
#include <stdlib.h>   // Provides Rand()
#include <chrono>     // Time for srand()
#include <map>        // Multimap
#include <fstream>    // Output for file
#include "officehrs.h"  // access to student and questoins classes
using namespace main_savitch_8A;
using namespace std;

void average_students(queue<student>);

queue<multimap<unsigned int, student>> office_hours_simulate();

void print(int, queue<multimap<unsigned int, student>>);

//ADD FILE IO FOR EACH ITTERATION
//PRINT OUT HOW QUESTIONS ASKED FOR EACH STUDENT FOR EACH OFFICE HOURS

void print(int i,queue<multimap<unsigned int, student>> token){
    ofstream o_stream;
    o_stream.open("/Users/PatSelover/Desktop/Officehours.txt");
    if(o_stream.fail()){
        cout<<"Input file opening failed. \n";
        exit(1);
    }
    
    
    o_stream<<"Office Hours "<<i<<endl;
    o_stream<<endl;
    
    while(!token.empty()){
        multimap <unsigned int, student> pair_print= token.front();
        token.pop();
        for (std::multimap<unsigned int,student>::iterator it=pair_print.begin(); it!=pair_print.end(); ++it)
            o_stream << (*it).first << " => " << (*it).second << endl;
    }
    
    
    o_stream.close();
}

int main()
{
    queue<student> avg_office_hours;
    queue<multimap<unsigned int, student>>classmate;
    for(int i = 0; i <= 99; ++i){
        classmate = office_hours_simulate();
        //avg_office_hours.push(t);
        print(i,classmate);
    }
    /*average_students(avg_office_hours);
     student print = avg_office_hours.front();
     avg_office_hours.pop();
     cout<<"Average help time needed: "<< print.help_time_needed<< endl;
     cout<<"Average arrival time "<< print.arrival()<<endl;
     cout<<"Average wait time " << print.time_in_line<<endl;
     cout<<"Average overtime "<< print.over_time<<endl;*/
    return 0;
}

void average_students(queue<student> a){
    while (a.size() != 1){
        student front = a.front();
        a.pop();
        student second = a.front();
        a.pop();
        front.help_time_needed = (front.help_time_needed + second.help_time_needed)/2;
        front.time_in_line = (front.time_in_line + second.time_in_line)/2;
        front.over_time = (front.over_time + second.over_time)/2;
        a.push(front);
    }
}
queue<multimap<unsigned int, student>> office_hours_simulate()
{
    queue<multimap<unsigned int, student>> line;
    student average(0,0), front(0,0), last_kid(0,0);
    for (int i = 0; i<= 59; ++i){
        if(rand() % 100 <= 20){
            srand(time(NULL));
            unsigned int help_time = rand() % 15 + 1;
            unsigned int name = rand() % 40;
            if(line.empty()){
                student token (i, help_time);
                token.time_in_line = 0;
                last_kid = token;
                multimap<unsigned int, student> customer;
                customer.insert(std::pair<unsigned int,student>(name, token));
                line.push(customer);
            }
            else {
                student token(i, help_time);
                token.time_in_line = (last_kid.arrival() - i) + last_kid.time_in_line + last_kid.help_time_needed;
                multimap<unsigned int, student> customer;
                customer.insert(std::pair<unsigned int,student>(name, token));
                line.push(customer);
                last_kid = token;
            }
        }
    }
    /*unsigned int count = 0;
     while (!line.empty()){
     front = line.front();
     line.pop();
     if(count != 0){
     average.time_in_line = (average.time_in_line + front.time_in_line) / 2;
     average.help_time_needed = (average.help_time_needed + front.help_time_needed) / 2;
     if(line.empty())
     average.over_time = (front.time_in_line + front.help_time_needed);
     }
     else{
     average.time_in_line = front.time_in_line;
     average.help_time_needed = front.help_time_needed;
     ++count;
     }
     }
     return average;*/
    return line;
}
