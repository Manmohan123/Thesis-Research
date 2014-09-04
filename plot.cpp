#include <iostream>
#include <stdlib.h>
#include <utility>
struct point {float repl; float ratio; };

point model1 (float alpha, int M) {point p; p.repl = 1; p.ratio = 2*alpha*alpha*((float)M)/(2*alpha*alpha+((float)M)-1); return p;}
point model2 (float alpha, int M) {point p; p.repl = M; p.ratio = std::min(2.0,1+alpha*alpha/2.); return p;}
point model3 (float alpha, int M, int k) {
  point p;
  p.repl = ((float)M)/k;
  p.ratio = ((float)(alpha*alpha*k)/(alpha*alpha+k-1));
  p.ratio *= ( (float)(M+k-1)/(M));

  p.ratio += ((float)(M-k)/M);
  return p;
}

int main (int argc, char* argv[]) {
  int model = atoi(argv[1]);
  int M = atoi(argv[2]);
  float alpha = atof(argv[3]);
  
  if (model == 1) {
    point p = model1(alpha, M);
    std::cout<<p.repl<<" "<<p.ratio<<std::endl;
  }
  if (model == 2) {
    point p = model2(alpha, M);
    std::cout<<p.repl<<" "<<p.ratio<<std::endl;
  }  

  if (model == 3) {
    for (int k=1; k<=M; ++k) {
      if (M%k == 0) {
	point p = model3(alpha, M, k);
	std::cout<<p.repl<<" "<<p.ratio<<std::endl;      
      }
    }
  }

  return 0;
}
