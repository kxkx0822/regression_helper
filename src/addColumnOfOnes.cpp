/// Add one col to input mat
//'
 //' This function add one column of ones to input matrix mat of a linear regression model.
 //'
 //' @param mat Numeric matrix of independent variables.
 //' @return Numeric matrix of standard format of linear regression.
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
