/*
 * This is a header only class since it is intended to be very simplistic
 * keeps track of ids that have been assigned to objects and also has its own id in order to segregate groups of objects
 * IdGroup.h
 *
 *  Created on: Mar 5, 2019
 *      Author: twhite
 */

typedef unsigned short int ObjectId;

#ifndef IDGROUP_H_
#define IDGROUP_H_



// a few bitwise operations that combine 2 object ids into a single unsigned int
unsigned int glueId(const ObjectId majorId, const ObjectId minorId){

	unsigned int rtn = (unsigned int) majorId;

	rtn = rtn << sizeof(ObjectId);

	rtn = rtn || ((unsigned int) minorId);

	return rtn;

}

class IdGroup {
public:


	IdGroup(ObjectId masterId){

		this->masterId	= masterId;
		this->idCount 	= 0;

	}

	ObjectId getNextId(){
		return this->idCount++;
	}

	ObjectId getMasterId() const{
		return this->masterId;
	}

	virtual ~IdGroup();


private:

	ObjectId idCount; // the next id that will be used when an object is assigned an Id
	ObjectId masterId; // The Id of the Id handler itself, usefull with mods since it avoids Id conflicts

};

#endif /* IDGROUP_H_ */