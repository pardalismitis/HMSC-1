#' Simulated data and parameters
#'
#' Simulated data and the parameters used to construct the simulated data.  These data and their associated parameters were constructed to illustrate some of the functionality of the R package.
#'
#' @docType data
#'
#' @usage 
#' data(simulEx2)
#' data(simulParamEx2)
#'
#' @format 
#' \code{simulEx2} is an object of class \code{HMSCdata} that include:
#' \itemize{
#'     \item{\code{Y}}{ A community \code{matrix}}
#'     \item{\code{X}}{ A \code{matrix} of three explanatory (environmental) variables}
#'     \item{\code{Tr}}{ A \code{matrix} of two traits}
#'     \item{\code{Phylo}}{ A \code{matrix} of phylogenic correlations among the ten species}
#'     \item{\code{Random}}{ A \code{data.frame} that includes two factors presenting a site-level random effect and a 5-level random effect}
#' }
#' \code{simulParamEx2} is an object of class \code{HMSCparam} that include:
#' \itemize{
#'     \item{\code{paramX}}{ A \code{matrix} that contains the parameters of each covariates (\code{X} in \code{simulEx2}) associated to each simulated species. }
#'     \item{\code{paramTr}}{ A \code{matrix} that contains the parameters of each traits (\code{Tr} in \code{simulEx2}) associated to each covariate(\code{X} in \code{simulEx2}). }
#'     \item{\code{varX}}{ A covariance \code{matrix}. }
#'     \item{\code{precX}}{ A precision \code{matrix}, which is the inverse of \code{varX}. Technically this matrix is redundant with \code{varX} but because it is used often in the parameter estimation, it is convenient for \code{\link{as.HMSCparam}} to construct it. }
#'     \item{\code{phylo}}{ A numeric value that defines the positive or negative importance phylogenetic correlations have on the community (\code{Y} in \code{simulEx2}). }
#'     \item{\code{latent}}{ A \code{list} that contain 2 matrices of two latent variables. }
#'     \item{\code{paramLatent}}{ A \code{list} that contain 2 matrices, which include the parameters associated to the latent variables in \code{latent}. }
#' }
#'
#' @keywords datasets
"simulEx2"