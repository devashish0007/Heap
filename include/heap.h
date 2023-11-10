/**************************************************************************
 *  $Id$
 *  File:	Heap.h - Definition file for List
 *
 *  Purpose:	
 *
 *  Author:	Devashish Dewangan CS21M017
 *************************************************************************/
#ifndef HEAP_H
#define HEAP_H
#include <iostream>

using namespace std;
#define HEAP_SIZE 1000

typedef int Position;

typedef struct
{
  int priority;                            // Priority value
  string name;                            // Name of the person
  int timeStamp;                        // store Order of arrival of request
}ElemType;

class Heap {
  ElemType persons[HEAP_SIZE];        	// A Heap of integers
  Position last;
public:
  void insertHeap(ElemType x);       	// Insertes an element on to the Heap
  ElemType deleteRoot();             	// DeleteRoot of the Heap
  int empty();                   		// returns 1 if Heap is empty
  void createHeap();             		// creates an empty Heap
  void printHeap();               		// Prints the heap
 };
#endif
