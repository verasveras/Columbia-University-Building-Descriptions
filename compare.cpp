#include "compare.h"

// compare two buildings.

// north of S is T.
// T is north of S.
bool isNear(building s, building t){

	int roiCOMx = s.xCOM;
	int roiCOMy = s.yCOM;
	int sHeight = s.bottomRight.y - s.upperLeft.y;
	int sWidth = s.bottomRight.x - s.upperLeft.x;

	int upperLeftROIx = roiCOMx - sWidth;
	int upperLeftROIy = roiCOMy - sHeight;
	int bottomRightROIx = roiCOMx + sWidth;
	int bottomRightROIy = roiCOMy + sHeight;

	if (t.bottomRight.y < bottomRightROIy && t.bottomRight.y > upperLeftROIy){
		if (t.bottomRight.x < bottomRightROIx && t.bottomRight.x <upperLeftROIx)
			return true;

		if (t.upperLeft.x < bottomRightROIx && t.upperLeft.x <upperLeftROIx)
			return true;
	}

	else if (t.upperLeft.y < bottomRightROIy && t.upperLeft.y > upperLeftROIy){
		if (t.bottomRight.x < bottomRightROIx && t.bottomRight.x <upperLeftROIx)
			return true;

		if (t.upperLeft.x < bottomRightROIx && t.upperLeft.x <upperLeftROIx)
			return true;
	}

	else 
		return false;
}
bool isNorth(building s, building t){

	int targetBottom = t.bottomRight.y;
	int sourceTop = s.upperLeft.y;

	if (targetBottom < sourceTop)
		return true; // Target is north of Source.
	else 
		return false; // Source is south of Target.
}
bool isSouth(building s, building t){

	int targetTop = t.upperLeft.y;
	int sourceBottom = s.bottomRight.y;

	if (targetTop > sourceBottom)
		return true; // Target is south of Source.
	else 
		return false; // Source is north of Target.

}
bool isEast(building s, building t){

	int sourceRight = s.bottomRight.x;
	int targetLeft = t.upperLeft.x;

	if (targetLeft > sourceRight)
		return true; // Target is East of Source.
	else
		return false; // Target is not east of source.

}
bool isWest(building s, building t){

	int sourceLeft = s.upperLeft.x;
	int targetRight = t.bottomRight.x;

	if (targetRight < sourceLeft)
		return true; // Target is West of Source;
	else
		return false;
}