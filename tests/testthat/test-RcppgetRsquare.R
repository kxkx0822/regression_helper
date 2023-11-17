library(testthat)
test_that("My function does this", {
  set.seed(123)
  n <- 10
  mat_test = matrix(rnorm(n * 2), ncol = 2)
  y <- 2 * mat_test[, 1] + 3 * mat_test[, 2] + rnorm(n)
  lm_ = lm(y ~ mat_test)
  result = RcppgetRsquare(mat_test, y)
  expected = summary(lm_)$r.squared
  expect_equal(result, expected, tolerance = 1e-5)
})
