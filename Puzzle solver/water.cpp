#include <iostream>
#include <map>
#include <list>
#include "solution2.h"
#include "puzzle.h"
#include <cstdlib>


typedef std::vector<int> ConfData;

class water : public puzzle<ConfData, ConfData>{
public:

	ConfData capacity;
	ConfData initialConfiguration;
	ConfData goal;

	water(ConfData initialConfiguration, ConfData capacity, ConfData goal)
    : capacity(capacity), initialConfiguration(initialConfiguration), goal(goal)
    {
		// paramatrized constructor
	}

	bool isGoal( ConfData configuration){

        for(int i = 0; i< configuration.size(); i++ )
        {
            if(configuration.at(i) == goal.at(0))
		   return true;
        }
    return false;

	}

	std::vector<ConfData> getNextConfiguration(ConfData v){
     
     std::vector<ConfData> confi;
     for(int i= 0; i<v.size(); i++){

        confi.push_back(fillTheContainers(v, i));
     }


     for(int i= 0; i<v.size(); i++){

        confi.push_back(emptyTheContainers(v, i));
     }

        for (int i = 0; i < v.size(); ++i)
        {
            for(int j= 0; j<v.size(); j++){

                confi.push_back(pour(v, i, j));
            }
        }

        return confi;
    }

    ConfData fillTheContainers(std::vector<int> v, int i){

         v.at(i) = capacity.at(i);
        return v;

    }

    ConfData emptyTheContainers(std::vector<int> v, int i){
        v.at(i) = 0;
        return v;
    }

    ConfData  pour(std::vector<int> v, int i, int j){

        int min; 
        int canPour = capacity.at(j) - v.at(j);
        min = (v.at(i)<canPour)? v.at(i): canPour;
        v.at(i)-=min;
        v.at(j)+=min;

        return v;
    }

    void displayPaths(std::list<ConfData> temp){
 
     std::list<ConfData> bestPathList = temp;
    
        
        std::cout <<"The solution needs to be \n";
         for (std::list<ConfData>::iterator it=bestPathList.begin(); it!=bestPathList.end(); ++it)
            {     
                for (std::vector<int>::iterator itv = (*it).begin() ; itv != (*it).end(); ++itv)
                    std::cout << ' ' << *itv;
                    std::cout << '\n'; 
            }  
    }
    


    ConfData getKey(std::map<ConfData,ConfData> *temp, ConfData find){
        
        for (std::map<ConfData,ConfData>::iterator it=temp->begin(); it!=temp->end(); ++it)
        { 
            if (it->first == find){
                ConfData value = it->second;
                return value;
            }
        }
        return find;
    }
};

int main(int argc, char *argv[]){

    //cout<<argc<<"\n";
    ConfData capacity;
    ConfData initialConfiguration; 
    ConfData goal;

    int targetWater = atoi(argv[1]);
    goal.push_back(targetWater);
    for (int i = 2; i < argc; ++i)
    {   
      //  cout<<argv[i]<<" hi \n";
        capacity.push_back(atoi(argv[i]));
        initialConfiguration.push_back(0);

    } 
    // initialConfiguration.push_back(0);//testing
    // initialConfiguration.push_back(0);
    // initialConfiguration.push_back(0);
    // initialConfiguration.push_back(0);
    
    // capacity.push_back(3);
    // capacity.push_back(5);
    // capacity.push_back(7);
    // capacity.push_back(13);
    // 
    // goal.push_back(11);
    
    water w (initialConfiguration, capacity, goal);
    
    solution<ConfData, ConfData> *s = new solution<ConfData, ConfData>( initialConfiguration, goal);
    s->solve(w);
   s = NULL;
 
    return 0;	
}