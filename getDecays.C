/////////////////////////////
//simulating data for a /////
//categorical prob dis///////
/////////////////////////////


#include<iostream>
using namespace std;

//for 3outcoms 

double getParticle(double xnum){

	if(0<xnum && xnum<=0.28)//assigned prop for alpha 0.28
		return 1;
	else if(0.28<xnum && xnum<0.72)//value of parameter theta=0.44. same as assigned prob for beta
		return 2;
	else if(0.72<=xnum && xnum<1.)//prob assigned to gamma 0.28
	
		return 3;

	else 
		cout<<"Can't identify this particle"<<endl;

}

void getDecays(int numEvents){


	ofstream dataFile;
	dataFile.open("myFile.txt");
	
	
	//for random number generation

	TRandom3 *rnd = new TRandom3();//for random number generation

	TTimeStamp *tm = new TTimeStamp();//good to  get indep random numbers
	double myNum;
	double num=0;

	for(int i=1; i<=numEvents; i++){

		num = rnd->Rndm(tm->GetNanoSec());
//	cout<<"Outcom is of the trial "<<i<<"  is :     "<<num<<endl;	

	myNum = getParticle(num);
	cout<<"Detector reads:   "<<myNum<<endl;
	dataFile << myNum<<endl;
	}
        dataFile.close();

	delete rnd;
	delete tm;
}//end
