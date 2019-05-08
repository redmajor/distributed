#ifndef CONFIG_H_
#define CONFIG_H_

#include "utils.h"

constexpr int BENCH_SIZE = 1000; //upper limit on maximum block size when in benchmark mode

constexpr char SRC_PATH[] = "/home/rafael/mestrado/bigann"; //folder where the bigann database is stored
constexpr char INDEX_ROOT[] = "index"; //folder where the indexed databases are stored
constexpr int BENCH_REPEATS = 3; //number of times that a certain number of queries will be executed while in benchmark mode

constexpr double SLOW_RATE_MULT = 0.1;
constexpr double AVERAGE_RATE_MULT = 0.5;
constexpr double FAST_RATE_MULT = 1;

enum class RequestDistribution {Constant_Slow, Constant_Average, Constant_Fast, Variable_Poisson};

struct Config {
	//database config
	int d = 128; //vector dimension
	int nb = 500000000; //database size
	int ncentroids = 8192; //number of centroids
	int m = 8; //vector size after compression, in bytes
	int nq = 10000; //total number of distinct queries
	
	//runtime config
	int k = 10;
	int nprobe = 16;
	int block_size = 5;
	int test_length = 100000; //how many queries will be sent in total
	int eval_length = 30000; //of the sent queries, how many will be used to compute the average response time
	
	//mode specific config
	RequestDistribution request_distribution;
	int processing_size;
	bool only_min;
};

#endif 
