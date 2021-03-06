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
 * TextAndDescription.h
 *
 *  Created on: Jan 18, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef TEXTANDDESCRIPTION_H_
#define TEXTANDDESCRIPTION_H_

#include "interactionbase_api.h"
#include "TextAndDescriptionStyle.h"

#include "VisualizationBase/src/items/LayoutProvider.h"
#include "VisualizationBase/src/items/Text.h"
#include "VisualizationBase/src/layouts/SequentialLayout.h"

namespace Interaction {

class INTERACTIONBASE_API TextAndDescription : public Visualization::LayoutProvider<>
{
	ITEM_COMMON(TextAndDescription)

	public:
		TextAndDescription(Item* parent, const StyleType* style = itemStyles().get());
		TextAndDescription(const QString& text, const QString& description, const StyleType* style = itemStyles().get());
		virtual ~TextAndDescription();

		virtual bool sizeDependsOnParent() const;

		void setContents(const QString& text, const QString& description);

	protected:
		virtual void determineChildren();

	private:
		typedef Item BaseItemType;

		Visualization::Text* textVis_;
		Visualization::Text* descriptionVis_;

		QString text_;
		QString description_;
};

}

#endif /* TEXTANDDESCRIPTION_H_ */
