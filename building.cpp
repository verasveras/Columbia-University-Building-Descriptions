#include "building.h"
#include <fstream>

// Constructor
building::building(Mat image, int buildingNumber){
	buildingImage = getOneBuilding(image, buildingNumber);
	// buildingName = assignName(buildingNumber);
	buildingName;
	assignName(buildingNumber);
	findCOM(buildingImage);
	findMBR(buildingImage);
	calculateArea();
	makeMBRContour();
	makeMBRCorners();

	// printContour("C:\\Users\\Lisa\\Desktop\\MBRContour2.txt", MBRContour);
	// printContour("C:\\Users\\Lisa\\Desktop\\BuildingContour.txt", buildingContour);
	// printContour("C:\\Users\\Lisa\\Desktop\\MBRCorners.txt", MBRCorners);

	isSquare();
	isRectangular();
	isBumpy();
	isCornered();
	isNWSymetrical();
	isWESymetrical();

	printInfo();
}


// basic building properties
void building::assignName (int buildingNumber2){
	 
	if (buildingNumber2 == 1)
		 buildingName = "Pupin";

    else if (buildingNumber2 == 2)
		buildingName = "Schapiro CEPSRN";

	else if (buildingNumber2 == 3)
		buildingName = "Mudd, Engineering Terrace, Fairchild & Computer Science";
    
	else if (buildingNumber2 == 4)
		buildingName = "Physical Fitness Center";

    else if (buildingNumber2 == 5)
		buildingName = "Gymnasium & Uris";

	else if (buildingNumber2 == 6)
		buildingName = "Schermerhorn";

    else if (buildingNumber2 == 7)
		buildingName = "Chandler & Havemeyer";
	
	else if (buildingNumber2 == 8)
		buildingName = "Computer Center";

    else if (buildingNumber2 == 9)
		buildingName = "Avery";

	else if (buildingNumber2 == 10)
		buildingName = "Fayerweather";

	else if (buildingNumber2 == 11)
		buildingName = "Mathematics";
	
	else if (buildingNumber2 == 12)
		buildingName = "Low Library";

	else if (buildingNumber2 == 13)
		buildingName = "St. Paul's Chapel";

	else if (buildingNumber2 == 14)
		buildingName = "Earl Hall";

	else if (buildingNumber2 == 15)
		buildingName = "Lewisohn";

	else if (buildingNumber2 == 16)
		buildingName = "Philosophy";

	else if (buildingNumber2 == 17)
		buildingName = "Buell & Maison Francaise";

	else if (buildingNumber2 == 18)
		buildingName = "Alma Mater";

	else if (buildingNumber2 == 19)
		buildingName = "Dodge";

	else if (buildingNumber2 == 20)
		buildingName = "Kent";

	else if (buildingNumber2 == 21)
		buildingName = "College Walk";

	else if (buildingNumber2 == 22)
		buildingName = "Journalism & Furnald";
	
	else if (buildingNumber2 == 23)
		buildingName = "Hamilton, Hartley, Wallach & John Jay";

	else if (buildingNumber2 == 24)
		buildingName = "Lion's Court";
	
	else if (buildingNumber2 == 25)
		buildingName = "Lerner Hall";
	
	else if (buildingNumber2 == 26)
		buildingName = "Butler Library";

	else if (buildingNumber2 == 27)
		buildingName = "Carman";

	else
		buildingName = "Unknown";
}
Mat building::getOneBuilding (Mat image, int buildingNumber){


	Mat building = image.clone();
	// cvtColor(building, building, CV_RGB2GRAY);
	// namedWindow("one", CV_WINDOW_AUTOSIZE);
    // imshow("one", building);

	int width = image.cols;
	int height = image.rows;

	Scalar pixel;

	for (int i = 1; i < width; i++){
		for (int j = 1; j < height; j++){
			pixel = image.at<uchar>(j, i);
			if (pixel.val[0] == buildingNumber) {
				// printf("X:%d, Y:%d, Pixel: %d \n", i, j, pixel);
				building.at<uchar>(j, i) = 255;
			}
		}
	}

	threshold(building, building, 100, 255, CV_THRESH_BINARY);
	// char Number[5];
	// imshow(itoa(buildingNumber), building);
	return building;
}
void building::findCOM(Mat image){

	Mat im_binary = image.clone();
	// imshow("binary", im_binary);

    int Xsum = 0;
    int Ysum = 0;
    int width = im_binary.cols;
    int height = im_binary.rows;
    double total = 0;
    Scalar pixel;


	for (int i = 1; i < width; i++){
        for (int j = 1; j < height; j++){
            pixel = im_binary.at<uchar>(j, i);

            if (pixel.val[0] > 0) {
				// printf("%d\n", pixel.val[0]);
                Xsum += i;
                Ysum += j;
                total += 1;
            }
        }
    } 

	double Xcoord = Xsum/total;
    double Ycoord = Ysum/total;
	xCOM = (int) Xcoord;
	yCOM = (int) Ycoord;

	// printf("X: %d, Y: %d \n", xCOM, yCOM); 
	// imshow("wow", im_binary);

}
void building::findMBR(Mat image){
	
  Mat src_gray = image.clone();
  int thresh = 100;
  int max_thresh = 255;
  RNG rng(12345);

  /* Code from OPENCV example */
  Mat threshold_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  // Detect edges using Threshold
  threshold( src_gray, threshold_output, thresh, 255, THRESH_BINARY );
  
  // Find contours
  findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

  /// Approximate contours to polygons + get bounding rects and circles
  vector<vector<Point> > contours_poly( contours.size() );
  vector<Rect> boundRect( contours.size() );

  // FILE * wow2 = fopen("C:\\Users\\Lisa\\Desktop\\wow2.txt", "w");
  for (int i = 0; i < contours.size(); i++) { 
	   // fprintf(wow2, "%d\n", i);
	   approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
       MBR = boundRect[i] = boundingRect( Mat(contours_poly[i]) );
	   // fprintf(wow2, "Top Left: %d, %d \n", boundRect[i].tl().x , boundRect[i].tl().y);
	   // fprintf(wow2, "Bottom Right: %d, %d \n", boundRect[i].br().x, boundRect[i].br().y);
     }

  upperLeft = MBR.tl();
  bottomRight = MBR.br();
  buildingContour = contours_poly[0];

  // fclose (wow2);
  // Draw polygonal contour + bonding rects + circles
  /* Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );

  for (int i = 0; i< contours.size(); i++) {

	   Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );

	   if (i == 0)
	        // color = Scalar(0, 0, 255);
	   if  (i == 1)
		    color = Scalar(255, 0, 0);

       drawContours( drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
       rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 1, 8, 0 );
     }

  // Show in a window
  namedWindow( "MBR", CV_WINDOW_AUTOSIZE );
  imshow( "MBR", drawing ); */

}
void building::calculateArea(){

	int height = upperLeft.y - bottomRight.y;
	int width = bottomRight.x - upperLeft.x;
	area = height * width * (-1);
	// printf("%d", area);
}
void building::makeMBRContour(){

	Point pixel;
	// x 
	for (int i = upperLeft.x; i < bottomRight.x; i++) {
		// y
		for (int j = upperLeft.y; j < bottomRight.y; j++){
			pixel = Point(i,j);
			MBRContour.push_back(pixel);
		}
	}


    /* FILE *contFile = fopen("C:\\Users\\Lisa\\Desktop\\MBRcontour.txt", "w");
	for (int z = 0; z < MBRContour.size(); z++){
		fprintf(contFile, "X: %d, Y: %d\n", MBRContour[z].x, MBRContour[z].y); 
	}
	fclose(contFile); */

	// draw the contour to make sure it's good
	// RNG rng(12345);
	// Scalar color = Scalar (0, 0, 255);

	// vector <vector <Point>> contoursDraw;
	// contoursDraw.push_back(MBRContour);
    // drawContours(buildingImage, contoursDraw, 0, color, 5, 8);  
	// imshow("MDB CALC", buildingImage);

}
void building::makeMBRCorners(){

	int upperLeftX = upperLeft.x;
	int upperLeftY = upperLeft.y;
	 
	int bottomLeftX = upperLeft.x;
	int bottomLeftY = bottomRight.y;

	int upperRightX = bottomRight.x;
	int upperRightY = upperLeft.y;

	int bottomRightX = bottomRight.x;
	int bottomRightY = bottomRight.y;

	MBRCorners.push_back(Point(upperLeftX, upperLeftY));
	MBRCorners.push_back(Point(bottomLeftX, bottomLeftY));
	MBRCorners.push_back(Point(upperRightX, upperRightY));
	MBRCorners.push_back(Point(bottomRightX, bottomRightY));
	
}


