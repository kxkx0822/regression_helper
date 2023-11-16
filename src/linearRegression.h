#pragma once

#include <Rcpp.h>

Rcpp::NumericMatrix addColumnOfOnes(Rcpp::NumericMatrix mat);

Rcpp::NumericVector getBetaHat(Rcpp::NumericMatrix mat, Rcpp::NumericVector y);

Rcpp::List getF(Rcpp::NumericMatrix mat, Rcpp::NumericVector y);

Rcpp::NumericVector getResidual(Rcpp::NumericMatrix mat, Rcpp::NumericVector y);

double getRsquare(Rcpp::NumericMatrix mat, Rcpp::NumericVector y);
