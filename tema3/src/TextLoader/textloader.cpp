#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

std::vector<std::string> read_file_as_word_vector(std::string file_name)
{
  std::ifstream ifs(file_name);
  std::vector<std::string> word_vector;
  std::string line;

  if (!ifs)
  {
    std::cout << "Could not open input file. \n";
    return word_vector;
  }

  while (std::getline(ifs, line))
  {
    std::istringstream linestream(line);
    std::string word;
    while (linestream >> word)
    {
      word_vector.push_back(word);
    }
  }
  return word_vector;
};