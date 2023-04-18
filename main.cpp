#include "statistics.hpp"
#include <random>
#include <iostream> 
#include <fstream>

int main(){
    pf::Sample data{};
    //std::random_device r;
    //std::default_random_engine eng(r());

    std::ifstream in_file("data.txt");
    std::ofstream out_file{"./results.txt"};
    double x;
    while (in_file >>  x){
        data.add(x);
    }

    std::normal_distribution<double> dist;
    const auto statistics{data.statistics()};
    out_file << "- mean: " << statistics.mean << "\n" << "- sigma: " << statistics.sigma << "\n";
}