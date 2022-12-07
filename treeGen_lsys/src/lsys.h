#ifndef LSYS_H
#define LSYS_H

#include <string>
#include "turtle.h"
using namespace std;

class lsys{
    public:
        string omega, genStr;
        Turtle turt1;
        int depth1;

        lsys(int d=0, string w=""):
            depth1(d), omega(w){}

        string productionrules(char s); 

        void create_sequence(string currs="", int depth=0, int current_depth=0); 
   
        void visualise_sequence(string sentence="");
};

#endif