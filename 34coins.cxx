#include "34coins.hpp"

#include <fstream>
#include <vector>
#include <string>

using std::cout;

std::string saveFile = "/.config/unity3d/noio/Kingdom/storage_v34_AUTO.dat";

std::string findCoins(const std::string &input) {
  auto sc = input.find(':', input.find("coins", input.find("lostCrown")));
  auto ec = input.find('}', input.find("coins", input.find("lostCrown"))) - sc;

  return input.substr(sc + 1, ec - 1);
}

std::string setCoins(std::string &input, const std::string fill) {
  auto sc = input.find(':', input.find("coins", input.find("lostCrown")));
  auto ec = input.find('}', input.find("coins", input.find("lostCrown"))) - sc;

  return input.replace(sc + 1, ec - 1, fill);
}

int getCoins() {
  std::ifstream infile(saveFile);
  std::string line;

  if (!infile.good()) {
    throw std::string("SaveFile does not exist: " + std::string(saveFile));
  }

  while (std::getline(infile, line)) {
    std::string coins = findCoins(line);
    if (coins.size() > 0) {
      infile.close();
      return std::stoi(coins);
    }
  }

  infile.close();
  throw std::string("Incompatible file format");
}

void add34Coins(bool fill) {
  std::ifstream input_file(saveFile);
  std::vector<std::string> lines;
  std::string input;

  while (std::getline(input_file, input)) {
    if (findCoins(input).size() > 0) {
      if (fill) {
        input = setCoins(input, "34");
      } else {
        input = setCoins(input, "0");
      }
    }

    lines.push_back(input);
  }

  input_file.close();

  std::ofstream output_file(saveFile);

  for (auto line: lines) {
    output_file << line << "\n";
  }

  output_file.close();
}


int main() {
  int coins = 0;
  saveFile = std::getenv("HOME") + saveFile;

  try {
    coins = getCoins();
  } catch (std::string e) {
    cout << e << "\n";
    return -1;
  }

  try {
    std::unique_ptr<MainWindow> win(new MainWindow());
    if (coins > 0) {
      win->walletIsFull = true;
    }
    win->start();
  } catch (std::string e) {
    cout << e << "\n";
    return -1;
  }

  return 0;
}
