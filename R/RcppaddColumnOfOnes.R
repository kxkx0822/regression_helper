### Add one col to input mat
#'
#' This function add one column of ones to input matrix mat of a linear regression model.
#'
#' @param mat Numeric matrix of independent variables.
#' @return Numeric matrix of standard format of linear regression.
#' @export
#' @useDynLib regressionhelper, .registration=TRUE
#' @import Rcpp
#' @import RcppEigen
RcppaddColumnOfOnes <- function(mat) {
  x <- addColumnOfOnes(mat)
  x
}
