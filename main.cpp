#include "statistics.hpp"
#include <random>
#include <iostream> 
#include <vector>
#include <iterator>

int main(){
    const int N = 10000;
    pf::Sample data{};
    std::random_device r;
    std::default_random_engine eng(r());
    std::normal_distribution<double> dist;
    data.push_back(eng, 100000);
    const auto statistics{data.statistics()};
    std::cout << "- mean: " << statistics.mean << "\n" << "- sigma: " << statistics.sigma << "\n";
}