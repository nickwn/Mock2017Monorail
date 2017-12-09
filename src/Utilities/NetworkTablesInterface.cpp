/*
 * NetworkTablesInterface.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Dhruti
 */

#include "NetworkTablesInterface.h"

/*NetworkTablesInterface::NetworkTablesInterface() {
 // TODO Auto-generated constructor stub

 }

 NetworkTablesInterface::~NetworkTablesInterface() {
 // TODO Auto-generated destructor stub
 }*/

bool NetworkTablesInterface::TargetFound() {
	return NetworkTable::GetTable("cv")->GetBoolean("targetFound", false);
}

std::string NetworkTablesInterface::Orientation() {
	return NetworkTable::GetTable("cv")->GetString("orientation", "A");
}

double NetworkTablesInterface::TargetAzimuth() {
	return NetworkTable::GetTable("cv")->GetNumber("targetAzimuth", -1.0);
}
