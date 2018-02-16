#include <iostream>   // Provides cout
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <queue>      // Provides queue
#include <stdlib.h>
#include <chrono>
#include "officehrs.h"  // Provides averager, bool_source, washer
using namespace main_savitch_8A;
using namespace std;
void average_students(queue<student>);
student office_hours_simulate();
int main()
{
    queue<student> avg_office_hours;

    for(int i = 0; i <= 99; ++i){
        avg_office_hours.push(office_hours_simulate());
    }
    average_students(avg_office_hours);
    student print = avg_office_hours.front();
    avg_office_hours.pop();
    cout<<"Average help time needed: "<< print.help_time_needed<< endl;
    cout<<"Average arrival time "<< print.arrival()<<endl;
    cout<<"Average wait time " << print.time_in_line<<endl;
    cout<<"Average overtime "<< print.over_time<<endl;
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
student office_hours_simulate()
{
    queue<student> line;
    student average(0,0), front(0,0);
    for (int i = 0; i<= 59; ++i){
        if(rand() % 100 <= 20){
            srand(time(NULL));
            unsigned int help_time = rand() % 15 + 1;
            if(line.empty()){
                student token (i, help_time);
                token.time_in_line = 0;
                line.push(token);
            }
            else {
                student last = line.back();
                student token(i, help_time);
                token.time_in_line = (last.arrival() - i) + last.time_in_line + last.help_time_needed;
                line.push(token);
            }
        }
    }
    unsigned int count = 0;
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
    return average;
}
