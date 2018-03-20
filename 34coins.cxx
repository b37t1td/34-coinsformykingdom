#include "34coins.hpp"

using std::cout;

int main() {
  try {
    std::unique_ptr<MainWindow> win(new MainWindow());
    win->start();
  } catch (const char *e) {
    cout << e << "\n";
    return -1;
  }

  return 0;
}