// shape calculations
void building::isRectangular(){
	
   // int width = bottomRight.x - upperLeft.x;
   // int height = bottomRight.y - upperLeft.y;
   if (square == true)
	   rectangular = false;
   else
	   rectangular = true;

}
void building::isSquare(){

	int width = bottomRight.x - upperLeft.x;
	int height = bottomRight.y - upperLeft.y;
	
	if (width == height) {
		square = true;
	}

	else if (height <= (width)*1.1 && height > width){
		square = true;
	}

	else if (width <= (height)*1.1 && width > height) { 
		square = true;
	}

	else {
		square = false;
	}
	  
}
void building::isCornered(){

	int cornerCount = 0;

	for (int i = 0; i < MBRCorners.size(); i++){
		
		for (int j = 0; j < buildingContour.size(); j++){
			if (MBRCorners[i] == buildingContour[j]){
				cornerCount = 4;
				break;
			}
		}
	}

	if (cornerCount < 4)
	    fourCorners = false;
	else
		fourCorners = true;
}
void building::isBumpy(){

	int pointNumber = buildingContour.size();

	if (pointNumber > 4)
		bumpy = true;
	else 
		bumpy = false;

}
void building::isNWSymetrical(){

	int heightMid = (int) ((upperLeft.y + bottomRight.y) / 2);
	// int widthMid = (int) ((upperLeft.x + bottomRight.x) / 2);

	int top = 0;
	int bottom = 0;

	for (int z = 0; z < buildingContour.size(); z++) {
		if (buildingContour[z].y > heightMid){
			top++;
		}

		if (buildingContour[z].y < heightMid){
			bottom++;
		}
	}

	if (top == bottom)
		nsSymetrical = true;
	else 
		nsSymetrical = false;
}
void building::isWESymetrical(){

	// int heightMid = (int) ((upperLeft.y + bottomRight.y) / 2);
	int widthMid = (int) ((upperLeft.x + bottomRight.x) / 2);

	int left = 0;
	int right = 0;

	for (int z = 0; z < buildingContour.size(); z++) {
		if (buildingContour[z].x > widthMid){
			right++;
		}

		if (buildingContour[z].x < widthMid){
			left++;
		}
	}

	if (right == left)
		weSymetrical = true;
	else 
		weSymetrical = false;
}


