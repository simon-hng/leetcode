#include "../include/bits/stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  std::vector<std::string> numToText = {"one", "two",   "three", "four", "five",
                                        "six", "seven", "eight", "nine"};

  if (1 <= n && n <= 9) {
    std::cout << numToText[n - 1] << std::endl;
  } else {
    std::cout << "Greater than 9" << std::endl;
  }
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
