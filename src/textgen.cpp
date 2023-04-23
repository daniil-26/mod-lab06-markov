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


template <typename T>
T random_element(vector<T> v)
{
    random_device rd;
    mt19937 gen(rd());
    return v[gen() % v.size()];
}

prefix create_prefix(ifstream& file, const int npref)
{
    prefix key;
    string word;
    for (int _ = 0; _ < npref; _++)
    {
        file >> word;
        key.push_back(word);
    }
    return key;
}

void create_note(tab& statetab, prefix key, string word)
{
    if (statetab.count(key))
    {
        statetab[key].push_back(word);
    }
    else
    {
        statetab.insert({ key, { word } });
    }
}


tab create_tab(string fname, const int npref)
{
    tab statetab;
    prefix key;
    string word;

    ifstream file;
    file.open(fname);
    key = create_prefix(file, npref);
    while (file >> word)
    {
        create_note(statetab, key, word);
        key.pop_front();
        key.push_back(word);
    }
    file.close();

    return statetab;
}

void generate(string fname, tab statetab, const int maxgen, const int npref)
{
    vector<prefix> keys;
    for (auto const& element : statetab) {
        keys.push_back(element.first);
    }
    prefix key = random_element(keys);
    string word;

    ofstream file;
    file.open(fname);
    
    for (string word : key)
    {
        file << word << " ";
    }
    for (int _ = 0; _ < maxgen - npref; _++)
    {
        if (statetab.count(key))
        {
            word = random_element(statetab[key]);
            file << word << " ";
            key.pop_front();
            key.push_back(word);
        }
        else return;
    }

    file.close();
}
