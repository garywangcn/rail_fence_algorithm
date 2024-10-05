#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "rail_fence_algorithm.h"

using namespace std;

int main(void)
{
    string Cipertxt;
    int depth = 0;
    int repeat = 0;
   
    std::cout << "please input the Cipertxt:"; 
    std::getline(std::cin, Cipertxt);

    std::cout << "please input the depth:"; 
    std::cin >> depth;

    std::cout << "please input the repeat:"; 
    std::cin >> repeat;

    std::cout << "Decrypt the cipertxt with depth " << depth << " and repeat " << repeat << " times..." << std::endl;

    string src = Cipertxt;
    string Plaintxt;

    rail_fence_decryption(Cipertxt, Plaintxt, depth, repeat);

    std::cout << "Chipertxt : " << Cipertxt << std::endl;
    std::cout << "Plaintxt: " << Plaintxt << std::endl;
    return 0;
}
