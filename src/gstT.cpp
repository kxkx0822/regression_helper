/// Get result of T-test
//'
 //' This function calculates the T-statistic, standard error, p-value and statistical decisions for a T-test of a linear regression model.
 //'
 //' @param mat Numeric matrix of independent variables.
 //' @param y Numeric vector of dependent variable.
 //' @return A list containing results of T-test of the model.
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
List getT(NumericMatrix mat, NumericVector y) {
  NumericMatrix x = addColumnOfOnes(mat);
  NumericVector beta = getBetaHat(mat, y);
  VectorXd beta_vector = as<Map<VectorXd>>(beta);

  MatrixXd X = as<Map<MatrixXd>>(x);
  NumericVector res = getResidual(mat, y);
  VectorXd res_vector = as<Map<VectorXd>>(res);

  int n = x.nrow();
  int k = x.ncol();
  double df_residual = n - k;
  double sse = res_vector.transpose() * res_vector;
  double mse = sse / df_residual;

  MatrixXd XtX_inv = (X.transpose() * X).inverse();
  VectorXd se = (mse * XtX_inv.diagonal().array()).sqrt();
  VectorXd t_stat = beta_vector.array() / se.array();
  NumericVector p_values = 2 * (1 - Rcpp::pt(abs(wrap(t_stat)), df_residual));

  CharacterVector decision(p_values.length());
  for (int i = 0; i < p_values.length(); ++i) {
    if (p_values[i] < 0.05) {
      decision[i] = "sig";
    } else {
      decision[i] = "non-sig";
    }
  }

  return List::create(Named("t_stat") = wrap(t_stat), Named("se") = wrap(se), Named("p-values") = wrap(p_values), Named("Decisions") = decision);
}
