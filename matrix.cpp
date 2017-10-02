#include <cstdio>
#include <cmath>
#include <armadillo>

using namespace std;

void arrayToFile(double a[], int N, const char * fileName){
    FILE* fil = fopen(fileName,"w");
    for(int i=0; i<N; i++){
        fprintf(fil,"%.30f\n",a[i]);
    }
    fclose(fil);
}

int main() {
  int M = 3;
  int N = 10000;
  double** a = new double*[M];
  for (size_t i = 0; i < M; i++) {
    a[i] = new double[N];
  }
  a[0][0] = 10;
  printf("%s\n", M);
  for (size_t i = 0; i < M; i++) {
    delete[] a[i];
  }
}
