#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	//just set up the openFrameworks stuff
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(255);
		
	//initialize the variable so it's off at the beginning
}

//--------------------------------------------------------------
void testApp::update(){
	
	//don't move the points if we are using the camera	
	
	//find the new center, we need this to move our camera
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//if we're using the camera, start it.
	//everything that you draw between begin()/end() shows up from the view of the camera
    
	//do the same thing from the first example...
    glBegin(GL_TRIANGLE_STRIP);
	for(int i = 1; i < points.size(); i++){
		
		//find this point and the next point
		ofVec3f thisPoint = points[i-1];
		ofVec3f nextPoint = points[i];
		
		//get the direction from one to the next. 
		//the ribbon should fan out from this direction
		ofVec3f direction = (nextPoint - thisPoint);
		
		//get the distance from one point to the next
		float distance = direction.length();
		
		//get the normalized direction. normalized vectors always have a length of one
		//and are really useful for representing directions as opposed to something with length
		ofVec3f unitDirection = direction.normalized();
		
		//find both directions to the left and to the right 
		ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
		ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
		
		//use the map function to determine the distance.
		//the longer the distance, the narrower the line. 
		//this makes it look a bit like brush strokes
		float thickness = ofMap(distance, 0, 60, 20, 2, true);
		
		//calculate the points to the left and to the right
		//by extending the current point in the direction of left/right by the length
		ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
		ofVec3f rightPoint = thisPoint+toTheRight*thickness;
		
		//add these points to the triangle strip
		glColor3f(0,0,0);
		glVertex3f(leftPoint.x, leftPoint.y, leftPoint.z);
		glVertex3f(rightPoint.x, rightPoint.y, rightPoint.z);
	}
    
	//end the shape
    glEnd();
    		
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
	//if we are using the camera, the mouse moving should rotate it around the whole sculpture
		
	//find the amount to rotate based on the x position of the mouse		
	//get the furthest point away, which will be the oldest point		
	//find the direction to the furthers point from the center
	//rotate that directionaround Y 
	//set the camera at the point we get by translating the center in the direction of the rotated furthest point
	//look back at the center

	//otherwise add points like normal
	ofVec3f mousePoint(x,y,0);
	points.push_back(mousePoint);        
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}