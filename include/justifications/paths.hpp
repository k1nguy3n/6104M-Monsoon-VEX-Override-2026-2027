#ifndef _PATHS_HPP_
#define _PATHS_HPP_

//inclusions
#include "api.h"
#include "lemlib/api.hpp"

namespace paths{
    std::vector<std::vector<double>> CoeffMatrix(std::vector<std::pair<double, double>> SplineInterpolPts);
    std::vector<double> solve_matrix(std::vector<std::vector<double>> Matrix, std::vector<std::pair<double, double>> SplineInterpolPts);

    

}  

#endif