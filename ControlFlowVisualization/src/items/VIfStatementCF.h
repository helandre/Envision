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
 * VIfStatementCF.h
 *
 *  Created on: Mar 2, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef VIFSTATEMENTCF_H_
#define VIFSTATEMENTCF_H_

#include "../controlflowvisualization_api.h"
#include "VIfStatementCFStyle.h"
#include "VListCF.h"

#include "OOModel/src/statements/IfStatement.h"

namespace ControlFlowVisualization {

class CONTROLFLOWVISUALIZATION_API VIfStatementCF
: public Visualization::ItemWithNode<ControlFlowItem, OOModel::IfStatement>
{
	ITEM_COMMON(VIfStatementCF)

	public:
		VIfStatementCF(Item* parent, NodeType* node, const StyleType* style = itemStyles().get());
		virtual ~VIfStatementCF();

		virtual bool sizeDependsOnParent() const;
		virtual bool isEmpty() const;

	protected:
		virtual void determineChildren();
		virtual void updateGeometry(int availableWidth, int availableHeight);

	private:
		typedef Visualization::ItemWithNode<ControlFlowItem, OOModel::IfStatement> BaseItemType;

		Visualization::SequentialLayout* conditionBackground;

		Visualization::Item* condition;
		VListCF* thenBranch;
		VListCF* elseBranch;
};

}

#endif /* VIFSTATEMENTCF_H_ */
