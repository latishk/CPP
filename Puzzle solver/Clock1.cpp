#include <iostream>
#include <map>
#include <list>
#include "solution2.h"
#include "puzzle.h"


class Clock : public puzzle<int, int>{

public:
	int hoursOnClock;
	int initialConfiguration;
	int goal;
    std::vector<int> variations;

	Clock(int hoursOnClock, int initialConfiguration, int goal, std::vector<int> variations)
    : initialConfiguration(initialConfiguration), goal(goal), hoursOnClock(hoursOnClock), variations(variations)
    {
        
	}

	bool isGoal(int configuration){

		return configuration == goal;

	}

	std::vector<int> getNextConfiguration(int currentConfiguration){

       std::vector<int> v = getAllConfigurations(currentConfiguration);
         return v;
     
        // for(std::vector<int>::iterator it = variations.begin(); it!=variations.end();it++){//
        //     cout<<*it<<"!!! getNextConfiguration \n";
        // }   
    }

    std::vector<int> getAllConfigurations(int current){
        std::vector<int> v ;
       

        for(std::vector<int>::iterator it = variations.begin(); it!=variations.end();it++){


           // cout<<current<<" CHANGE :"<<*it<<"\n----------\n";
            
            int changes = *it;
            //change is a decrement

            if ((current+changes) <= 0){

                v.push_back(hoursOnClock+current+changes);
            
            }
            else
                 if ((current + changes) > hoursOnClock){

                        v.push_back((current+changes) % hoursOnClock);
                
                }
                else{
                
                    v.push_back(current+changes);
                    
                }
        }

        // cout<<"sending in: ";
        // for(std::vector<int>::iterator it = v.begin(); it!= v.end(); it++){
        //     cout<<*(it)<<" ";

        // }
        //  cout<<"\n";
        return v;
    }

    void displayPaths(std::list<int> temp){
        std::list<int> bestPathList = temp;
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
    std::vector<int> v;
    for(int i = 4; i < argc; i++){
        v.push_back(atoi(argv[i]));
        cout<<v[i-4]<<" main ";
    }
    cout<<"\n";
    // if(currentTimeOnTheClock > numberOfHoursOnTheClock)
    //     currentTimeOnTheClock %= numberOfHoursOnTheClock;

    // if(actualTime > numberOfHoursOnTheClock)
    //     actualTime %= numberOfHoursOnTheClock;

    Clock c (numberOfHoursOnTheClock, currentTimeOnTheClock, actualTime, v);
    solution<int, int> *s = new solution<int, int>(currentTimeOnTheClock, actualTime);
    s->solve(c);
    s = NULL; 
    
    return 0;	
}