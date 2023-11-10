/*-------------------------------------------------------------------------
 *  Complement.C - Implements Complent of two List
 *  Version:	$Name$
 *  Module:	
 *
 *  Purpose:	
 *  See:	
 *
 *  Author:	Devashish Dewangan CS21M017
 *
 *  Created:        Mon 20-Sep-2021 15:00:00
 *  Last modified:  Mon 20-Sep-2021 15:00:00 By Devashish Dewangan
 *  $Id$
 *
 *  Bugs:	
 *
 *  Change Log:	<Date> <Author>
 *  		<Changes>
 -------------------------------------------------------------------------*/
#include <iostream>
#include "../include/Heap.h"
using namespace std;
typedef int elementType;
typedef int Position;


void Heap::insertHeap(ElemType x){
    last++; // increment last position
    persons[last]  = x;  // inserting element at leaf node
    
    Position parent = (last - 1)/2; // position of parent
    Position element = last;
    // Heapify 
    while(element > 0 && persons[parent].priority < persons[element].priority)
    {
        ElemType temp;
        temp = persons[element];
        persons[element] = persons[parent];
        persons[parent] = temp;
        element = parent;
        parent = (element-1)/2;
    }
    
}
ElemType Heap::deleteRoot(){
    ElemType root; // store the extracting element
    
    // Check if the heap is not empty
    if(!empty())
    {
    	// if not empty then extract max and place the last leaf node.
        root = persons[0];
        persons[0] = persons[last];
        last--;
    }
    // initializing postions
    Position element = 0;
    Position left = 2 * element + 1;
    Position right = 2 * element + 2;
    Position max;
    // 	heapifying  
    while(element < last){
        
        max = element;
        // check the left node 
        if (left <= last && persons[left].priority > persons[max].priority)
        {
            // if higher priority then update max
            max = left;
        }
        // check right node
        if (right <= last && persons[right].priority > persons[max].priority)
        {
            // if higher priority then update max
            max = right;
        }
	
	// if both has equal priority
        if (persons[right].priority == persons[left].priority)
        {   
            
            // update with oldest request
            if(persons[right].timeStamp < persons[left].timeStamp)
            {
                max = right;
            }                
            else
            {
                max = left;
            }
        }
        
  	// check if max was changed      
        if (max != element)
        {
            // then swap 
            ElemType temp;
            temp = persons[element];
            persons[element] = persons[max];
            persons[max] = temp;
            element = max;
            left = max*2 +1; // update left child
            right = max*2 +2; // update right child

        }
        else
        {
            // heap is heapified
            break;
        }
    } // (element < last)
    
    return root;
}
int Heap::empty(){
    // Check position of last element
    if(last < 0)
    {
    	// empty
        return 1;
    }
    else
    {
    	// not empty
        return 0;        
    }   
}
void Heap::createHeap(){
    // intialize last position of element
    last = -1; 
}
void Heap::printHeap(){
    // print the priority of element of heap
    for(Position i =0;i <= last; i++){
        cout<<persons[i].priority<<" ";
    }
    cout<<"\n";
}

