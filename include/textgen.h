#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <map>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

typedef deque<string> prefix;
typedef map<prefix, vector<string>> tab;


tab create_tab(string fname, int npref);

void generate(string fname, const tab statetab, const int maxgen, const int npref);
