#include "sort.h"

#define BLOCK 1024

using namespace std;

int main(int argc, char** argv){

    if(argc == 1){
        cout << "Please give data in argument\nex: ./sort data" << endl;
        return 1;
    }

    else{
    	std::string data;
        
        ifstream file;
        // Open file in read mode
        file.open(argv[1], ios::in);
        
        if(file.is_open()){
            // Read and save each line in data
            while(getline(file, data)){
            	cout << "original : " << data << endl;
            	// Sort the line saved in data
            	quickSort(data, 0, data.size()-1);
            	cout << "sorted : " << data << endl;
            }
        }
        
        file.close();
    }
}
