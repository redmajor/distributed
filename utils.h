#ifndef UTILS_H_
#define UTILS_H_

#include <cstdio>
#include <vector>

#include "config.h"

//#define DEBUG

#ifdef DEBUG
	#define deb(...) do {std::printf("%lf) ", now()); std::printf(__VA_ARGS__); std::printf("\n");} while(0)
#else
	#define deb(...) ;
#endif

enum class ProcType {Static, Dynamic, Bench};

constexpr int AGGREGATOR = 0;
constexpr int GENERATOR = 1;

double now();
int *ivecs_read(const char *fname, int *d_out, int *n_out);
float *fvecs_read (const char *fname, int *d_out, int *n_out);
double poisson_interval(double mean_interval);
std::pair<int, int> longest_contiguous_region(double tolerance, std::vector<double>& time_per_block);
bool file_exists(char* name);

#endif /* UTILS_H_ */
