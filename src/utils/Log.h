/* A shitty logging system written on the go, so don't take this seriously!
   I will improve this crappy system but it has some basic features like supporting
   more than 1 argument thanks to the goodness of vartic arguments or varadic???
   Every function defined here is a template function as you can see and this style 
   was chosen by another guy (not the system!) that helped me make this atleast. But in the 
   future i will add enum classes to choose between types of messages. I also decided to
   print the messages with timestamps but using locales seems to be a garbage method, and
   again i will improve this for my and for your sake.

   Written By: System Coding a.k.a Revanth
   Date: 10-01-2023
*/


#pragma once

#include <string>
#include <iostream>
#include <iomanip>

namespace utils {
    class Log
    {
    public:
        template<typename... Args>
        static void Info(const Args&... args)
        {
            (std::cout << ... << args);
        }

        template<typename... Args>
        static void Error(const Args&... args)
        {
            (std::cout << ... << args);
        }

        template<typename... Args>
        static void Warn(const Args&... args)
        {
            (std::cout << ... << args);
        }
    };
};