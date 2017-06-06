#include "Reviews.h"


Reviews::Reviews(string filename_)
{
//ctor: split IDs, sentiments and reviews
    filename = filename_;

    ifstream file(filename_.c_str());
    string line;

    vector<string> all;

    while (getline(file, line))
    {
        process_tsv(line, "<br />");

        istringstream linestream(line);

        for (string each;
            getline(linestream, each, '\t');
            all.push_back(each)); // no implementation for this loop
    };

//Extract all words appearing in negative and positive comments

    for (int i = 0; i < all.size(); i += 3)
    {
        istringstream reviewlines(all[i + 2]);

        if (all[i + 1 ] == "1")
        {
            for (string each;
                getline(reviewlines, each, ' ');
                allwords_positive.push_back(each));
        }
        else if (all[i + 1 ] == "0")
        {
            for (string each;
                getline(reviewlines, each, ' ');
                allwords_negative.push_back(each));
        };
    }

// create a vector of unique words only:
    vocab = allwords_negative;
    vocab.insert(vocab.end(),
                 allwords_positive.begin(),
                 allwords_positive.end());

    sort(vocab.begin(), vocab.end());
    vocab.erase(unique(vocab.begin(), vocab.end()), vocab.end());

}
Reviews::~Reviews()
{
    //dtor
}

vector <string> Reviews::get_vocab()
{
return vocab;
}


vector <int> Reviews::count_positive()
{
    vector<int> vec_positive (vocab.size(), 0);

    for (int i = 0; i < vocab.size(); i++)
    {
        for (int k = 0; k < allwords_positive.size(); k++)
            {if(allwords_positive[k] == vocab[i]) vec_positive[i]++;};
    };

    return vec_positive;
}


vector <int> Reviews::count_negative()
{
    vector<int> vec_negative (vocab.size(), 0);

    for (int i = 0; i < vocab.size(); i++)
    {
        for (int k = 0; k < allwords_negative.size(); k++)
            {if(allwords_negative[k] == vocab[i]) vec_negative[i]++;};
    };

    return vec_negative;
}

string Reviews::get_name()
{
    return filename;
}
