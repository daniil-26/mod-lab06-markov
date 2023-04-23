// Copyright 2021 GHA Test Team
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <map>
#include <vector>
#include <algorithm>
#include <random>


typedef std::deque<std::string> prefix;
typedef std::map<prefix, std::vector<std::string>> tab;


tab create_tab(std::string fname, const int npref);

void generate(std::string fname, tab statetab, const int maxgen, const int npref);
