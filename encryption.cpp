#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "rail_fence_algorithm.h"

using namespace std;

int main(void)
{
    string plaintxt;
    int depth = 0;
    int repeat = 0;
   
    std::cout << "please input the plaintxt:"; 
    std::getline(std::cin, plaintxt);

    std::cout << "please input the depth:"; 
    std::cin >> depth;

    std::cout << "please input the repeat:"; 
    std::cin >> repeat;

    std::cout << "Encrypt the plaintxt with depth " << depth << " and repeat " << repeat << " times..." << std::endl;

    string src = plaintxt;
    string cipher;

    rail_fence_encryption(plaintxt, cipher, depth, repeat);

    std::cout << "Plaintxt : " << plaintxt << std::endl;
    std::cout << "Chipertxt: " << cipher << std::endl;
    return 0;
}
