/// Get R^2
//'
 //' This function calculates the Rsquare (coefficient of determination) of a linear regression model.
 //'
 //' @param mat Numeric matrix of independent variables.
 //' @param y Numeric vector of dependent variable.
 //' @return A double number representing the R^2 of the model.
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
double getRsquare(NumericMatrix mat, NumericVector y){
  NumericMatrix x = addColumnOfOnes(mat);

  VectorXd Y = as<Map<VectorXd>>(y);
  MatrixXd X = as<Map<MatrixXd>>(x);
  NumericVector beta = getBetaHat(mat, y);
  VectorXd beta_vector = as<Map<VectorXd>>(beta);
  NumericVector res = getResidual(mat, y);
  VectorXd res_vector = as<Map<VectorXd>>(res);

  VectorXd yhat = X * beta_vector;
  double ybar = Y.mean();
  VectorXd ybar_vector = VectorXd::Ones(Y.size()) * ybar;
  double sse = res_vector.transpose() * res_vector;
  double sst = (Y - ybar_vector).transpose() * (Y - ybar_vector);
  // double sst = (Y.array() - ybar).square().sum();
  if (sst < 1e-10) {
    return 0.0;
  }
  return 1.0 - (sse / sst);
}
