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
 * FormalArgument.h
 *
 *  Created on: Jan 31, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef FORMALARGUMENT_H_
#define FORMALARGUMENT_H_

#include "../oomodel_api.h"

#include "../attributeMacros.h"
#include "../expressions/Expression.h"

#include "ModelBase/src/nodes/Extendable/ExtendableNode.h"
#include "ModelBase/src/nodes/Text.h"
#include "ModelBase/src/nodes/nodeMacros.h"
#include "ModelBase/src/nodes/Integer.h"

namespace OOModel {

class OOMODEL_API FormalArgument : public Model::ExtendableNode
{
	EXTENDABLENODE_DECLARE_STANDARD_METHODS(FormalArgument)
	ATTRIBUTE_OOP_NAME
	ATTRIBUTE(Expression, typeExpression, setTypeExpression)
	PRIVATE_ATTRIBUTE_VALUE(Model::Integer, directionInt, setDirectionInt, int)

	public:
		enum Direction {IN, OUT, INOUT};

		FormalArgument(const QString& name, Expression* type = nullptr, const Direction& direction = IN);
		FormalArgument(const QString& name, const Direction& direction);

		Direction direction() const;
		void setDirection(const Direction& direction);

		virtual bool definesSymbol() const;
		virtual const QString& symbolName() const;
};

inline FormalArgument::Direction FormalArgument::direction() const { return static_cast<Direction> (directionInt()); }
inline void FormalArgument::setDirection(const Direction& direction) { setDirectionInt(direction); }

}

#endif /* FORMALARGUMENT_H_ */
