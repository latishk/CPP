#ifndef SOLUTION_H
#define SOLUTION_H 

#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include "puzzle.h"
template <class T, typename T2>

class solution
{
public:
	T2 goal;
	T initialConfiguration;
	std::queue<T> solutionQueue;
	std::map<T,T> m;

	solution(T initialConfiguration, T2 goal): initialConfiguration(initialConfiguration), goal(goal){

		
		solutionQueue.push(initialConfiguration);
		m[initialConfiguration] = initialConfiguration;
		

	}

	std::vector<T> nextConfiguration;
	void solve(puzzle<T,T2> &p){

		if(p.isGoal(initialConfiguration)){
			std::list<T> InitialIsGoalList;
			InitialIsGoalList.push_front(initialConfiguration);
			p.displayPaths( InitialIsGoalList);
			//cout<<"here!!";
		}
		else
		{

		T goalNew = initialConfiguration;//if initialcofi is goal itself
		//solutionQueue.push(initialConfiguration);
		while( !solutionQueue.empty() && !p.isGoal(solutionQueue.front())){
			//cout<<"inside while";
			T config = solutionQueue.front();
			nextConfiguration = p.getNextConfiguration(config);
			for (int i = 0; i < nextConfiguration.size(); ++i)
			{
				if(m.find(nextConfiguration.at(i)) == m.end()){
					solutionQueue.push(nextConfiguration.at(i));
					m[nextConfiguration.at(i)] = config;
				}
			}
			solutionQueue.pop();
			if(p.isGoal(solutionQueue.front())) {
				goalNew = solutionQueue.front();
				//bool goalFound = true;
				//cout<<goal.at(0);
			}
		}//end while

		//displayMap(m);
			
			p.displayPaths(displaySol(m, goalNew, initialConfiguration));
		}
	}//end void

	std::list<T> displaySol(std::map<T,T2> temp, T2 goal, T initialConfiguration){
        
        std::map<T,T2> *tempMapPointer = new  std::map<T, T2>(temp);
        std::list<T> bestPathList;
        std::list<T> NoSolEmptyList;
        bestPathList.push_front(goal);
        T2 find = goal;
        int count = 0;
        while(count++ < temp.size()){
        	//cout<<"here!: " <<count;
        	T2 findCheck = find;
            T next = getKey(tempMapPointer, find);
            /*
				if count is 1 and getKey() returns the find itself that means it could't 
				find the goal in the map and there is no solution so we should return an emptylist.
            */
           	if(count == 1 && (next == findCheck))
           		return NoSolEmptyList;

           
	            find = next;
    	        bestPathList.push_front(next);
    	        if(find == initialConfiguration)
                break;
        }
       // cout<<"the element is "<< bestPathList.front();
        return bestPathList;
    }

	T getKey(std::map<T,T2> *temp, T2 find){
        
        for (typename std::map<T,T2>::iterator it=temp->begin(); it!=temp->end(); ++it)
        { 
            if (it->first == find){
                T2 value = it->second;
                return value;
            }
        }
        return find;
    }

	void displayMap(std::map<T,T> temp){
                
        for (typename std::map<T, T>::iterator it=temp.begin(); it!=temp.end(); ++it)
            std::cout << it->first << " => " << it->second <<endl;
                std::cout<<endl;
                
            }
};
#endif