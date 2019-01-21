#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofNoFill();
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int coordinate_span = 144;
	int radius = 40;
	float span = (2 * PI * radius) / 360;
	for (int x = coordinate_span * 0.5; x < ofGetWidth(); x += coordinate_span) {

		for (int y = coordinate_span * 0.5; y < ofGetHeight(); y += coordinate_span) {

			int small_circle_deg_size = ofMap(ofNoise(ofRandom(360), ofGetFrameNum() * 0.008), 0, 1, 10, 120);
			int small_radius = span * small_circle_deg_size * 0.35;
			int small_deg = ofMap(ofNoise(ofRandom(360), ofGetFrameNum() * 0.003), 0, 1, 0, 720);
			int deg_start = small_deg + small_circle_deg_size * 0.5;
			int deg_end = deg_start + 360 - small_circle_deg_size;
			vector<glm::vec2> vertices;
			for (int deg = deg_start; deg <= deg_end; deg++) {

				vertices.push_back(glm::vec2(x, y) + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
			}

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();

			ofDrawCircle(glm::vec2(x, y) + glm::vec2(radius * cos(small_deg * DEG_TO_RAD), radius * sin(small_deg * DEG_TO_RAD)), small_radius);
		}
	}
}
//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}