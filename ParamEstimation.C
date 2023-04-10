////////////////////////////////////////
//produce a func for LLR for ///////////
//categorical dist//////////////////////
//Estimate the parameter////////////////
///////////////////////////shoukat//////

#include<iostream>
using namespace std;



int ParamEstimation(const int nmEv){


       //open the data file

	ifstream file("myFile.txt");
	if(!file.is_open()){
	cout<<"Error in oppening the file"<<endl;
	}
        //store the data in an array
        int outcome[nmEv];
	for(int r=0; r<nmEv; r++){
	file >>outcome[r]; //filling the array
        //cout<<outcome[r]<<endl;
	}

       //writting a PDF 
       int alpha=0, beta=0, gamma=0;
       double theta; //unknown parameter
       for(int n=0; n<nmEv; n++){
       
	       if(outcome[n]==1){
		       alpha++;
	       }
	       else if(outcome[n]==2){
	       
		       beta++;
	       }
	       else if(outcome[n]==3){
	       
		       gamma++;
	       }
	       else{
	       cout<<"There is an un-identified particle in the detector!!"<<endl;
	       }

       }//loopclosed
  const int nmAlpha=alpha;
  const int nmBeta=beta;
  const int nmGamma=gamma;

  cout<<"The nm of alpha, beta, and gamma particles are: "<<nmAlpha<< "  "<<nmBeta<<"  "<<nmGamma<<endl;  

          //prob for alpha and beta
	  double const prob_alpha = (double) nmAlpha/(double)nmEv;
	  double const prob_gamma = (double)nmGamma/(double)nmEv;
	  cout<<"alpha and beta carries the probabilities as: "<<prob_alpha<<"   "<<prob_gamma<<endl;

           //fn for LLR 
	   double LLR = -(nmAlpha*TMath::Log(prob_alpha) +nmBeta*TMath::Log(theta)+nmGamma*TMath::Log(prob_gamma))/nmEv;//maximize this fn to get theta(unknown parameter)

	   //using lagrange multiplier, setting the constraint sum_all prob=1, the expression for theta(unknown parameter) can be written
	   
	   theta = (double)nmBeta/(double)nmEv;

	   cout<<"the estimated value for theta is:  "<<theta<<endl;
	   double d_theta= 0.44-theta;
	   //residuals for two other parameters is given by
	  double  d_alpha=0.28-prob_alpha;
	  double d_gamma= 0.28-prob_gamma;
	   cout<<"the residuals of the measured values are:  [ "<<d_alpha<<" , "<<d_theta<<" , "<<d_gamma<<" ]"<<endl;

	const double res[3] = {d_alpha, d_theta, d_gamma};
	 const  double part[3] ={1., 2., 3.};

           //to make the plots
	   auto *c = new TCanvas();
	   gStyle->SetStatX(0.7);
           gStyle->SetStatW(0.2);
           gStyle->SetLabelOffset(1.2);
           gStyle->SetLabelFont(72);
	   auto *gr = new TGraph(3, part, res);
	   gr->SetTitle("Residuals plot");
	   gr->GetXaxis()->SetTitle("particles(1=Alpha, 2=Beta, 3=Gamma)");
	   gr->GetYaxis()->SetTitle("(true-estimated) parameter");
	   gr->SetMarkerStyle(21);
	   gr->SetMarkerColor(2);
           gr->GetYaxis()->SetRangeUser(-0.1, 0.1);
	   gr->Draw("ap");


	   c->SaveAs("esParam.pdf");
return 0;

}
