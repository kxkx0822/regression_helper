/// Get result of F-test
//'
 //' This function calculates the F-statistic and p-value for a F-test of a linear regression model.
 //'
 //' @param mat Numeric matrix of independent variables.
 //' @param y Numeric vector of dependent variable.
 //' @return A list containing results of F-test of the model.
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
List getF(NumericMatrix mat, NumericVector y){
  NumericMatrix x = addColumnOfOnes(mat);
  VectorXd Y = as<Map<VectorXd>>(y);

  NumericVector beta = getBetaHat(mat, y);
  VectorXd beta_vector = as<Map<VectorXd>>(beta);
  NumericVector res = getResidual(mat, y);
  VectorXd res_vector = as<Map<VectorXd>>(res);
  double ybar = Y.mean();
  VectorXd ybar_vector = VectorXd::Ones(Y.size()) * ybar;

  int n = x.nrow();
  int k = x.ncol();
  double df_model = k - 1;
  double df_residual = n - k;

  double sse = res_vector.transpose() * res_vector;
  double mse = sse / df_residual;
  double sst = (Y - ybar_vector).transpose() * (Y - ybar_vector);
  double ssr = sst - sse;
  double f_stat = (ssr / df_model) / mse;
  double p_value = R::pf(f_stat, df_model, df_residual, false, false);

  return List::create(Named("F_Statistic") = f_stat, Named("P_Value") = p_value);
}
