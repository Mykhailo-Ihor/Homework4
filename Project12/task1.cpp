#include "task1.h"

double scalarProduct(const std::vector<double>& v1, const std::vector<double>& v2)
{
    if (v1.size() != v2.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    double result = 0.0;
    for (size_t i = 0; i < v1.size(); i++) {
        result += v1[i] * v2[i];
    }

    return result;
}

vector<double> multiplyVectorByMatrix(const vector<double>& v, const vector<vector<double>>& m)
{
    if (v.size() != m.size()) {
		throw std::invalid_argument("Vector size must be equal to the number of rows in the matrix");
	}

	vector<double> result(m[0].size(), 0.0);
    for (size_t i = 0; i < m.size(); i++) {
        for (size_t j = 0; j < m[i].size(); j++) {
			result[j] += v[i] * m[i][j];
		}
	}

	return result;
}