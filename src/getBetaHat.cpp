/// Estimate Beta Hat
//'
 //' This function estimates the coefficients (Beta Hat) of a linear regression model.
 //'
 //' @param mat Numeric matrix of independent variables.
 //' @param y Numeric vector of dependent variable.
 //' @return Numeric vector representing the estimated coefficients.
#include <Rcpp.h>
#include <RcppEigen.h>
#include "linearRegression.h"
using namespace Rcpp;
using namespace Eigen;

// [[Rcpp::depends(RcppEigen)]]
using Eigen::Map;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::LLT;

// [[Rcpp::export]]
NumericVector getBetaHat(NumericMatrix mat, NumericVector y){
  NumericMatrix x = addColumnOfOnes(mat);
  VectorXd Y = as<Map<VectorXd>>(y);
  MatrixXd X = as<Map<MatrixXd>>(x);

  MatrixXd XtX = X.transpose() * X;
  VectorXd XtY = X.transpose() * Y;
  LLT<MatrixXd> llt(XtX);

  VectorXd beta = llt.solve(XtY);

  return wrap(beta);
}
