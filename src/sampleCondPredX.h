#ifndef sampleCondPredX_h
#define sampleCondPredX_h
#include <RcppArmadillo.h>
#include <Rcpp.h>
#include "sampleYlatentProbit.h"
#include "sampleYlatentPoisson.h"

arma::cube sampleCondPredX(arma::mat& Y,
					 arma::mat& X,
					 arma::cube& paramX,
					 arma::mat residVar,
					 int nsite,
					 double nsp,
					 int niter,
					 int nsample,
				 	 std::string family);
#endif