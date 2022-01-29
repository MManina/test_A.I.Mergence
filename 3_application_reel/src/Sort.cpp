#include "Sort.h"

using namespace std;

void permut_data(string & data,unsigned a,unsigned b){
    char tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}

unsigned partition(string &  data, unsigned first, unsigned last, unsigned pivot)
{
    permut_data(data,pivot,last);

    unsigned j = first;
    for(unsigned i=first;i<=last-1;i++)
    {
        if(data[i]<=data[last])
        {
            permut_data(data,i,j);
            j++;
        }
    }
    permut_data(data,last,j);
    return(j);
}
unsigned int choose_pivot(string data, unsigned first, unsigned last){
    return first + rand() % (last-first);
}

void sort(string & data, int first, int last)
{
    if(first == -1){
        first = 0;
    }
    if(last == -1){
        last = (int) data.size() -1;
    }
    if(first<last)
    {
        unsigned int pivot=choose_pivot(data, first, last);
        pivot = partition(data,first,last, pivot);
        sort(data,first,pivot-1);
        sort(data,pivot+1,last);
    }
}
