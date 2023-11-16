### Get residual
#'
#' This function calculates the residuals(Y-Yhat) of a linear regression model.
#'
#' @param mat Numeric matrix of independent variables.
#' @param y Numeric vector of dependent variable.
#' @return Numeric vector representing the residuals.
#' @export
#' @useDynLib regressionhelper, .registration=TRUE
#' @import Rcpp
#' @import RcppEigen
RcppgetResidual <- function(mat, y) {
  res <- getResidual(mat, y)
  res
}
