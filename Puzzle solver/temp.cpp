std::vector<int> getAllConfigurations(int currentConfiguration, int *variations, int totalVariations){
        std::vector<int> v ;

        for(int index = 0, index < totalVariations; index++){
            
            int changes = *(totalVariations + index);
            //change is a decrement

            if ((currentConfiguration + changes < = 0)){

                v.push_back(hoursOnClock+currentConfiguration+changes);
            
            }
            else
                 if ((currentConfiguration + changes > hoursOnClock)){

                        v.push_back((currentConfiguration+changes) % hoursOnClock);
                
                }
                else{
                
                    v.push_back(currentConfiguration+changes);
                    
                }
        }
}




 for(std::vector<int>::iterator it = variations.begin(); it!=variations.end();it++){//
            for (int i = 0; i < ; ++i)
            {
                /* code */
            }
            cout<<*it<<"!!! getNextConfiguration \n";
        } 