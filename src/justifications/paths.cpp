// Needed inclusions for now
#include <string>
#include <vector>
#include <cmath>
// Namespace to keep things organized
namespace paths{
    std::vector<std::vector<double>> CoeffMatrix(std::vector<std::pair<double, double>> SplineInterpolPts){
        // Define points in pairs
        // std::vector<std::pair<double, double>> SplineInterpolPts;
        // All X points in a vector
        std::vector<double> SplineInterpolPtsX;
        for (size_t i = 0; i < SplineInterpolPts.size(); i++) {
            SplineInterpolPtsX.push_back(SplineInterpolPts[i].first);
        }
        // Number of equations
        size_t equations = SplineInterpolPts.size()-1;
        // Define chungus matrix by size? Everything is now filled with 0s
        std::vector<std::vector<double>> Matrix(4*equations, std::vector<double>(4*equations, 0));
        // Counter for taking derivative and inputting into matrix
        float deriv_counter = ((2*equations) - 2)/2;
        // Set out all xs (WORKS FOR EXAMPLE AT LEAST TEST LATER WITH ANOTHER SET?)
        for (size_t i = 0; i < equations*2; i++) {
            // Determines offset of 0s
            int k = i/2; // 4 0s every 2 lines
            size_t offset = 4*k;
            int x = (i+1)/2;
            Matrix[i][offset + 0] = std::pow(SplineInterpolPtsX[x], 3);
            Matrix[i][offset + 1] = std::pow(SplineInterpolPtsX[x], 2);
            Matrix[i][offset + 2] = SplineInterpolPtsX[x];
            Matrix[i][offset + 3] = 1;
        }
        // Take first derivative (power rule) (figure out how to make more efficent?)
        // Relationship btwn pts and 1st deriv eqs prob not right ngl... (eqs*2-2)/2 for number of rows?
        for (size_t i = 1; i <= deriv_counter; i++) {
            // Determines offset of 0s
            size_t offset = 4*(i-1);
            float row = (equations*2)+i-1;
            Matrix[row][offset + 0] = 3*std::pow(SplineInterpolPtsX[i], 2);
            Matrix[row][offset + 1] = 2*SplineInterpolPtsX[i];
            Matrix[row][offset + 2] = 1;
            // skip 3
            Matrix[row][offset + 4] = -3*std::pow(SplineInterpolPtsX[i], 2);
            Matrix[row][offset + 5] = -2*SplineInterpolPtsX[i];
            Matrix[row][offset + 6] = -1;
        }
        // Take the 2nd derivative (power rule)
        for (size_t i = 1; i <= deriv_counter; i++) {
            size_t offset = 4*(i-1);
            float row = (equations*2)+deriv_counter+i-1;
            Matrix[row][offset + 0] = 6*SplineInterpolPtsX[i];
            Matrix[row][offset + 1] = 2;
            // skip 2 and 3
            Matrix[row][offset + 4] = -6*SplineInterpolPtsX[i];
            Matrix[row][offset + 5] = -2;
        }
        // BOUNDARY CONDITION STUFF NEEDED (end behavior)
        size_t row = 4*equations - 2;
        // first boundary
        double x0 = SplineInterpolPtsX[0];
        Matrix[row][0] = 6*x0;
        Matrix[row][1] = 2;
        // 2nd boundary condition
        row++;
        double xn = SplineInterpolPtsX.back();
        size_t offset = 4*(equations-1);
        Matrix[row][offset + 0] = 6*xn;
        Matrix[row][offset + 1] = 2;   
        return Matrix;
    }
    std::vector<double> solve_matrix(std::vector<std::vector<double>> Matrix, std::vector<std::pair<double, double>> SplineInterpolPts){
        int system_size = Matrix.size();
        size_t equations = SplineInterpolPts.size()-1;
        std::vector<double> right_side(4*equations, 0);
        for (size_t i = 0; i < equations*2; i++) {
            int x = (i+1)/2;
            right_side[i] = SplineInterpolPts[x].second;
        }
        // Augment the matrix with the right hand side vector
        for (int i = 0; i < system_size; i++) {
            Matrix[i].push_back(right_side[i]);
        }
        // Gaussian elimination with partial pivoting
        for (int i = 0; i < system_size; i++) {
            // Find pivot
            int max_row = i;
            double max_val = std::abs(Matrix[i][i]);
            for (int k = i + 1; k < system_size; k++) {
                if (std::abs(Matrix[k][i]) > max_val) {
                    max_val = std::abs(Matrix[k][i]);
                    max_row = k;
                }
            }
            // Swap rows if needed
            if (max_row != i) {
                std::swap(Matrix[i], Matrix[max_row]);
            }
            // Eliminate below
            for (int k = i + 1; k < system_size; k++) {
                double factor = Matrix[k][i] / Matrix[i][i];
                for (int j = i; j <= system_size; j++) {
                    Matrix[k][j] -= factor * Matrix[i][j];
                }
            }
        }
        // Back substitution
        std::vector<double> solution(system_size);
        for (int i = system_size - 1; i >= 0; i--) {
            solution[i] = Matrix[i][system_size];
            for (int j = i + 1; j < system_size; j++) {
                solution[i] -= Matrix[i][j] * solution[j];
            }
            solution[i] /= Matrix[i][i];
        }
        return solution;
    }
}