// print
void building::printInfo(){

	
	FILE *out = fopen("C:\\Users\\Lisa\\Desktop\\buildingDescriptions.txt", "a");

	fprintf(out, "%s", buildingName.c_str());
	fprintf(out, " has a center of mass at %d, %d\n", xCOM, yCOM);
	fprintf(out, "The upper-left corner of the MBR is at %d, %d.\n", upperLeft.x, upperLeft.y);
	fprintf(out, "The lower-right corner of the MBR is at %d, %d.\n", bottomRight.x, bottomRight.y); 
	fprintf(out, "The area of the MBR is %d.\n", area);

	if (square == true)
		fprintf(out, "Is square. \n");

	if (rectangular == true)
		fprintf(out, "Is rectangular. \n");

	if (bumpy == true)
		fprintf(out, "Is bumpy. \n");

	if (fourCorners == true)
		fprintf(out, "It has four corners.\n");
	else 
		fprintf(out, "It does not have four corners.\n");

	if (nsSymetrical == true)
		fprintf(out, "Is symetrical north/south.\n");
	else 
		fprintf(out, "Is not symetrical north/south.\n");


	if (weSymetrical == true)
		fprintf(out, "Is symetrical west/east.\n");
	else 
		fprintf(out, "Is not symetrical west/east.\n");

    fprintf(out, "\n\n\n");

	fclose(out);

}
void building::printContour(char * filename, vector<Point> contour){

	FILE *contourFile = fopen(filename, "w");
	for (int z = 0; z < contour.size(); z++){ 
		Point p = contour[z];
		fprintf(contourFile, "%d, %d\n", p.x, p.y);
	}
	fclose(contourFile);
}
