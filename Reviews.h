#ifndef REVIEWS_H
#define REVIEWS_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

#include "functions.h"

class Reviews
{
    public:
        Reviews(string filename_);
        virtual ~Reviews();

        vector <string> get_vocab();
        string get_name();
        vector <int> count_negative();
        vector <int> count_positive();



    private:
        string filename;
        vector <string> allwords_positive;
        vector <string> allwords_negative;
        vector <string> vocab;

};

#endif // REVIEWS_H
