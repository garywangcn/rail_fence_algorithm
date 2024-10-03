#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "rail_fence_algorithm.h"

using namespace std;

class RailFenceAlgorithmTest : public ::testing::Test {
};

TEST_F(RailFenceAlgorithmTest, EncryptionTest1) {
    std::string plaintext = "CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES.";
    std::string expected_cipher = "CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES.";
    std::string cipher;
    int depth = 1;
    int repeat = 1;

    rail_fence_encryption(plaintext, cipher, depth, repeat);

    EXPECT_EQ(cipher, expected_cipher);
}

TEST_F(RailFenceAlgorithmTest, EncryptionTest2) {
    std::string plaintext = "CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES.";
    std::string expected_cipher = "CYTLG STEPATC N TD FTCNQE O EUECMUIAINI H RSNEO HR ATE ALDAVRAISRPOOYI H RCIEADSUYO EHIUSFRSCR OMNCTO NTEPEEC FTIDPRISCLE DESRE.";
    std::string cipher;
    int depth = 2;
    int repeat = 1;

    rail_fence_encryption(plaintext, cipher, depth, repeat);

    EXPECT_EQ(cipher, expected_cipher);
}

TEST_F(RailFenceAlgorithmTest, EncryptionTest3) {
    std::string plaintext = "CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES.";
    std::string expected_cipher = "CTGSEACNT TNEOEEMIIIHRNOH T LARIROY  CEDUOEISRC MCONEECFIPICEDSEYL TPT  DFCQ  UCUAN  SE RAEADVASPOIHRIASY HUFSRONT TPE TDRSL ER.";
    std::string cipher;
    int depth = 2;
    int repeat = 2;

    rail_fence_encryption(plaintext, cipher, depth, repeat);

    EXPECT_EQ(cipher, expected_cipher);
}
