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

TEST_F(RailFenceAlgorithmTest, EncryptionTest4) {
    std::string plaintext = "CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES.";
    std::string expected_cipher = "CYLIETSTGENC AEUEERRCLMU OPYAICE  SRIPAOSTSTN TEECID  IDPYDONDEAVR NCHAEHSTOFRCT EOSI TFNIN QD HHIARFORPU.S  OEUE ER  CIS RTMLAC";
    std::string cipher;
    int depth = 4;
    int repeat = 5;

    rail_fence_encryption(plaintext, cipher, depth, repeat);

    EXPECT_EQ(cipher, expected_cipher);
}

TEST_F(RailFenceAlgorithmTest, DecryptionTest1) {
    std::string cipher = "TAOTINEN KAT I ODIOAEI OHHLSCTE TTETOEL BI IHI GAO   EPSEA TO SS  EEK  ELRCPTSIY EANRPHMCYEK E CREAAIEJURTE  IEASHI MA DRN RH  AUWTA RF EFTFHENTPSF Q   TAILB E TTECAPMSIYIY SRPURNTBL YCL OANAO  E  TVREAOSHOTTNULSRHK";
    std::string expected_plaintext = "TAOTINEN KAT I ODIOAEI OHHLSCTE TTETOEL BI IHI GAO   EPSEA TO SS  EEK  ELRCPTSIY EANRPHMCYEK E CREAAIEJURTE  IEASHI MA DRN RH  AUWTA RF EFTFHENTPSF Q   TAILB E TTECAPMSIYIY SRPURNTBL YCL OANAO  E  TVREAOSHOTTNULSRHK";
    std::string plaintext;
    int depth = 1;
    int repeat = 1;

    rail_fence_decryption(cipher, plaintext, depth, repeat);

    EXPECT_EQ(plaintext, expected_plaintext);
}

TEST_F(RailFenceAlgorithmTest, DecryptionTest2) {
    std::string cipher = "TAOTINEN KAT I ODIOAEI OHHLSCTE TTETOEL BI IHI GAO   EPSEA TO SS  EEK  ELRCPTSIY EANRPHMCYEK E CREAAIEJURTE  IEASHI MA DRN RH  AUWTA RF EFTFHENTPSF Q   TAILB E TTECAPMSIYIY SRPURNTBL YCL OANAO  E  TVREAOSHOTTNULSRHK";
    std::string expected_plaintext = "TPTSAEEAO CTTOA ISPSN M EESENKI   YEKLIRACYPTT S ISYI RE APNORUPDHRMICNYOETKA BEE LCIR E AYAOICEHJLUHR TLEO S AICENATSAHEIO  M AT  DTRENE  RTH  O TAEUVWLTRA  ERBFA IEOF TSFIHHEHNOTIPTS FT GQN A U OTLA ISL BR  EH ETK";
    std::string plaintext;
    int depth = 3;
    int repeat = 1;

    rail_fence_decryption(cipher, plaintext, depth, repeat);

    EXPECT_EQ(plaintext, expected_plaintext);
}


TEST_F(RailFenceAlgorithmTest, DecryptionTest3) {
    std::string cipher = "TAOTINEN KAT I ODIOAEI OHHLSCTE TTETOEL BI IHI GAO   EPSEA TO SS  EEK  ELRCPTSIY EANRPHMCYEK E CREAAIEJURTE  IEASHI MA DRN RH  AUWTA RF EFTFHENTPSF Q   TAILB E TTECAPMSIYIY SRPURNTBL YCL OANAO  E  TVREAOSHOTTNULSRHK";
    std::string expected_plaintext = "THE RAILFENCE CIPHER IS AN EASY TO APPLY TRANSPOSITION CIPHER THAT JUMBLES UP THE ORDER OF THE LETTERS OF A MESSAGE IN A QUICK CONVENIENT WAY IT ALSO HAS THE SECURITY OF A KEY TO MAKE IT A LITTLE BIT HARDER TO BREAK";
    std::string plaintext;
    int depth = 3;
    int repeat = 3;

    rail_fence_decryption(cipher, plaintext, depth, repeat);

    EXPECT_EQ(plaintext, expected_plaintext);
}

TEST_F(RailFenceAlgorithmTest, DecryptionTest4) {
    std::string cipher = "CYLIETSTGENC AEUEERRCLMU OPYAICE  SRIPAOSTSTN TEECID  IDPYDONDEAVR NCHAEHSTOFRCT EOSI TFNIN QD HHIARFORPU.S  OEUE ER  CIS RTMLAC";
    std::string expected_plaintext = "CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES.";
    std::string plaintext;
    int depth = 4;
    int repeat = 5;

    rail_fence_decryption(cipher, plaintext, depth, repeat);

    EXPECT_EQ(plaintext, expected_plaintext);
}
