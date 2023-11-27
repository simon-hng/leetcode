/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			          1 if num is lower than the picked number
 *                  otherwise return 0
 */
int guess(int num);

class Solution {
 public:
  int guessNumber(int n) { return guessNumber(1, n); };

  int guessNumber(const int lower, const int upper) {
    int mid = lower + (upper - lower) / 2;

    switch (guess(mid)) {
      case 0:
        return mid;
      case -1:
        return guessNumber(lower, mid);
      case 1:
        return guessNumber(mid + 1, upper);
    };

    // should not happen
    return 0;
  }
};
