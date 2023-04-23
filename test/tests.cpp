// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include "textgen.cpp"

using namespace std;

typedef deque<string> prefix;
typedef map<prefix, vector<string>> tab;


TEST(test1, create_prefix_test)
{
    prefix expected = { "word1", "word2", "word3", "word4", "word5" };
    ifstream file;
    file.open("test.txt");
    prefix result = create_prefix(file, 5);

    bool is_equal = expected == result;

    EXPECT_TRUE(is_equal);
}

TEST(test2, create_note_test)
{
    tab expected =
    {
        { { "word1", "word2" }, { "word3", "word2" } },
        { { "word2", "word3" }, { "word1" } }
    };
    tab result;
    prefix key;
    string word;

    key = { "word1", "word2" };
    word = "word3";
    create_note(result, key, word);

    key = { "word2", "word3" };
    word = "word1";
    create_note(result, key, word);

    key = { "word1", "word2" };
    word = "word2";
    create_note(result, key, word);

    bool is_equal = expected == result;

    EXPECT_TRUE(is_equal);
}

TEST(test3, choice_suffix_test)
{
    vector<string> v = { "suffix" };
    string result = random_element(v);
    EXPECT_TRUE(result == v[0]);
}

TEST(test4, choice_single_suffix_test)
{
    vector<string> v = { "suffix1",  "suffix2", "suffix3" };
    string result = random_element(v);
    EXPECT_TRUE(find(v.begin(), v.end(), result) != v.end());
}

TEST(test5, text_generation)
{
    const int NPREF = 2;
    const int MAXGEN = 5;
    tab statetab =
    {
        { { "word1", "word2" }, { "word1" } },
        { { "word2", "word1" }, { "word2", "word1" } },
        { { "word1", "word1" }, { "word1" } }
    };
    generate("test_result.txt", statetab, MAXGEN, NPREF);

    ifstream fresult;
    fresult.open("test_result.txt");
    string result;
    getline(fresult, result);
    fresult.close();

    ifstream fexpected;
    fexpected.open("test_expected.txt");
    bool is_equal = false;
    string expected;
    while (getline(fexpected, expected) && !is_equal)
    {
        is_equal = expected == result;
    }
    fexpected.close();

    EXPECT_TRUE(is_equal);
}
