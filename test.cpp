#include <cstdio>
#include <cmath>
#include <armadillo>
#include <string>

using namespace std;

/* g++ -std=c++11 */

int main(int argc, char const *argv[]) {
  const char* x = "test";
  const char* y = "test";
  string hello = string("hello");
  std::string world = std::string("world");
  std::string greetings = hello + " " + world;
  printf(greetings.c_str());
  return 0;
}
