/*
 * Structures.h
 *
 *  Created on: Mar 16, 2019
 *      Author: twhite
 */

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

namespace strc{

	typedef float scalar;

	struct vector3d{
		scalar x;
		scalar y;
		scalar z;

		vector3d operator+(vector3d vec2){
			vector3d nvec;
			nvec.x = vec2.x + this->x;	nvec.y = vec2.y + this->y;	nvec.z = vec2.z + this->z;
			return nvec;
		}

		scalar dot(vector3d vec2){
			return (this->x * vec2.x) + (this->y * vec2.y) + (this->z * vec2.z);
		}


	};


}
