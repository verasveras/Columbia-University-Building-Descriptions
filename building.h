#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <string>
                                                       
using namespace cv;
using namespace std; 

class building {

public:

	building(); // default constructor
	building(Mat image, int buildingNumber); // constructor


	// building info
	Mat buildingImage;
	string buildingName;
	int xCOM;
	int yCOM;
	Rect MBR;
	CvPoint upperLeft;
	CvPoint bottomRight;
	int area;
	vector<Point> buildingContour;
	vector<Point> MBRContour;
	vector<Point> MBRCorners;


	// bool+ean characteristics for building
	bool rectangular;
	bool square;
	bool Lshape;
	bool nsSymetrical;
	bool weSymetrical;
	bool fourCorners;
	bool bumpy;

	
	// Find basic info about building.
	Mat getOneBuilding (Mat image, int buildingNumber); // isolate the image of one building in a new binary image
	void assignName (int buildingNumber2); // assign the building name according to it's identifying numbber
	void findCOM (Mat image); // find the center of mass
	void findMBR (Mat image); // find the minimum bounding rectangle (mbr)
	void calculateArea(); // calculate area of mbr
	void makeMBRContour(); 
	void makeMBRCorners();


	// Calculate information about building shape.
	void isRectangular(); // 
	void isSquare(); // 
	void isBumpy(); // 
	void isCornered();
	void isNWSymetrical();
	void isWESymetrical();


	// Print out info on building.
	void printInfo();
	void printContour(char* filename, vector<Point> contour);

};
