//
//  main.cpp
//  WillContainers
//
//  Created by Julien Esposito on 8/24/16.
//  Copyright © 2016 Julien Esposito. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#include "Vector.hpp"
//
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Vector<int> v;
    for( size_t i = 0; i < 1000; i++ )
    {
        v.push_back(i);
    }
    
    v._PrintInfo(  );
    std::cout << v << std::endl;
    
    Vector<int> v2 = v;
    v2._PrintInfo(  );
    return 0;
}
