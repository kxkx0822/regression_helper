library(testthat)
test_that("My function does this", {
  set.seed(123)
  n <- 10
  mat_test = matrix(rnorm(n * 2), ncol = 2)
  result = RcppaddColumnOfOnes(mat_test)
  expected = cbind(matrix(1, ncol = 1, nrow = n), mat_test)
  expect_equal(result, expected, tolerance = 1e-5)
})
