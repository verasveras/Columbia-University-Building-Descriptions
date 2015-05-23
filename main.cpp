#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include "cloud.h"

using namespace cv;
using namespace std;


void printVector (vector <vector <int>> Relationships, char* filename) {

	FILE * output = fopen(filename, "w");

	for (int i = 0; i < Relationships.size(); i++){
		vector <int> out = Relationships[i];
		for (int j = 0; j < out.size(); j ++){
				fprintf(output, "%d ", out[j]);
		}

		fprintf(output, "\n");
	}

	fclose(output);
}
/* vector <pix> bfsCloudDraw (pix firstpixel, vector <int> matchDescription, vector <pix> visited, vector <pix> &draw) {

	bool haveSeen = false;
	for (int i = 0; i < visited.size(); i++){
		if (visited[i].location.x == firstpixel.location.x && visited[i].location.y == firstpixel.location.y){
			haveSeen = true;
			return;
		}
	}

	if (firstpixel.description == matchDescription && haveSeen == false){

		pix right = pix (firstpixel.location.x + 1, firstpixel.location.y);
	    pix left = pix (firstpixel.location.x - 1, firstpixel.location.y);
	    pix top = pix (firstpixel.location.x, firstpixel.location.y);
	    pix bottom = pix (firstpixel.location.x, firstpixel.location.y);

		bfsCloudDraw(right, matchDescription, visited, draw);
	    bfsCloudDraw(left, matchDescription, visited, draw);
	    bfsCloudDraw(top, matchDescription, visited, draw);
	    bfsCloudDraw(bottom, matchDescription, visited, draw);
	}

	return;
} */

