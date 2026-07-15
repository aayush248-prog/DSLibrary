#ifndef REDISLITE_TPP
#define REDISLITE_TPP

#include <cctype>
#include <sstream>

// more functionalities can be added futher but basic implementations is to be verified first 
inline redislite::redislite()
{
    cout << "Welcome to RedisLite\n";
}


inline void redislite::set(string key, string value)
{
    hm.push(key, value);
}

inline string redislite::get(string key)
{
    return hm[key];
}

inline void redislite::del(string key)
{
    hm.pop(key);
}

inline bool redislite::exists(string key)
{
    return hm.find(key) != NULL;
}

inline int redislite::size()
{
    return hm.count;
}

inline void redislite::keys()
{
    hm.keys();
}


inline void redislite::to_lower(string &str)
{
    for(char &ch : str)
    {
        ch = tolower(ch);
    }
}

inline void redislite::processCommand(const string &input)
{
    try
    {
        stringstream ss(input);

        string command;
        string key;
        string value;

        ss >> command >> key >> value;

        to_lower(command);

        cout << "\033[96moutput>>>>>>>>>>>\033[0m ";

        if(command == "set")
        {
            if(key.empty() || value.empty())
            {
                cout << "\033[1;91mUsage : SET <key> <value>\033[0m";
            }
            else
            {
                set(key, value);
                cout << "\033[1;92mSuccessful\033[0m";
            }
        }
        else if(command == "get")
        {
            cout << get(key);
        }
        else if(command == "del")
        {
            del(key);
        }
        else if(command == "keys")
        {
            keys();
        }
        else if(command == "size")
        {
            cout << size();
        }
        else if(command == "exists")
        {
            cout << boolalpha << exists(key);
        }
        else
        {
            cout << "\033[1;91mInvalid Command\033[0m";
        }

        cout << endl;
    }
    catch(const out_of_range& e)
    {
        cout << "\033[1;91mOut of Range Error : " << e.what() << "\033[0m\n";
    }
    catch(const underflow_error& e)
    {
        cout << "\033[1;91mUnderflow Error : " << e.what() << "\033[0m\n";
    }
    catch(const bad_alloc& e)
    {
        cout << "\033[1;91mMemory Allocation Failed : " << e.what() << "\033[0m\n";
    }
    catch(const exception& e)
    {
        cout << "\033[1;91mException : " << e.what() << "\033[0m\n";
    }
    catch(...)
    {
        cout << "\033[1;91mUnknown Error Occurred.\033[0m\n";
    }
}

inline void redislite::run()
{
    while(true)
    {
        cout << "\033[1;96mredislite>\033[0m ";

        string input;

        getline(cin, input);

        string temp = input;

        to_lower(temp);

        if(temp == "exit")
        {
            cout << "\033[1;95m########## THANKS FOR USING REDISLITE ##############\033[0m\n";
            break;
        }

        processCommand(input);
    }
}

#endif