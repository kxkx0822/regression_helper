### Get result of T-test
#'
#' This function calculates the T-statistic, standard error, p-value and statistical decisions for a T-test of a linear regression model.
#'
#' @param mat Numeric matrix of independent variables.
#' @param y Numeric vector of dependent variable.
#' @return A list containing results of T-test of the model.
#' @export
#' @useDynLib regressionhelper, .registration=TRUE
#' @import Rcpp
#' @import RcppEigen
RcppgetT <- function(mat, y) {
  tstat <- getT(mat, y)
  tstat
}
