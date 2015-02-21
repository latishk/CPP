#include <iostream>
#include <map>
#include <list>
#include "solution2.h"
#include "puzzle.h"
#include <cstdlib>




class Clock : public puzzle<int, int>{

public:
	int hoursOnClock;
	int initialConfiguration;
	int goal;

	Clock(int hoursOnClock, int initialConfiguration, int goal)
    : initialConfiguration(initialConfiguration), goal(goal), hoursOnClock(hoursOnClock)
    {
    
	}

	bool isGoal(int configuration){

		return configuration == goal;

	}

	std::vector<int> getNextConfiguration(int currentConfiguration){
        std::vector<int> v ;
        if ((currentConfiguration-1) == 0){
            v.push_back(hoursOnClock);
            v.push_back(currentConfiguration+1);
            return v;
        }
        else
            if (currentConfiguration == hoursOnClock){
                
                  v.push_back(currentConfiguration-1);
                  v.push_back(1);
                  return v;
            }
            else {
                
                v.push_back(currentConfiguration-1);
                v.push_back(currentConfiguration+1);
                return v;
            }
    }

    void displayPaths(std::list<int> bestPathList){

        std::cout <<"set the clock by rotating through: ";
        for (std::list<int>::iterator it=bestPathList.begin(); it!=bestPathList.end(); ++it)
            std::cout <<*it<<" ";
        std::cout <<std::endl;
        
    }
    
};

int main(int argc, char *argv[]){


    int numberOfHoursOnTheClock = atoi(argv[1]);
    int currentTimeOnTheClock = atoi(argv[2]);
    int actualTime = atoi(argv[3]);
    //int hoursOnClock = 

    if(numberOfHoursOnTheClock > 0 ){
    Clock c (numberOfHoursOnTheClock, currentTimeOnTheClock, actualTime);
    solution<int, int> *s = new solution<int, int>(currentTimeOnTheClock, actualTime);
    s->solve(c);
    s = NULL;
    }
    else cout<<"Your clock doesn't have any hours!\n";
    
    
    return 0;	
}