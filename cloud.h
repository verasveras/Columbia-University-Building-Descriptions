#include "compare.h"

class pix {

public:
	CvPoint location;
	int NorthBuilding;
	int SouthBuilding;
	int WestBuilding;
	int EastBuilding;
	Mat image;
	vector <int> description;

	pix();
	pix(int x, int y, Mat map); // constructor
	pix(int x, int y);

	void goNorth();
	void goSouth();
	void goEast();
	void goWest();

};
