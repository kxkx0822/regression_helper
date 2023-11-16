### Get R^2
#'
#' This function calculates the Rsquare (coefficient of determination) of a linear regression model.
#'
#' @param mat Numeric matrix of independent variables.
#' @param y Numeric vector of dependent variable.
#' @return A scalar representing the R^2 of the model.
#' @export
#' @useDynLib regressionhelper, .registration=TRUE
#' @import Rcpp
#' @import RcppEigen
RcppgetRsquare <- function(mat, y) {
  Rsquare <- getRsquare(mat, y)
  Rsquare
}
