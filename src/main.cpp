// Copyright 2021 GHA Test Team
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <map>
#include <vector>
#include <cstdlib>
#include "textgen.h"


typedef std::deque<std::string> prefix;
typedef std::map<prefix, std::vector<std::string>> tab;


int main() {
    const int NPREF = 2;
    const int MAXGEN = 1000;

    tab statetab = create_tab("text.txt", NPREF);
    generate("generation_example.txt", statetab, MAXGEN, NPREF);
}
