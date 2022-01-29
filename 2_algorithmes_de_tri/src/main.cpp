#include "sort.h"

#define BLOCK 1024

int main(int argc, char** argv){
    string data;

    if(argc == 1){
        cout << "Please give data in argument\nex: ./sort data" << endl;
        return 1;
    }

    else{
        fstream file;
        file.open(argv[1], ios::in);
        if(file.is_open()){
            while(getline(file, data)){
                cout << data << endl;
            }
        }
        file.close();
    }
}