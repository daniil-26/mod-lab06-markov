// Copyright 2021 GHA Test Team
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>


typedef std::deque<std::string> prefix;
typedef std::map<prefix, std::vector<std::string>> tab;


template <typename T>
T random_element(std::vector<T> v);

prefix create_prefix(std::ifstream& file, int npref);

void create_note(tab* statetab, prefix key, std::string word);


tab create_tab(std::string fname, int npref);

void generate(std::string fname, tab statetab, int maxgen, int npref);
