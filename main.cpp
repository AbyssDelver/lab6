#include "statistics.hpp"
#include <random>
#include <iostream> 

int main(){
    const int N = 100;
    pf::Sample data{};
    std::random_device r;
    std::default_random_engine eng(r());
    std::normal_distribution<double> dist;
    for(int i = 0; i < N; ++i){
        data.add(dist(eng));
    }
    const auto statistics{data.statistics()};
    std::cout << "- mean: " << statistics.mean << "\n" << "- sigma: " << statistics.sigma << "\n";
}