#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

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

static void rail_fence_decryption_single(string &src, string &dst, int depth)
{
    int n = src.length();

    if (depth == 1) {
        dst = src;
        return;
    }

    // Declare  a 2D vector 
    vector<vector<char>> rows(depth, vector<char>(n, '\0'));

    int row = 0;
    int direc = 1;  // 1: down, -1: up

    // Step 1: Mark the zigzag path with '$'
    for (int i = 0; i < n; i++) {
        rows[row][i] = '$';  

        row += direc;
        if (row == 0 || row == depth - 1) {
            direc = -direc;  // Change direction 
        }
    }

    // Step 2: Fill the zigzag pattern base on the signal of $
    int index = 0;
    for (int r = 0; r < depth; r++) {
        for (int c = 0; c < n; c++) {
            if (rows[r][c] == '$') {
                rows[r][c] = src[index++];
            }
        }
    }

    // Step 3: Read the message base on the zigzag path
    dst.clear();  
    row = 0;
    direc = 1;
    for (int i = 0; i < n; i++) {
        dst += rows[row][i];  
        
        row += direc;
        if (row == 0 || row == depth - 1) {
            direc = -direc;  
        }
    } 
}

void rail_fence_decryption(string &cipher, string &plaintxt, int depth, int repeat)
{
    string src = cipher;
    string dst;
    do {
        dst.clear();
        rail_fence_decryption_single(src, dst, depth); 
        src = dst;
    } while (--repeat > 0);

    plaintxt=dst;
}
