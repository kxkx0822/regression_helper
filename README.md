
# regressionhelper

<!-- badges: start -->
[![R-CMD-check](https://github.com/kxkx0822/regression_helper/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/kxkx0822/regression_helper/actions/workflows/R-CMD-check.yaml)
[![Codecov test coverage](https://codecov.io/gh/kxkx0822/regression_helper/branch/main/graph/badge.svg)](https://app.codecov.io/gh/kxkx0822/regression_helper?branch=main)
<!-- badges: end -->

The goal of regressionhelper is to generate the usually needed results of a linear regression model.

## Installation

You can install the development version of regressionhelper from [GitHub](https://github.com/) with:

``` r
# install.packages("devtools")
devtools::install_github("kxkx0822/regression_helper")
```

## Example

This is a basic example which shows you how to solve a common problem:

``` r
library(regressionhelper)
# Example 1: Getting Beta Hat
mat <- matrix(rnorm(10), ncol = 2)
y <- 2 * mat[, 1] + 3 * mat[, 2] + rnorm(50)
RcppgetBetaHat(mat, y)

# Example 2: Getting Residuals
RcppgetResidual(mat, y)

# Example 3: Getting R-squared
RcppgetRsquare(mat, y)

# Example 4: Getting F-statistic
RcppgetF(mat, y)

# Example 5: Getting T-statistics and P-values
RcppgetT(mat, y)
```

## Efficiency check

The following is a running time comparison example of function "RcppgatBetaHat" from regressionhelper and function "lm" in R base library

``` r
A tibble: 2 × 13
  expression      min   median `itr/sec` mem_alloc `gc/sec` n_itr  n_gc total_time result
  <bch:expr> <bch:tm> <bch:tm>     <dbl> <bch:byt>    <dbl> <int> <dbl>   <bch:tm> <list>
1 lm_        465.45µs 508.32µs     1956.   24.38KB     6.39   919     3    469.8ms <dbl> 
2 RcppgetBe…   4.69µs   5.44µs   174325.    4.88KB    17.4   9999     1     57.4ms <dbl> 
```