int main() {

    string mapLocation = "C:\\Users\\Lisa\\Desktop\\ass3\\ass3-labeled.pgm";
	Mat mapImage = imread(mapLocation, CV_LOAD_IMAGE_GRAYSCALE);
	imshow("Map", mapImage);

	vector <building> allBuildings;

    building One = building(mapImage, 1);
	building Two = building(mapImage, 2);
	building Three = building(mapImage, 3);
	building Four = building(mapImage, 4);
	building Five = building(mapImage, 5);
	building Six = building(mapImage, 6);
	building Seven = building(mapImage, 7);
	building Eight = building(mapImage, 8);
	building Nine = building(mapImage, 9);
	building Ten = building(mapImage, 10);
	building Eleven = building(mapImage, 11);
	building Twelve = building(mapImage, 12);
	building Thirteen = building(mapImage, 13);
	building Fourteen = building(mapImage, 14);
	building Fifteen = building(mapImage, 15);
	building Sixteen = building(mapImage, 16);
	building Seventeen = building(mapImage, 17);
	building Eighteen = building(mapImage, 18);
	building Nineteen = building(mapImage, 19);
	building Twenty = building(mapImage, 20);
	building Twentyone = building(mapImage, 21);
	building Twentytwo = building(mapImage, 22);
	building Twentythree = building(mapImage, 23);
	building Twentyfour = building(mapImage, 24);
	building Twentyfive = building(mapImage, 25);
	building Twentysix = building(mapImage, 26);
	building Twentyseven = building(mapImage, 27);

	allBuildings.push_back(One);
	allBuildings.push_back(Two);
	allBuildings.push_back(Three);
	allBuildings.push_back(Four);
	allBuildings.push_back(Five);
	allBuildings.push_back(Six);
	allBuildings.push_back(Seven);
	allBuildings.push_back(Eight);
	allBuildings.push_back(Nine);
	allBuildings.push_back(Ten);
	allBuildings.push_back(Eleven);
	allBuildings.push_back(Twelve);
	allBuildings.push_back(Thirteen);
	allBuildings.push_back(Fourteen);
	allBuildings.push_back(Fifteen);
	allBuildings.push_back(Sixteen);
	allBuildings.push_back(Seventeen);
	allBuildings.push_back(Eighteen);
	allBuildings.push_back(Nineteen);
	allBuildings.push_back(Twenty);
	allBuildings.push_back(Twentyone);
	allBuildings.push_back(Twentytwo);
	allBuildings.push_back(Twentythree);
	allBuildings.push_back(Twentyfour);
	allBuildings.push_back(Twentyfive);
	allBuildings.push_back(Twentysix);
	allBuildings.push_back(Twentyseven);


	vector <vector <int>> North;
		for (int i = 0; i < allBuildings.size(); i++){

			vector <int> sources;
			for (int j = 0; j < allBuildings.size(); j++){
				if (isNorth (allBuildings[j], allBuildings[i]))
					sources.push_back(1);
				else 
					sources.push_back(0);
			}

			North.push_back(sources);
		}


	vector <vector <int>> South;
	    for (int i = 0; i < allBuildings.size(); i++){

			vector <int> sources;
			for (int j = 0; j < allBuildings.size(); j++){
				if (isSouth (allBuildings[j], allBuildings[i]))
					sources.push_back(1);
				else
					sources.push_back(0);
			}

			South.push_back(sources);
		}


	vector <vector <int>> West;
        for (int i = 0; i < allBuildings.size(); i++){

			vector <int> sources;
			for (int j = 0; j < allBuildings.size(); j++){
				if (isWest (allBuildings[j], allBuildings[i]))
					sources.push_back(1);
				else
					sources.push_back(0);
			}

			West.push_back(sources);
		}


	vector <vector <int>> East;
        for (int i = 0; i < allBuildings.size(); i++){

			vector <int> sources;
			for (int j = 0; j < allBuildings.size(); j++){
				if (isEast (allBuildings[j], allBuildings[i]))
					sources.push_back(1);
				else
					sources.push_back(0);
			}

			East.push_back(sources);
		}


	vector <vector <int>> Near;
        for (int i = 0; i < allBuildings.size(); i++){

			vector <int> sources;
			for (int j = 0; j < allBuildings.size(); j++){
				if (isNear (allBuildings[j], allBuildings[i]))
					sources.push_back(1);
				else
					sources.push_back(0);
			}

			Near.push_back(sources);
		}





   vector <vector <int>> North2;
       for (int i = 0; i < North.size() - 1; i++){
		   vector <int> currentBuilding = North[i];
		   vector <int> nextBuilding = North[i + 1];

		   for (int j = 0; j < currentBuilding.size(); j++){
			   if (currentBuilding[j] == 1){
			       if (nextBuilding[j] == 1){
					   if (nextBuilding[i] == 1){
						   North2[j][i] = 0;
			           }
				   }
		       }
           }
	    }


   vector <vector <int>> South2 = South;
   for (int i = 0; i < South2.size() - 1; i++){
		   vector <int> currentBuilding = South2[i];
		   vector <int> nextBuilding = South2[i + 1];

		   for (int j = 0; j < currentBuilding.size(); j++){
			   if (currentBuilding[j] == 1){
			       if (nextBuilding[j] == 1){
					   if (nextBuilding[i] == 1){
						   nextBuilding[i] = 0;
			           }
				   }
		       }
           }
   }

   vector <vector <int>> West2 = West;
   for (int i = 0; i < West2.size() - 1; i++){
		   vector <int> currentBuilding = West2[i];
		   vector <int> nextBuilding = West2[i + 1];

		   for (int j = 0; j < currentBuilding.size(); j++){
			   if (currentBuilding[j] == 1){
			       if (nextBuilding[j] == 1){
					   if (nextBuilding[i] == 1){
						   nextBuilding[i] = 0;
			           }
				   }
		       }
           }

   }

   vector <vector <int>> East2 = East;
   for (int i = 0; i < East2.size() - 1; i++){
		   vector <int> currentBuilding = East2[i];
		   vector <int> nextBuilding = East2[i + 1];

		   for (int j = 0; j < currentBuilding.size(); j++){
			   if (currentBuilding[j] == 1){
			       if (nextBuilding[j] == 1){
					   if (nextBuilding[i] == 1){
						   nextBuilding[i] = 0;
			           }
				   }
		       }
           }
   }

   vector <vector <int>> Near2 = Near;
   for (int i = 0; i < Near2.size() - 1; i++){
		   vector <int> currentBuilding = Near2[i];
		   vector <int> nextBuilding = Near2[i + 1];

		   for (int j = 0; j < currentBuilding.size(); j++){
			   if (currentBuilding[j] == 1){
			       if (nextBuilding[j] == 1){
					   if (nextBuilding[i] == 1){
						   nextBuilding[i] = 0;
			           }
				   }
		       }
           }
   }

   printVector(West, "C:\\Users\\Lisa\\Desktop\\North.txt");
   printVector(East, "C:\\Users\\Lisa\\Desktop\\North2.txt");

   // pix first(200, 200, mapImage);	
   // bfsCloudDraw(first, first.description, mapImage);

	cout << "End" << endl;
	waitKey(0);
	return 0;

}