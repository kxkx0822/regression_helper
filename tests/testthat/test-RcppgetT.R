library(testthat)
test_that("My function does this", {
  set.seed(123)
  n <- 10
  mat_test = matrix(rnorm(n * 2), ncol = 2)
  y <- 2 * mat_test[, 1] + 3 * mat_test[, 2] + rnorm(n)
  lm_ = lm(y ~ mat_test)
  result = RcppgetT(mat_test, y)
  coeff = coef(summary(lm_))
  t_stat = as.numeric(coeff[, "t value"])
  se = as.numeric(coeff[, "Std. Error"])
  pvalue = as.numeric(coeff[, "Pr(>|t|)"])
  decision = ifelse(pvalue < 0.05, "sig", "non-sig")
  expected =list(t_stat = t_stat, se = se, `p-values` = pvalue, Decisions = decision)

  # Check t_stat
  expect_equal(result$t_stat, expected$t_stat, tolerance = 1e-5)

  # Check standard errors
  expect_equal(result$se, expected$se, tolerance = 1e-5)

  # Check p-values
  expect_equal(result$p_values, expected$p_values, tolerance = 1e-5)

  # Check Decisions
  expect_true(identical(as.character(result$Decisions), as.character(expected$Decisions)))
})
