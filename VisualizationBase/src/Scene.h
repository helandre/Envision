/***********************************************************************************************************************
**
** Copyright (c) 2011, ETH Zurich
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
** following conditions are met:
**
**    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following
**      disclaimer.
**    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
**      following disclaimer in the documentation and/or other materials provided with the distribution.
**    * Neither the name of the ETH Zurich nor the names of its contributors may be used to endorse or promote products
**      derived from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
** INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
***********************************************************************************************************************/

/***********************************************************************************************************************
 * Scene.h
 *
 *  Created on: Dec 6, 2010
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef SCENE_H_
#define SCENE_H_

#include "visualizationbase_api.h"

namespace Model {
	class Model;
	class Node;
}

namespace Visualization {

class Item;
class ModelRenderer;
class SceneHandlerItem;
class SelectedItem;
class Cursor;

class VISUALIZATIONBASE_API Scene : public QGraphicsScene
{
	Q_OBJECT

	private:

		// This is needed in order to make the Signals and Slots mechanism work. Otherwise we are not able to connect to
		// the signal provided from Model. This is because the signatures of the two methods, must match exactly
		// (stringwise).
		typedef Model::Node Node;

	public:
		Scene();
		virtual ~Scene();
		void setRenderer(ModelRenderer* renderer);

		ModelRenderer* renderer();
		static ModelRenderer* defaultRenderer();

		void addTopLevelItem(Item* item);
		void removeTopLevelItem(Item* item);
		void scheduleUpdate();
		void listenToModel(Model::Model* model);

		Cursor* mainCursor();
		void setMainCursor(Cursor* cursor);

		virtual void customEvent(QEvent *event);

		virtual SceneHandlerItem* sceneHandlerItem();

		/**
		 * Adds an action to be executed after the current event.
		 *
		 * This method can only be called while handling an event.
		 */
		void addPostEventAction(QEvent* action);

		enum ItemCategory {
			NoItemCategory = 0x0,
			CodeItemCategory = 0x1,
			MenuItemCategory = 0x2,
			SelectionItemCategory = 0x4,
			CursorItemCategory = 0x8
		};
		Q_DECLARE_FLAGS(ItemCategories, ItemCategory)

		void setHiddenItemCategories( ItemCategories hidden = NoItemCategory);
		bool isHiddenCategory(ItemCategory cat);

	public slots:
		void nodesUpdated(QList<Node*> nodes);

	protected:
		bool event(QEvent *event);

	private:
		bool needsUpdate_;

		ModelRenderer* renderer_;
		SceneHandlerItem* sceneHandlerItem_;
		QList<Item*> topLevelItems_;
		QList<SelectedItem*> selections_;
		QList<Cursor*> cursors_;
		QList<QEvent*> postEventActions_;

		bool inEventHandler_;
		bool inAnUpdate_;

		ItemCategories hiddenItemCategories_;

		void updateItems();
		void computeSceneRect();
};

Q_DECLARE_OPERATORS_FOR_FLAGS(Scene::ItemCategories)
inline void Scene::setHiddenItemCategories( ItemCategories hidden) {hiddenItemCategories_ = hidden;}
inline bool Scene::isHiddenCategory(ItemCategory cat) {return cat & hiddenItemCategories_;}

inline void Scene::setRenderer(ModelRenderer* renderer) { renderer_ = renderer? renderer : defaultRenderer(); }
inline ModelRenderer* Scene::renderer() { return renderer_; }
inline SceneHandlerItem* Scene::sceneHandlerItem() {return sceneHandlerItem_; }
inline Cursor* Scene::mainCursor() { return cursors_.isEmpty() ? nullptr : cursors_.first(); }


}

#endif /* SCENE_H_ */
