#include <cstdio>
#include <cmath>
#include <armadillo>
#include <string>

using namespace std;

/* call with g++ -std=c++11 etc */

double* solveTriDig(double a[], double b[], double c[], double f[], int N) /* A(abc)v=f */
{
    double* v = new double[N];
    for(int i=1; i<N; i++){
        b[i] -= c[i-1]*a[i-1]/b[i-1];
        f[i] -= f[i-1]*a[i-1]/b[i-1];
    }
    v[N-1] = f[N-1]/b[N-1];
    for(int i=N-2; i>=0; i--){
        v[i] = (f[i]-v[i+1]*c[i])/b[i];
    }
    return v;
}

double* solveSpecialTriDig(double f[], int N)
{
    double* v = new double[N];
    double* b = new double[N];
    b[0] = b[N-1] = 2;
    for (int i = 1; i<N; i++){
        double k = (i-1.0)/i;
        b[i] = 2-k;
        f[i] = f[i] -f[i-1]*k;
    }
    v[N-1] = f[N-1]/b[N-1];
    for (int i = N-2; i >= 0; i--){
        v[i] = (f[i]+v[i+1])/b[i];
    }
}

void arrayToFile(double a[], int N, const char * fileName){
    FILE* fil = fopen(fileName,"w");
    for(int i=0; i<N; i++){
        fprintf(fil,"%.30f\n",a[i]);
    }
    fclose(fil);
}

void solveSystemN(int N, bool special)
{
  /*int N = 1000000;*/
  double h = 1.0/(N+1);
  double *a,*b,*c,*f,*ft,*u,*v,*x;
  a  = new double[N];
  b  = new double[N];
  c  = new double[N];
  f  = new double[N];
  ft = new double[N];
  u = new double[N];
  x = new double[N];
  for(int i=0; i<N; i++){
      x[i] = h*(i+1);
      f[i] = 100*exp(-10*x[i]);
      u[i] = 1 - (1-exp(-10))*x[i] - exp(-10*x[i]);
      ft[i] = f[i]*h*h;
      a[i] = c[i] = -1;
      b[i] = 2;
  }

  std::string filePrefix;

  if (special){
    v = solveSpecialTriDig(ft,N);
    filePrefix = std::string("special_") + std::to_string(N);
  } else {
    v = solveTriDig(a,b,c,ft,N);
    filePrefix = std::string("general_") + std::to_string(N);
  }

  double diff = 0;
  for(int i = 0; i<N;i++){
      /*printf("%.30f\n",fabs((v[i]-u[i])/u[i]));*/
      if(fabs((v[i]-u[i])/u[i])>diff){
          diff = fabs((v[i]-u[i])/u[i]);
      }
  }

  arrayToFile(x,N,(filePrefix + "_x.txt").c_str());
  arrayToFile(v,N,(filePrefix + "_v.txt").c_str());
  arrayToFile(u,N,(filePrefix + "_u.txt").c_str());
  printf("%.30f\n",diff);

  delete[] a;
  delete[] b;
  delete[] c;
  delete[] f;
  delete[] ft;
  delete[] u;
  delete[] v;
  delete[] x;
}

int main()
{
  solveSystemN(10, false);
  solveSystemN(100, false);
  solveSystemN(1000, false);
}
