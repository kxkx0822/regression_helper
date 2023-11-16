### Estimate Beta Hat
#'
#' This function estimates the coefficients (Beta Hat) of a linear regression model.
#'
#' @param mat Numeric matrix of independent variables.
#' @param y Numeric vector of dependent variable.
#' @return Numeric vector representing the estimated coefficients.
#' @export
#' @useDynLib regressionhelper, .registration=TRUE
#' @import Rcpp
#' @import RcppEigen
RcppgetBetaHat <- function(mat, y) {
  betahat <- getBetaHat(mat, y)
  betahat
}
