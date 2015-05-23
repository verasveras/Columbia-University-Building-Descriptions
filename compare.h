#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <string>
#include "building.h"
                                                       
using namespace cv;
using namespace std; 


// Compare two buidlings.
// north of S is T.
bool isNear(building s, building t);
bool isNorth(building s, building t);
bool isSouth(building s, building t);
bool isWest(building s, building t);
bool isEast(building s, building t);

/*
bool isNear(int s, int t);
bool isNorth(int s, int t);
bool isSouth(int s, int t);
bool isWest(int s, int t);
bool isEast(int s, int t);
*/