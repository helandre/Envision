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
 * VBlock.h
 *
 *  Created on: Feb 15, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef VBLOCK_H_
#define VBLOCK_H_

#include "../oovisualization_api.h"
#include "VBlockStyle.h"

#include "OOModel/src/statements/Block.h"

#include "VisualizationBase/src/items/Item.h"
#include "VisualizationBase/src/items/ItemWithNode.h"

namespace OOVisualization {

class VStatementItemList;

class OOVISUALIZATION_API VBlock : public Visualization::ItemWithNode< Visualization::Item, OOModel::Block>
{
	ITEM_COMMON(VBlock)

	public:
		VBlock(Item* parent, NodeType* node, const StyleType* style = itemStyles().get());
		virtual ~VBlock();

	protected:
		void determineChildren();
		void updateGeometry(int availableWidth, int availableHeight);

	private:
		typedef Visualization::ItemWithNode< Visualization::Item, OOModel::Block> BaseItemType;

		VStatementItemList* items_;
};

}

#endif /* VBLOCK_H_ */
