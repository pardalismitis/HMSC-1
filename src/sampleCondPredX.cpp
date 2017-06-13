#include <RcppArmadillo.h>
#include <Rcpp.h>
#include "sampleCondPredX.h"

using namespace arma;
using namespace Rcpp;

// Calculates a prediction conditional on a subset of species.
//[[Rcpp::export]]
arma::cube sampleCondPredX(arma::mat& Y,
					 arma::mat& X,
					 arma::cube& paramX,
					 arma::mat residVar,
					 int nsite,
					 double nsp,
					 int niter,
					 int nsample,
				 	 std::string family) {

	// Define objects to store results
	mat YlatentSample(nsite, nsp);
	cube Ylatent(nsite,nsp,niter);

	mat EstModel(nsite, nsp);

	mat residVarT = trans(residVar);

	for(int i = 0; i < niter ; i++){
		EstModel = X * trans(paramX.slice(i));

		for (int j = 0; j < nsample; j++) {
			if(family == "probit"){
				uvec Y0Loc = find(Y==0);
				uvec Y1Loc = find(Y==1);
				uvec YNALoc = find_nonfinite(Y);

				mat YlatentIni = zeros(nsite,nsp);

				YlatentSample = sampleYlatentProbit(Y0Loc, Y1Loc, YNALoc, YlatentIni, EstModel, residVarT.col(i), nsp, nsite);
			}

			if(family == "gaussian"){
				mat repResidVar(nsite,nsp);
				repResidVar = repmat(residVarT.col(i),nsite,1);
				YlatentSample = randn(nsite,nsp)%repResidVar+EstModel;
			}

			if(family == "poisson" | family == "overPoisson"){
				mat YlatentIni = zeros(nsite,nsp);

				YlatentSample = sampleYlatentPoisson(Y, YlatentIni, EstModel, residVarT.col(i), nsp, nsite);
			}
		}
		// Store in final object
		Ylatent.slice(i) = YlatentSample;
	}
	// return result object
	return Ylatent;
}