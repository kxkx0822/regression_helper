library("Rcpp")
library("RcppEigen")
sourceCpp("src/linearRegression.cpp")

mat = matrix(c(4, 4.5, 5, 5.5, 6, 6.5, 7), nrow = 7)
vec = c(1:9)
y = c(33, 42, 45, 51, 53, 61, 62)

mat_new = addColumnOfOnes(mat)
betahat = getBetaHat(mat, y)
res = getResidual(mat, y)
print(betahat)
print(res)
