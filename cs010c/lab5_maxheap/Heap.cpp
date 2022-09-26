#include <iostream>
using namespace std;

#include "Heap.h"

  /*Initializes an empty heap.*/
  Heap::Heap(){
      numItems = 0;
  }

  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
  void Heap::enqueue(PrintJob* job){
      if (MAX_HEAP_SIZE > numItems){
          //empty heap case
          if (numItems == 0){
              arr[numItems] = job;
              numItems+= 1;
          }
          else {
              int index = numItems;
            while ((index > 0) && arr[(index - 1)/2]->getPriority() < job->getPriority()){
                arr[index] = arr[(index - 1)/2];
                index = (index - 1)/2;
            }
            arr[index] = job;
            numItems += 1;
          }
        }
    }
  /*Removes the node with highest priority from the heap. 
  Follow the algorithm on priority-queue slides. */
  void Heap::dequeue(){
    //   if (numItems == 0){
    //       return;
    //   }
      if (numItems == 1){
          arr[0] = 0;
          numItems = 0;
      }
      if (numItems > 1){
          arr[0] = arr[numItems - 1];
          arr[numItems - 1] = 0;
          numItems -= 1;
          trickleDown(0);
      }
  }

  /*Returns the node with highest priority.*/
  PrintJob* Heap::highest(){
      if (numItems > 0){
          return arr[0];
      }
      else {
          return 0;
      }
  }

  /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
  void Heap::print(){
    if(numItems > 0){
        cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;
    }
    else{
        cout << "The heap is empty." << endl;
    }
  }
/*This function is called by dequeue function
  to move the new root down the heap to the 
  appropriare location.*/
  void Heap::trickleDown(int index){
      for (int i = 0; i < numItems; ++i){
          if(arr[index]->getPriority() < arr[i]->getPriority()){
            swap(arr[index],arr[i]);
            //utilizing swap in stl, but i know to swap i owuld have to declare a variable of printjob* temp
          }
      }
  }
