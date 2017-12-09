/*
 * NetworkTablesInterface.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Dhruti
 */

#ifndef UTILITIES_NETWORKTABLESINTERFACE_H_
#define UTILITIES_NETWORKTABLESINTERFACE_H_

#include "NetworkTables/NetworkTable.h"

class NetworkTablesInterface {
public:
	//NetworkTablesInterface(); NOT REQUIRED
	//virtual ~NetworkTablesInterface(); NOT REQUIRED
	static bool TargetFound(); //checks if the gear has been detected
	static std::string Orientation(); //gives the distance to the gear
	static double TargetAzimuth(); //gives the azimuth for the gear
};

#endif /* UTILITIES_NETWORKTABLESINTERFACE_H_ */
