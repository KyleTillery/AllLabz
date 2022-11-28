#include <iostream>
#include "hashTable.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <cmath>

typedef std::chrono::high_resolution_clock Clock;

int main () {


    hashTable<int, int>* t11 = new hashTable<int, int>(500);
    auto t1500 = Clock::now();
    for (int i = 0; i < 500; i++){
        int random = ( rand()%1000);
        t11->add(random,i+1);
    }
    auto t2500 = Clock::now();
    std::cout << "Adding 500 to hash(100%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2500 - t1500).count() << " nanoseconds" << std::endl;
    
    hashTable<int, int>* t12 = new hashTable<int, int>(750);
    auto t1501 = Clock::now();
    for (int i = 0; i < 500; i++){
        int random = ( rand()%1000);
        t12->add(random,i+1);
    }
    auto t2501 = Clock::now();
    std::cout << "Adding 500 to hash(150%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2501 - t1501).count() << " nanoseconds" << std::endl;
   
    hashTable<int, int>* t13 = new hashTable<int, int>(1000);
    auto t1502 = Clock::now();
    for (int i = 0; i < 500; i++){
        int random = ( rand()%1000);
        t13->add(random,i+1);
    }
    auto t2502 = Clock::now();
    std::cout << "Adding 500 to hash(200%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2502 - t1502).count() << " nanoseconds" << std::endl;
   
    hashTable<int, int>* t14 = new hashTable<int, int>(2500);
    auto t1503 = Clock::now();
    for (int i = 0; i < 500; i++){
        int random = ( rand()%1000);
        t14->add(random,i+1);
    }
    auto t2503 = Clock::now();
    std::cout << "Adding 500 to hash(500%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2503 - t1503).count() << " nanoseconds" << std::endl;
    cout <<endl;
   ////////////////////////////////////////////////////////// Next size up /////////////////////////////////////////
    
    hashTable<int, int>* t21 = new hashTable<int, int>(1000);
    auto t11000 = Clock::now();
    for (int i = 0; i < 1000; i++){
        int random = ( rand()%1000);
        t21->add(random,i+1);
    }
    auto t21000 = Clock::now();
    std::cout << "Adding 1000 to hash(100%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t21000 - t11000).count() << " nanoseconds" << std::endl;
       
    hashTable<int, int>* t22 = new hashTable<int, int>(1500);
    auto t11001 = Clock::now();
    for (int i = 0; i < 1000; i++){
        int random = ( rand()%1000);
        t22->add(random,i+1);
    }
    auto t21001 = Clock::now();
    std::cout << "Adding 1000 to hash(150%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t21001 - t11001).count() << " nanoseconds" << std::endl;
   
    hashTable<int, int>* t23 = new hashTable<int, int>(2000);
    auto t11002 = Clock::now();
    for (int i = 0; i < 1000; i++){
        int random = ( rand()%1000);
        t23->add(random,i+1);
    }
    auto t21002 = Clock::now();
    std::cout << "Adding 1000 to hash(200%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t21002 - t11002).count() << " nanoseconds" << std::endl;
    
    hashTable<int, int>* t24 = new hashTable<int, int>(5000);
    auto t11003 = Clock::now();
    for (int i = 0; i < 1000; i++){
        int random = ( rand()%1000);
        t24->add(random,i+1);
    }
    auto t21003 = Clock::now();
    std::cout << "Adding 1000 to hash(500%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t21003 - t11003).count() << " nanoseconds" << std::endl;
    cout <<endl;
 ////////////////////////////////////////////////////////// Next size up /////////////////////////////////////////
   
    hashTable<int, int>* t31 = new hashTable<int, int>(2000);
    auto t12000 = Clock::now();
    for (int i = 0; i < 2000; i++){
        int random = ( rand()%1000);
        t31->add(random,i+1);
    }
    auto t22000 = Clock::now();
    std::cout << "Adding 2000 to hash(100%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t22000 - t12000).count() << " nanoseconds" << std::endl;

    hashTable<int, int>* t32 = new hashTable<int, int>(3000);
    auto t12002 = Clock::now();
    for (int i = 0; i < 2000; i++){
        int random = ( rand()%1000);
        t32->add(random,i+1);
    }
    auto t22002 = Clock::now();
    std::cout << "Adding 2000 to hash(150%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t22002 - t12002).count() << " nanoseconds" << std::endl;
    
    hashTable<int, int>* t33 = new hashTable<int, int>(4000);
    auto t12003 = Clock::now();
    for (int i = 0; i < 2000; i++){
        int random = ( rand()%1000);
        t33->add(random,i+1);
    }
    auto t22003 = Clock::now();
    std::cout << "Adding 2000 to hash(200%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t22003 - t12003).count() << " nanoseconds" << std::endl;
      
    hashTable<int, int>* t34 = new hashTable<int, int>(10000);
    auto t12004 = Clock::now();
    for (int i = 0; i < 2000; i++){
        int random = ( rand()%1000);
        t34->add(random,i+1);
    }
    auto t22004 = Clock::now();
    std::cout << "Adding 2000 to hash(500%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t22004 - t12004).count() << " nanoseconds" << std::endl;
    cout<<endl;
 ////////////////////////////////////////////////////////// Next size up /////////////////////////////////////////

    hashTable<int, int>* t41 = new hashTable<int, int>(5000);
    auto t15001 = Clock::now();
    for (int i = 0; i < 5000; i++){
        int random = ( rand()%1000);
        t41->add(random,i+1);
    }
    auto t25001 = Clock::now();
    std::cout << "Adding 5000 to hash(100%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t25001 - t15001).count() << " nanoseconds" << std::endl;
    
    hashTable<int, int>* t42 = new hashTable<int, int>(7500);
    auto t15002 = Clock::now();
    for (int i = 0; i < 5000; i++){
        int random = ( rand()%1000);
        t42->add(random,i+1);
    }
    auto t25002 = Clock::now();
    std::cout << "Adding 5000 to hash(150%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t25002 - t15002).count() << " nanoseconds" << std::endl;
    
    hashTable<int, int>* t43 = new hashTable<int, int>(10000);
    auto t15003 = Clock::now();
    for (int i = 0; i < 5000; i++){
        int random = ( rand()%1000);
        t43->add(random,i+1);
    }
    auto t25003 = Clock::now();
    std::cout << "Adding 5000 to hash(200%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t25003 - t15003).count() << " nanoseconds" << std::endl;
    
    hashTable<int, int>* t44 = new hashTable<int, int>(25000);
    auto t15004 = Clock::now();
    for (int i = 0; i < 5000; i++){
        int random = ( rand()%1000);
        t44->add(random,i+1);
    }
    auto t25004 = Clock::now();
    std::cout << "Adding 5000 to hash(500%): " << std::chrono::duration_cast<std::chrono::nanoseconds>(t25004 - t15004).count() << " nanoseconds" << std::endl;
    

}