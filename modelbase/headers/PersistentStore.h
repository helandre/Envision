/***********************************************************************************************************************
 * PersistentStore.h
 *
 *  Created on: Nov 3, 2010
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef PERSISTENTSTORE_H_
#define PERSISTENTSTORE_H_

#include "modelbase_api.h"
#include <QString>
#include <QList>

namespace Model {

typedef long long NodeIdType;

class Node;

struct MODELBASE_API LoadedNode
{
	QString name;
	Node* node;
};

class PersistentStore
{
	public:
		virtual void saveStringValue(const QString &value) = 0;
		virtual void saveIntValue(int value) = 0;
		virtual void saveFloatValue(double value) = 0;
		virtual void saveNode(const Node *node, const QString &name, bool partialLoadHint) = 0;


		virtual Node* loadRootNode(const QString &name) = 0;
		virtual QList<LoadedNode> loadAllSubNodes(Node* parent) = 0;
		virtual int loadIntValue() = 0;
		virtual QString loadStringValue() = 0;
		virtual double loadFloatValue() = 0;
};

}

#endif /* PERSISTENTSTORE_H_ */
