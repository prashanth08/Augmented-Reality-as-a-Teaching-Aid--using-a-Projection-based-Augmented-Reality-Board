#pragma once

#include "ofMain.h"
#include "page2.h"
#include "../english.h"
#include "../maths.h"
#include "../biology.h"
#include "../geography.h"
#include "../science.h"

//-----------------------------BEGINER--------------------------------
#include "../src/beg/english/eng1/eng1.h"
#include "../src/beg/english/eng2/eng2.h"
#include "../src/beg/english/eng3/eng3.h"
#include "../src/beg/english/eng4/eng4.h"
#include "../src/beg/english/eng5/eng5.h"

#include "../src/beg/math/math1/math1.h"
#include "../src/beg/math/mat2/mat2.h"
#include "../src/beg/math/mat3/mat3.h"
#include "../src/beg/math/mat4/mat4.h"
#include "../src/beg/math/mat5/mat5.h"

#include "../apps/myApps/ARapp/src/beg/biology/bio1/bio1.h"
#include "../apps/myApps/ARapp/src/beg/biology/bio2/bio2.h"
#include "../apps/myApps/ARapp/src/beg/biology/bio3/bio3.h"
#include "../apps/myApps/ARapp/src/beg/biology/bio4/bio4.h"
#include "../apps/myApps/ARapp/src/beg/biology/bio5/bio5.h"

#include "../apps/myApps/ARapp/src/beg/geo/geo1/geo1.h"
#include "../apps/myApps/ARapp/src/beg/geo/geo2/geo2.h"
#include "../apps/myApps/ARapp/src/beg/geo/geo3/geo3.h"
#include "../apps/myApps/ARapp/src/beg/geo/geo4/geo4.h"
#include "../apps/myApps/ARapp/src/beg/geo/geo5/geo5.h"

#include "../apps/myApps/ARapp/src/beg/science/sci1/sci1.h"
#include "../apps/myApps/ARapp/src/beg/science/sci2/sci2.h"
#include "../apps/myApps/ARapp/src/beg/science/sci3/sci3.h"
#include "../apps/myApps/ARapp/src/beg/science/sci4/sci4.h"
#include "../apps/myApps/ARapp/src/beg/science/sci5/sci5.h"

//-----------------------------INTERMEDIATE--------------------------------

#include "../src/int/englishi/engi1/engi1.h"
#include "../src/int/englishi/engi2/engi2.h"
#include "../src/int/englishi/engi3/engi3.h"
#include "../src/int/englishi/engi4/engi4.h"
#include "../src/int/englishi/engi5/engi5.h"

//-----------------------------ADVANCED--------------------------------


class testApp : public ofBaseApp{

	public:
		void setup();
		void update(int, int, bool);
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		int subject;
		int counter;
		int score;


private:
	void laserClicked(int, int);
	void gameLogic();
	int engLogic();
	int mathLogic();
	int bioLogic();
	int geoLogic();
	int sciLogic();

	int ans;
	bool mClicked;
	int xLoc, yLoc;
	bool beg, inter, adv;
	bool ansCorrect;
	int delayCounter;
	bool clickDone;
	bool clickedOutside;

	ofTrueTypeFont  a;
	ofTrueTypeFont  b;

	testAppp2 page2;
    english eng;
	maths math;
	biology bio;
	geography geo;
	science sci;

//-----------------------------BEGINER--------------------------------
	testApp1 eng1;
	testApp2 eng2;
	testApp3 eng3;
	testApp4 eng4;
	testApp5 eng5;
		
	testApp16 math1;
	testApp17 mat2;
	testApp18 mat3;
	testApp19 mat4;
	testApp20 mat5;
   
	testApp46 bio1;
	testApp47 bio2;
	testApp48 bio3;
	testApp49 bio4;
	testApp50 bio5;

	testApp61 geo1;
	testApp62 geo2;
	testApp63 geo3;
	testApp64 geo4;
	testApp65 geo5;

	testApp31 sci1;
	testApp32 sci2;
	testApp33 sci3;
	testApp34 sci4;
	testApp35 sci5;
//-----------------------------INTERMEDIATE--------------------------------	
	
	testApp6 engi1;
	testApp7 engi2;
	testApp8 engi3;
	testApp9 engi4;
	testApp10 engi5;

	testApp21 mati1;
	testApp22 mati2;
	testApp23 mati3;
	testApp24 mati4;
	testApp25 mati5;

	testApp51 bioi1;
	testApp52 bioi2;
	testApp53 bioi3;
	testApp54 bioi4;
	testApp55 bioi5;

	testApp66 geoi1;
	testApp67 geoi2;
	testApp68 geoi3;
	testApp69 geoi4;
	testApp70 geoi5;
		
	
	testApp36 scii1;
	testApp37 scii2;
	testApp38 scii3;
	testApp39 scii4;
	testApp40 scii5;

//-----------------------------ADVANCED--------------------------------
	testApp11 enga1;
	testApp12 enga2;
	testApp13 enga3;
	testApp14 enga4;
	testApp15 enga5;

	testApp26 mata1;
	testApp27 mata2;
	testApp28 mata3;
	testApp29 mata4;
	testApp30 mata5;

	testApp56 bioa1;
	testApp57 bioa2;
	testApp58 bioa3;
	testApp59 bioa4;
	testApp60 bioa5;

	testApp71 geoa1;
	testApp72 geoa2;
	testApp73 geoa3;
	testApp74 geoa4;
	testApp75 geoa5;

	testApp41 scia1;
	testApp42 scia2;
	testApp43 scia3;
	testApp44 scia4;
	testApp45 scia5;
		
};

