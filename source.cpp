#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "Reviews.h"
#include "Functions.h"

#include <Rcpp.h>

using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]

IntegerVector count_negative (SEXP namefile_) {


string namefile = Rcpp::as <std::string> (namefile_);

Reviews* theReviewPtr;

theReviewPtr = new Reviews(namefile);

vector<int> negative = theReviewPtr -> count_negative();

IntegerVector out(negative.size());

for (int i =0; i < negative.size(); ++i ){
  out[i] = negative[i];
}

delete theReviewPtr;

return out;
}
// [[Rcpp::export]]

IntegerVector count_positive (SEXP namefile_) {


  string namefile = Rcpp::as <std::string> (namefile_);

  Reviews* theReviewPtr;

  theReviewPtr = new Reviews(namefile);

  vector<int> positive = theReviewPtr -> count_positive();

  IntegerVector out(positive.size());

  for (int i =0; i < positive.size(); ++i ){
    out[i] = positive[i];
  }

  delete theReviewPtr;

  return out;
}


// [[Rcpp::export]]
StringVector get_vocab(SEXP namefile_) {


  string namefile = Rcpp::as <std::string> (namefile_);

  Reviews* theReviewPtr;

  theReviewPtr = new Reviews(namefile);

  vector<string> vocab = theReviewPtr -> get_vocab();

  StringVector out(vocab.size());

  for (int i = 0; i < vocab.size(); ++i ){
    out[i] = vocab[i];
  }

  delete theReviewPtr;

  return out;
}
