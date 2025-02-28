// Copyright 2022 Gleb "belgad" Danshin
#include "../../../modules/task_1/danshin_g_integral_rectangle/integral_rectangle.hpp"

double Integrate(size_t dim, double* step, double* lower, double* upper, Function func) {
  double result = 0;
  int total = 1;
  auto size = new int[dim];
  for (size_t k = 0; k < dim; ++k) {
    total *= size[k] = static_cast<int>((upper[k] - lower[k]) / step[k]);
  }
  auto curr_point = new double[dim];
  int j;
  for (int i = 0; i < total; ++i) {
    j = i;
    for (size_t k = 0; k < dim; ++k) {
      curr_point[k] = lower[k] + static_cast<double>(j % size[k]) * step[k];
        j /= size[k];
    }
    result += func(curr_point);
  }
  delete[] size;
  delete[] curr_point;
  for (size_t k = 0; k < dim; ++k) {
    result *= step[k];
  }
  return result;
}
