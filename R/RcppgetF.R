### Get result of F-test
#'
#' This function calculates the F-statistic and p-value for a F-test of a linear regression model.
#'
#' @param mat Numeric matrix of independent variables.
#' @param y Numeric vector of dependent variable.
#' @return A list containing results of F-test of the model.
#' @export
#' @useDynLib regressionhelper, .registration=TRUE
#' @import Rcpp
#' @import RcppEigen
RcppgetF <- function(mat, y) {
  Fstat <- getF(mat, y)
  Fstat
}

