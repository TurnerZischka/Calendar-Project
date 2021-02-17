#ifndef __MOMENT_HPP__
#define __MOMENT_HPP__

#include <string>

class Moment {
   private:
	string title;
	string description;
	string classification;
   	double startTime;
	double endTime;
	double totalTime;
	int priority;
   public:
	Moment(){} // default constructor
	
	// the most common constructor
	Moment(string titIn, string descIn, string catIn, double startIn, double endIn, double totIn, int priIn) {
	title = titIn;
	description = descIn;
	classification = catIn;
	startTime = startIn;
	endTime = endIn;
	totalTime = totIn;
	priority = priIn;
	}



};



#endif
