#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <vector>
using namespace std;

vector<int> vec;

int main() {
  struct timeval start, end;
  gettimeofday(&start, NULL);
  long starttime = start.tv_sec * 1000000 + start.tv_usec;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 100000000; ++j) {
      vec.push_back(j);
    }
  }
  gettimeofday(&end, NULL);
  long endtime = end.tv_sec * 1000000 + end.tv_usec;
  float runtime = (end.tv_sec + (end.tv_usec * 1.0 / 1000000)) - (start.tv_sec + (start.tv_usec * 1.0 / 1000000));

  cout << starttime << " " << endtime << " " << runtime << endl;
  while (1) {
    vec[0];
    usleep(1000);
  }
}
