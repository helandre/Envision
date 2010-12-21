/***********************************************************************************************************************
 * BinaryNode.h
 *
 *  Created on: Dec 14, 2010
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef BINARYNODE_H_
#define BINARYNODE_H_

#include "ModelBase/headers/nodes/Extendable/ExtendableNode.h"
#include "ModelBase/headers/nodes/nodeMacros.h"
#include "ModelBase/headers/nodes/Text.h"

namespace Visualization {

class BinaryNode: public Model::ExtendableNode
{
	EXTENDABLENODE_DECLARE_STANDARD_CONSTRUCTORS(BinaryNode)

	private:
		static Model::ExtendableIndex nameIndex;
		static Model::ExtendableIndex leftIndex;
		static Model::ExtendableIndex rightIndex;

	public:
		static void init();

		Model::Text* name();
		BinaryNode* left();
		BinaryNode* right();

		BinaryNode* makeLeftNode(const QString &type = QString());
		BinaryNode* makeRightNode(const QString &type = QString());

		void removeLeftNode();
		void removeRightNode();

};

}

#endif /* BINARYNODE_H_ */