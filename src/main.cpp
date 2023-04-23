#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <map>
#include <vector>
#include <algorithm>
#include "textgen.h"

using namespace std;

typedef deque<string> prefix;
typedef map<prefix, vector<string>> tab;


int main()
{
    const int NPREF = 2;
    const int MAXGEN = 1000;

    tab statetab = create_tab("text.txt", NPREF);
    generate("generation_example.txt", statetab, MAXGEN, NPREF);
}
