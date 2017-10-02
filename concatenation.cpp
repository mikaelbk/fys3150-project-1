#include <cstdio>
#include <cmath>
#include <armadillo>
#include <string>

using namespace std;

/* g++ -std=c++11 */

int main(int argc, char const *argv[]) {
  int N = 5;
  std::string num = std::to_string(N);
  std::string hello = std::string("hello");
  std::string world = std::string("world");
  std::string greetings = hello + " " + world;
  printf((hello + " number " + num).c_str());
  return 0;
}
