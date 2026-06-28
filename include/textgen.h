// Copyright 2026 Georgiy Zhbannikov

#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <deque>
#include <map>
#include <random>
#include <string>
#include <vector>

class MarkovTextGenerator {
 private:
  typedef std::deque<std::string> Prefix;
  typedef std::map<Prefix, std::vector<std::string> > StateTable;

  StateTable statetab;
  int npref;
  std::mt19937 rng;

 public:
  explicit MarkovTextGenerator(int prefixSize = 2);

  void buildFromFile(const std::string& filename);
  void buildFromText(const std::string& text);

  std::string generate(int maxWords);

  StateTable& getStateTable();
  void clear();
  void addSuffix(const Prefix& prefix, const std::string& suffix);
  std::string getRandomSuffix(const Prefix& prefix);
};

#endif // INCLUDE_TEXTGEN_H_
