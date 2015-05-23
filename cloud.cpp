#include "cloud.h"

//////////////////////////////////////////////////////
// pixel
pix::pix (int x, int y, Mat map){

	location.x = x;
	location.y = y;
	image = map.clone();

	goNorth();
	goSouth();
	goWest();
	goEast();

} // constructor
pix::pix (int x, int y){

	location.x = x;
	location.y = y;

}
void pix::goNorth(){

	int x = location.x;
	int y = location.y;

	int width = image.cols;
	int height = image.rows;

	Scalar pixel;

	for (int z = y; z > 0; z--){
			pixel = image.at<uchar>(z, x);
			if (pixel.val[0] > 0) {
				NorthBuilding = pixel.val[0];
				break;
			}
	}

	description.push_back(NorthBuilding);

}
void pix::goSouth(){

	int x = location.x;
	int y = location.y;

	int width = image.cols;
	int height = image.rows;

	Scalar pixel;

	for (int z = y; z < height; z++){
			pixel = image.at<uchar>(z, x);
			if (pixel.val[0] > 0) {
				SouthBuilding = pixel.val[0];
				break;
			}
	}

	description.push_back(SouthBuilding);
}
void pix::goEast(){

	int x = location.x;
	int y = location.y;

	int width = image.cols;
	int height = image.rows;

	Scalar pixel;

	for (int z = x; z < width; z++){
			pixel = image.at<uchar>(y, z);
			if (pixel.val[0] > 0) {
				EastBuilding = pixel.val[0];
				break;
			}
	}

	description.push_back(WestBuilding);

}
void pix::goWest(){

	int x = location.x;
	int y = location.y;

	int width = image.cols;
	int height = image.rows;

	Scalar pixel;

	for (int z = x; z < width; z++){
			pixel = image.at<uchar>(y, z);
			if (pixel.val[0] > 0) {
				WestBuilding = pixel.val[0];
				break;
			}
	}

	description.push_back(EastBuilding);
}