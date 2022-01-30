#include <iostream>
#include <fstream>
#include <string>      
#include <thread>
#include <vector>

#include "Sort.h"

using namespace std;
#define BLOCK_SIZE 1024 

int main(int argc,char **argv){
    if(argc==1){
        cout<<"Usage: ./Sort file_name"<<endl;
        return 1;
    }
    else{
	    int nb_blocks;
      
        vector<char> block(BLOCK_SIZE, 0);
        string data = "";
        
        ofstream newFile("sorted_data.txt");
        
        if(ifstream file{argv[1], ifstream::binary}){
            // Read and save each blocks in vector
            while(file.read(block.data(), block.size())){
            	// Get the first character
            	data += block.front();
            }
            file.close();
        }
        nb_blocks = data.size();
        
        // Sort 1st and 2nd half of data in 2 thread
        thread t1(sort, ref(data), 0, (nb_blocks/2));
        thread t2(sort, ref(data), (nb_blocks/2), nb_blocks-1);
        
        // Synchronize thread
        t1.join();
        t2.join();
        
        // Sort result of threads and write in new file
        // In new file write blocks 1024 same character
        int countT1=0;
        int countT2=nb_blocks/2;
        for(int i=0; i<nb_blocks; i++){
        	if(countT1>=nb_blocks/2){
        		newFile << string(1024, data[countT2]);
        		countT2++;
        	}else if(data[countT1]<data[countT2]){
        		newFile << string(1024, data[countT1]);
        		countT1++;
        	}else if(data[countT1]<data[countT2]){
        		newFile << string(1024, data[countT2]);
        		countT2++;
        	}
        }
        newFile.close();
    } 

    return 0;
}
