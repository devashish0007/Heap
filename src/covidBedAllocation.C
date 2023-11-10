/*-------------------------------------------------------------------------
 *  main -- Main Program for Complement
 *    Args:	none
 *    Returns:	List of Complement i.e. (A - B) in sorted order
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/

//Note: Donot edit the code given in between the boundaries:
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


#include <iostream>
#include "../include/Heap.h"
using namespace std;

void AllotBed(ElemType *array, int n)  // Use class Heap functions to define this function
{
    Heap heap; // priority heap 
    heap.createHeap();
    for(int i=0; i<n; i++ )
    {
        // insert element in heap.
        heap.insertHeap(array[i]);
    }

    ElemType temp;
    for(int i = 0; i < n; i++)
    {
        temp = heap.deleteRoot(); // extract max from heap
        cout<<temp.name<<" ";

    }
    
}    


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ElemType array[1000]; // array to store request
    int N; // no. of request
    cin>>N;
    // loop to read input (name, age)
    for(int i = 0;i < N; i++)
    {   
        int age;
        cin>> array[i].name;
        cin>>age;
        array[i].priority = 5 - (age-1)/20; // assign priority w.r.t. age 
        array[i].timeStamp = i;
    }
    // Allot Bed
    AllotBed(array, N);
    
    return 0;
}
