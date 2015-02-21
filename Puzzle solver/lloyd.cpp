#include <map>
#include <list>
#include "solution2.h"
#include "puzzle.h"
#include <iostream> 
#include <fstream>
#include <cstdlib>



typedef std::vector<string> ConfData;

class lloyd : public puzzle<ConfData, ConfData>{
public:

	int hieght;
	int width;
	ConfData initialConfiguration;
	ConfData goal;
	ostream &os;

	lloyd(int hieght, int width, ConfData initialConfiguration, ConfData goal, ostream &os)
	:hieght(hieght), width(width), initialConfiguration(initialConfiguration), goal(goal), os(os){

		
	}

	bool isGoal( ConfData configuration){

		for(int row = 0; row < configuration.size(); row++)
			{
				if(configuration.at(row).compare(goal.at(row)) !=0)
					return false;
			}
			return true;

	}

std::vector<ConfData> getNextConfiguration(ConfData confiPuzzle){
	
	std::vector<ConfData> c;
  	for(int row = 0; row < confiPuzzle.size(); row++)
			for(int col = 0; col<confiPuzzle.at(row).size(); col++)
			{
				if(confiPuzzle.at(row).at(col) == '.')
				{
					if(col-1 > -1 )
						 c.push_back(swap(confiPuzzle, row, col, row, col-1));
					if(col+1 < width)
						c.push_back(swap(confiPuzzle, row, col, row, col+1));
					if(row+1 < hieght)
						c.push_back(swap(confiPuzzle, row, col, row+1, col));
					if(row-1 > -1)
						c.push_back(swap(confiPuzzle, row, col, row-1, col));
				}
			}

	return c;

}

ConfData swap(ConfData board, int row, int col, int newRow, int newCol)
{
	// cout<<"initial string "<<board[0]<<"\n";
	// cout<<" row "<<row<<" col"<<col<<"\n";
	// cout<<" newRow "<<newRow<<" newCol "<<newCol<<"\n";
	char temp = board[row][col];
	board[row][col] = board[newRow][newCol];
	board[newRow][newCol] = temp;

	// cout<<"modified string"<<board[0]<<"\n";
	return board;
}


  void displayPaths(std::list<ConfData> temp){
        
        std::list<ConfData> bestPathList = temp;      
        os<<"The solution needs to be\n";
         for (std::list<ConfData>::iterator it=bestPathList.begin(); it!=bestPathList.end(); ++it)
            {     
                for (ConfData::iterator itv = (*it).begin() ; itv != (*it).end(); ++itv)
                    os << ' '<< *itv <<"\n";
                    os<< "-----------------\n"; 
            }  
    }

};


int main(int argc, char *argv[]){
  
	int height = 0;
	int width = 0;
    ConfData initialConfiguration;
    ConfData goal;
   
	if (argc != 3){

		cerr << "2 args only" << endl;
	}
	else{
			std::istream *isp;
			std::ifstream ifs;
			std::ostream *osp;
			std::ofstream ofs;

			if (argv[1][0] == '-' && argv[1][1] == '\0'){
				isp = &cin;
			}
			else{
				ifs.open(argv[1]);
				isp = &ifs;
			}
			
			istream &is = *isp;

			if (argv[2][0] == '-' && argv[2][1] == '\0'){
				osp = &cout;
			}
			else{
					ofs.open(argv[2]);
					osp = &ofs;
				}
			
			 
		

		is >> width >> height;
		char input[width];
		for (int i = 0; i != height; ++i){
			 for (int j = 0; j != width; ++j){
				is >> input[j];
			}
			
			initialConfiguration.push_back(input);
		}

		//is >>input[0];//blank line;
		for (int i = 0; i != height; ++i){
			for (int j = 0; j != width; ++j){

				is >> input[j];//reading the current character
				//pushing the character into init vector
			}

			goal.push_back(input);
		}
		// for(int i = 0; i != width; i++)
		// 	{
		// 		cout<<input[i];
		// 	}
		// 	cout<<"\n";

    lloyd w(height,width,initialConfiguration,goal, *osp);
    solution<ConfData, ConfData> *s = new solution<ConfData, ConfData>( initialConfiguration, goal);
    s->solve(w);
	}
 
    return 0;	
}

