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
    last++;
    persons[last]  = x;
    
    Position parent = (last - 1)/2;
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
    ElemType root;
    
    if(!empty())
    {
        root = persons[0];
        persons[0] = persons[last];
        last--;
    }
    
    Position element = 0;
    Position left = 2 * element + 1;
    Position right = 2 * element + 2;
    Position max;
    // printHeap();
    while(element < last){
        
        max = element;
        if (left <= last && persons[left].priority > persons[max].priority)
        {
            max = left;
        }
        if (right <= last && persons[right].priority > persons[max].priority)
        {
            max = right;
        }
        // cout<<"\nleft: "<<persons[left].priority<<"right: "<<persons[right].priority<<"\n";
        if (persons[right].priority == persons[left].priority)
        {   
            
            // cout<<" Priority is equal "<<persons[left].name<<" "<<persons[right].name<<" \n";
            // cout<<persons[left].timeStamp<<" "<< persons[right].timeStamp<<"\n";
            if(persons[right].timeStamp < persons[left].timeStamp)
            {
                max = right;
            }                
            else
            {
                max = left;
            }
        }
        
        
        if (max != element)
        {
            // printHeap();
            // cout<<"\n"<< persons[max].name<<" "<<persons[element].name<<"\n";
            ElemType temp;
            temp = persons[element];
            persons[element] = persons[max];
            persons[max] = temp;
            element = max;
            left = max*2 +1;
            right = max*2 +2;
            // printHeap();
        }
        else
        {
            break;
        }
    }
    
    return root;
}
int Heap::empty(){
    if(last < 0)
    {
        return 1;
    }
    else
    {
        return 0;        
    }   
}
void Heap::createHeap(){
    last = -1; 
}
void Heap::printHeap(){
    // cout<<"\n";
    for(Position i =0;i <= last; i++){
        cout<<persons[i].priority<<" ";
    }
    cout<<"\n";
}

