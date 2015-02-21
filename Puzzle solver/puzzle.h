#ifndef PUZZLE_H
#define PUZZLE_H
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
template <class T, typename T2>
class puzzle{
	
	public:
		T initialConfiguration;
		T2 goal;

		//puzzle(T initialConfiguration, T goal): 
		//initialConfiguration(initialConfiguration), goal(goal){}
		virtual	vector<T> getNextConfiguration(T currentConfiguration ) = 0;
		virtual	void displayPaths(std::list<T> temp) = 0;
		virtual	bool isGoal(T configuration) = 0;

};
#endif