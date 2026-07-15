#ifndef REDISLITE_H
#define REDISLITE_H

#include <iostream>
#include <string>
#include <sstream>

#include "Hashmap.h"

using namespace std;

class redislite
{
private:

    HashMap<string, string> hm;

    // Utility Functions
    void to_lower(string& str);

    // Command Processor
    void processCommand(const string& input);

public:

    // Constructor
    redislite();

    // Starts the CLI
    void run();

    // Redis Commands
    void set(string key, string value);

    string get(string key);

    void del(string key);

    bool exists(string key);

    int size();

    void keys();
};

#include "../src/Redislite.tpp"

#endif