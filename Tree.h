/*
 * Tree.h
 *
 *  Created on: Jan 21, 2016
 *      Author: pepc
 */

#ifndef TREE_H_
#define TREE_H_

#include "ObjetoCompuesto3D.h"
#include "Cilindro.h"

class Tree: public ObjetoCompuesto3D {
public:
	Tree(float height);
	virtual ~Tree();
};

#endif /* TREE_H_ */
