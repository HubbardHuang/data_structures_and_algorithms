#ifndef RANGE_H
#define RANGE_H

template <typename T>
class Range {
public:
    T begin_;
    T end_;
    Range(T begin, T end)
      : begin_(begin)
      , end_(end) {}
};

#endif