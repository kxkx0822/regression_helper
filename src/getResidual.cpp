/// Get residual
//'
 //' This function calculates the residuals(Y-Yhat) of a linear regression model.
 //'
 //' @param mat Numeric matrix of independent variables.
 //' @param y Numeric vector of dependent variable.
 //' @return Numeric vector representing the residuals.
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
NumericVector getResidual(NumericMatrix mat, NumericVector y){
  NumericMatrix x = addColumnOfOnes(mat);

  NumericVector beta = getBetaHat(mat, y);
  VectorXd beta_vector = as<Map<VectorXd>>(beta);
  // print(beta_vector.)
  MatrixXd x_matrix = as<Map<MatrixXd>>(x);
  VectorXd y_vector = as<Map<VectorXd>>(y);
  VectorXd res = y_vector - x_matrix * beta_vector;

  return wrap(res);
}
