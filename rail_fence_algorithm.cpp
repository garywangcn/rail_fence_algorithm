#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;


static void rail_fence_encryption_single(string &src, string &dst, int depth)
{
    string rows[depth];
    int row = 0;
    int direct = (depth == 1)? 0 : 1;  // 0: no direction, 1: down, -1: up

    for (int i=0; i<src.length(); i++) {
        rows[row].push_back(src[i]);

        row += direct;

        if (row == 0 || row == depth-1) {
            direct *= -1;
        }
    }
   
    for (row=0; row<depth; row++) {
        dst.append(rows[row]);
    } 
}

void rail_fence_encryption(string &plaintxt, string &cipher, int depth, int repeat)
{
    string src = plaintxt;
    string dst;
    do {
        dst.clear();
        rail_fence_encryption_single(src, dst, depth); 
        src = dst;
    } while (--repeat > 0);

    cipher = dst;
}

void rail_fence_decryption(string &cipher, string &plaintxt, int depth, int time)
{
}
