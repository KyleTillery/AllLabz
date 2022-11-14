#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <array>
#include "priorityQueue.h"
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;


void Make500Array(int array[]){
    for (int i = 0; i < 500; i++){
        int random = (1 + rand() % 500);
        array [i] = random;
    }
}
void Make1000Array(int array[]){
    for (int i = 0; i < 1000; i++){
        int random = (1 + rand() % 1000);
        array [i] = random;
    }
}
void Make2000Array(int array[]){
    for (int i = 0; i < 2500; i++){
        int random = (1 + rand() % 2000);
        array [i] = random;
    }
}
void Make5000Array(int array[]){
    for (int i = 0; i < 5000; i++){
        int random = (1 + rand() % 5000);
        array [i] = random;
    }
}
int main()
{
    //start of arraybased testing
    ArrayBased priorityQueue = ArrayBased();
    

    auto t1500 = Clock::now();
   for (int i = 0; i < 500; i++){
        int random = ( rand());
        priorityQueue.insert(random);
    }
    auto t2500 = Clock::now();
    std::cout << "500 ArrayBased insert: " << std::chrono::duration_cast<std::chrono::microseconds>(t2500 - t1500).count() << " microseconds" << std::endl;
    auto t3500 = Clock::now();
    for (int i = 0; i < 500; i++){
        priorityQueue.DeQueue();
    }
    auto t4500 = Clock::now();
    std::cout << "500 ArrayBased dequeue: " << std::chrono::duration_cast<std::chrono::microseconds>(t4500 - t3500).count() << " microseconds" << std::endl;
    
    
    auto t11000 = Clock::now();
   for (int i = 0; i < 1000; i++){
        int random = ( rand());
        priorityQueue.insert(random);
    }
    auto t21000 = Clock::now();
    std::cout << "1000 ArrayBased insert: " << std::chrono::duration_cast<std::chrono::microseconds>(t21000 - t11000).count() << " microseconds" << std::endl;
    auto t31000 = Clock::now();
    for (int i = 0; i < 1000; i++){
        priorityQueue.DeQueue();
    }
    auto t41000 = Clock::now();
    std::cout << "1000 ArrayBased dequeue: " << std::chrono::duration_cast<std::chrono::microseconds>(t41000 - t31000).count() << " microseconds" << std::endl;
    
    
    auto t12000 = Clock::now();
   for (int i = 0; i < 2000; i++){
        int random = ( rand());
        priorityQueue.insert(random);
    }
    
    auto t22000 = Clock::now();
    std::cout << "2000 ArrayBased insert: " << std::chrono::duration_cast<std::chrono::microseconds>(t22000 - t12000).count() << " microseconds" << std::endl;
    auto t32000 = Clock::now();
    for (int i = 0; i < 2000; i++){
        priorityQueue.DeQueue();
    }
    auto t42000 = Clock::now();
    std::cout << "2000 ArrayBased dequeue: " << std::chrono::duration_cast<std::chrono::microseconds>(t42000 - t32000).count() << " microseconds" << std::endl;
    


    auto t15000 = Clock::now();
   for (int i = 0; i < 5000; i++){
        int random = ( rand());
        priorityQueue.insert(random);
    }
    auto t25000 = Clock::now();
    std::cout << "5000 ArrayBased insert: " << std::chrono::duration_cast<std::chrono::microseconds>(t25000 - t15000).count() << " microseconds" << std::endl;
    auto t35000 = Clock::now();
    for (int i = 0; i < 4999; i++){
        priorityQueue.DeQueue();
    }
    auto t45000 = Clock::now();
    std::cout << "5000 ArrayBased dequeue: " << std::chrono::duration_cast<std::chrono::microseconds>(t45000 - t35000).count() << " microseconds" << std::endl;
    
    //start of heapbased testing
    HeapBased priorityQueue2 = HeapBased();
    
    
    auto t5500 = Clock::now();
   for (int i = 0; i < 500; i++){
        int random = ( rand());
        priorityQueue2.insert(random);
    }
    auto t6500 = Clock::now();
    std::cout << "500 HeapBased insert: " << std::chrono::duration_cast<std::chrono::microseconds>(t6500 - t5500).count() << " microseconds" << std::endl;
    auto t7500 = Clock::now();
    for (int i = 0; i < 500; i++){
        priorityQueue2.DeQueue();
    }
    auto t8500 = Clock::now();
    std::cout << "500 HeapBased dequeue: " << std::chrono::duration_cast<std::chrono::microseconds>(t8500 - t7500).count() << " microseconds" << std::endl;
    
    
    auto t51000 = Clock::now();
   for (int i = 0; i < 1000; i++){
        int random = ( rand());
        priorityQueue2.insert(random);
    }
    auto t61000 = Clock::now();
    std::cout << "1000 HeapBased insert: " << std::chrono::duration_cast<std::chrono::microseconds>(t61000 - t51000).count() << " microseconds" << std::endl;
    auto t71000 = Clock::now();
    for (int i = 0; i < 1000; i++){
        priorityQueue2.DeQueue();
    }
    auto t81000 = Clock::now();
    std::cout << "1000 HeapBased dequeue: " << std::chrono::duration_cast<std::chrono::microseconds>(t81000 - t71000).count() << " microseconds" << std::endl;
    
    
    auto t52000 = Clock::now();
   for (int i = 0; i < 2000; i++){
        int random = ( rand());
        priorityQueue2.insert(random);
    }
    auto t62000 = Clock::now();
    std::cout << "2000 HeapBased insert: " << std::chrono::duration_cast<std::chrono::microseconds>(t62000 - t52000).count() << " microseconds" << std::endl;
    auto t72000 = Clock::now();
    for (int i = 0; i < 2000; i++){
        priorityQueue2.DeQueue();
    }
    auto t82000 = Clock::now();
    std::cout << "2000 HeapBased dequeue: " << std::chrono::duration_cast<std::chrono::microseconds>(t82000 - t72000).count() << " microseconds" << std::endl;
    

    auto t55000 = Clock::now();
   for (int i = 0; i < 5000; i++){
        int random = ( rand());
        priorityQueue2.insert(random);
    }
    auto t65000 = Clock::now();
    std::cout << "5000 HeapBased insert: " << std::chrono::duration_cast<std::chrono::microseconds>(t65000 - t55000).count() << " microseconds" << std::endl;
    auto t75000 = Clock::now();
    for (int i = 0; i < 4999; i++){
        priorityQueue2.DeQueue();
    }
    auto t85000 = Clock::now();
    std::cout << "5000 HeapBased dequeue: " << std::chrono::duration_cast<std::chrono::microseconds>(t85000 - t75000).count() << " microseconds" << std::endl;

    return 0;


}