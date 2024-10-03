#ifndef __RAIL_FENCE_ALGORITHM__
#define __RAIL_FENCE_ALGORITHM__

#include <iostream>
#include <string>

using namespace std;


void rail_fence_encryption(string &plaintxt, string &cipher, int depth, int repeat);

void rail_fence_decryption(string &cipher, string &plaintxt, int depth, int repeat);


#endif
