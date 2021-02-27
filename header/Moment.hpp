#ifndef __MOMENT_HPP__
#define __MOMENT_HPP__

#include <string>

class Moment {
   private:
	std::string title;
	std::string description;
	std::string classification;
   	double startTime;
	double endTime;
	double totalTime;
	int priority;
	int ID;
   public:
	Moment(){} // default constructor
	
	// the most common constructor
	Moment(std::string titIn, std::string descIn, std::string catIn, double startIn, double endIn, double totIn, int priIn) {
	title = titIn;
	description = descIn;
	classification = catIn;
	startTime = startIn;
	endTime = endIn;
	totalTime = totIn;
	priority = priIn;
	}


	std::string getTitle(){ return title; }
	std::string getDescription(){ return description;}
	std::string getClass(){ return classification; }
	double getStart(){ return startTime; }
	double getEnd() { return endTime; }
	double getTotal() {return totalTime;}
	int getID() {return ID;}
	int getPriority() { return priority; }

	void setTitle(std::string newTit) { title = newTit; }
	void setDescription(std::string newTit) { description = newTit; }
	void setClass(std::string newTit) { classification = newTit; }
	void setStart(double newTit) { startTime = newTit; }
	void setEnd(double newTit) { endTime = newTit; }
	void setTotal(double newTit) { totalTime = newTit; }
	void setPriority(int newTit) { priority = newTit; }
};



#endif
