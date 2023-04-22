#include <iostream>
#include "TestHarness.h"
#include "../main/FaceDetector.h"
#include "../main/Face.h"
#include "../main/Viewer.h"


int main()
{
  // random number generator used in some tests
  srand(::time_t(NULL));

  TestResult tr;
  TestRegistry::runAllTests(tr);

  return 0;
}
