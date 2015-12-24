#include <iostream>
#include <stdlib.h>
#include <utility>

struct point {float cmax; float mem;};

point sabo (float alpha, int M, float delta, float rho1, float rho2) {
  point p;
  p.cmax = (1+delta)*alpha*alpha*rho1;
  p.mem = (1+1./delta)*rho2;
  return p;
}

point abo (float alpha, int M, float delta, float rho1, float rho2) {
  point p;
  p.cmax = 2-1./M+delta*alpha*alpha*rho1;
  p.mem = (1+M/delta)*rho2;
  return p;
}

point hypo3 (float alpha, int M, float delta, float rho1, float rho2, int k) {
  point p;
  p.cmax = k+1+delta*alpha*alpha*rho1;
  p.mem = (1+M/(k*delta))*rho2;
  return p;
}


int main (int argc, char* argv[]) {

  if (argc != 6) {
    std::cerr<<"usage: "<<argv[0]<<" model M alpha rho1 rho2"<<std::endl;
    return -1;
  }
  
  int model = atoi(argv[1]);
  int M = atoi(argv[2]);
  float alpha = atof(argv[3]);
  float rho1 = atof(argv[4]);
  float rho2 = atof(argv[5]);
  
  if (model == 1) {
    for (float delta=0.001; delta < 100; delta *= 1.1) {
      point p = sabo(alpha, M, delta, rho1, rho2);
      std::cout<<p.cmax<<" "<<p.mem<<std::endl;
    }
  }
  if (model == 2) {
    for (float delta=0.001; delta < 100; delta *= 1.1) {
      point p = abo(alpha, M, delta, rho1, rho2);
      std::cout<<p.cmax<<" "<<p.mem<<std::endl;
    }
  }  

  if (model == 3) {
    for (float delta=0.001; delta < 100; delta *= 1.1) {
      for (int k = 1; k < M; k++) {
	point p = hypo3(alpha, M, delta, rho1, rho2, k);
	std::cout<<p.cmax<<" "<<p.mem<<std::endl;
      }
    }
  }  

  
  return 0;
}
