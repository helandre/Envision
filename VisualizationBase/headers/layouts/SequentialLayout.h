/***********************************************************************************************************************
 * SequentialLayout.h
 *
 *  Created on: Dec 9, 2010
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef SEQUENTIALLAYOUT_H_
#define SEQUENTIALLAYOUT_H_

#include "../visualizationbase_api.h"

#include "Layout.h"
#include "SequentialLayoutStyle.h"

#include <QtCore/QList>

namespace Model { class Node; }

namespace Visualization {

class ModelRenderer;

class VISUALIZATIONBASE_API SequentialLayout: public Layout
{
	ITEM_COMMON(SequentialLayout)

	private:
		QVector<Item*> items;

	public:
		SequentialLayout(Item* parent, const StyleType* style = Styles::layout<SequentialLayout>("default"));
		~SequentialLayout();

		virtual bool isEmpty() const;

		virtual void updateGeometry(int availableWidth, int availableHeight);

		int focusedElementIndex() const;
		virtual bool focusChild(FocusTarget location);

		int length() const;

		void append(Item* item);
		void prepend(Item* item);
		void insert(Item* item, int position);
		void swap(int i, int j);

		void remove(int index, bool deleteItem = true);
		void removeAll(Item* item, bool deleteItem = true);
		void clear(bool deleteItems = true);

		template <class T> T* at(int index);
		template <class T> T* at(int index) const;

		void synchronizeWithNodes(const QList<Model::Node*>& nodes, ModelRenderer* renderer);

		void synchronizeFirst(Item*& item, Model::Node* node);
		void synchronizeLast(Item*& item, Model::Node* node);
		void synchronizeMid(Item*& item, Model::Node* node, int position);
		template <class T> void synchronizeFirst(T*& item, bool present, const typename T::StyleType* style);
		template <class T> void synchronizeLast(T*& item, bool present, const typename T::StyleType* style);
		template <class T> void synchronizeMid(T*& item, bool present, const typename T::StyleType* style, int position);
		template <class T> void synchronizeFirst(T*& item, typename T::NodeType* node, const typename T::StyleType* style);
		template <class T> void synchronizeLast(T*& item, typename T::NodeType* node, const typename T::StyleType* style);
		template <class T> void synchronizeMid(T*& item, typename T::NodeType* node, const typename T::StyleType* style, int position);
};

template <class T> inline T* SequentialLayout::at(int index) { return static_cast<T*> (items[index]); }
template <class T> inline T* SequentialLayout::at(int index) const { return static_cast<T*> (items[index]); }

template <class T> void SequentialLayout::synchronizeFirst(T*& item, bool present, const typename T::StyleType* style)
{
	synchronizeMid(item, present, style, 0);
}

template <class T> void SequentialLayout::synchronizeLast(T*& item, bool present, const typename T::StyleType* style)
{
	synchronizeMid(item, present, style, length());
}

template <class T> void SequentialLayout::synchronizeMid(T*& item, bool present, const typename T::StyleType* style, int position)
{
	if (item && !present)
	{
		removeAll(item);
		item = NULL;
	}

	if (!item && present)
	{
		item = new T(NULL, style);
		insert(item, ((position > length()) ? length() : position) );
	}
}

template <class T> void SequentialLayout::synchronizeFirst(T*& item, typename T::NodeType* node, const typename T::StyleType* style)
{
	synchronizeMid(item, node, style, 0);
}

template <class T> void SequentialLayout::synchronizeLast(T*& item, typename T::NodeType* node, const typename T::StyleType* style)
{
	synchronizeMid(item, node, style, length());
}

template <class T> void SequentialLayout::synchronizeMid(T*& item, typename T::NodeType* node, const typename T::StyleType* style, int position)
{
	if (item && item->node() != node)
	{
		removeAll(item);
		item = NULL;
	}

	if (!item && node)
	{
		item = new T(NULL, node, style);
		insert(item, ((position > length()) ? length() : position) );
	}
}

}

#endif /* SEQUENTIALLAYOUT_H_ */
