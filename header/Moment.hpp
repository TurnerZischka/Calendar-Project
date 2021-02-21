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


	string getTitle(){ return title; }
	string getDescription(){ return description;}
	string getClass(){ return classification; }
	double getStart(){ return startTime; }
	double getEnd() { return endTime; }
	double getTotal() {return totalTime;}
	int getPriority() { return priority; }

	void setTitle(string newTit) { title = newTit; }
	void setDescription(string newTit) { description = newTit; }
	void setClass(string newTit) { classification = newTit; }
	void setStart(double newTit) { startTime = newTit; }
	void setEnd(double newTit) { endTime = newTit; }
	void setTotal(double newTit) { totalTime = newTit; }
	void setPriority(int newTit) { priority = newTit; }
};



#endif
