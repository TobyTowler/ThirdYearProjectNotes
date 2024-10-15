#ifndef UTILITY_H
#define UTILITY_H

/// @brief Function for checking whether a value is equal to or between a min and max range.
/// @param val // the value to check
/// @param min  // the minimum value to check against
/// @param max  // the maximum value to check against
/// @return Return true if the value is equal to or between min and max
bool isbetween(double val, double min, double max){
  if (val <= max && val >= min)
  {
    return true;
  }
  return false;
}

#endif
