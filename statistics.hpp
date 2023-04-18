#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include <vector>
#include <random>

namespace pf {
  struct Statistics {
    double mean{};
    double sigma{};
    double mean_err{};
    double median{};
  };

  class Sample {
    std::vector<double> entries_;

   public:
    int size() const { return entries_.size(); }

    auto& entries() { return entries_; }
    const auto& entries() const { return entries_; }

    void add(double);    
    bool remove(double);
    void push_back(std::default_random_engine eng, int n);
    
    Statistics statistics() const;

    Sample& operator+=(const Sample&);

  };

  Sample operator+(const Sample&, const Sample&);
}

#endif

