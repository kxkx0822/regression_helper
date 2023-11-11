#include <Rcpp.h>
#include <RcppEigen.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppEigen)]]
using Eigen::Map;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::LLT;

// [[Rcpp::export]]
NumericVector testVector(NumericVector x) {
  return x;
}

// [[Rcpp::export]]
NumericMatrix addColumnOfOnes(NumericMatrix mat){
  int rowNum = mat.nrow();
  int colNum = mat.ncol();

  NumericMatrix newMat(rowNum, colNum + 1);
  for (int row = 0; row < rowNum; ++row){
    for (int col = 0; col < colNum; ++col){
      newMat(row, col + 1) = mat(row, col);
    }
    newMat(row, 0) = 1.0;
  }
  return newMat;
}

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
