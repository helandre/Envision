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
 * ReferenceExpression.h
 *
 *  Created on: Feb 1, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef REFERENCEEXPRESSION_H_
#define REFERENCEEXPRESSION_H_

#include "Expression.h"
#include "../elements/OOReference.h"

#include "ModelBase/src/nodes/TypedList.h"

namespace OOModel {

class Class;

class OOMODEL_API ReferenceExpression: public Expression
{
	EXTENDABLENODE_DECLARE_STANDARD_METHODS(ReferenceExpression)

	ATTRIBUTE(Expression, prefix, setPrefix)
	ATTRIBUTE(OOReference, ref, setRef)
	ATTRIBUTE(Model::TypedList<Expression>, typeArguments, setTypeArguments)

	public:
		ReferenceExpression(const QString& name, Expression* prefix = nullptr);

		Model::Node* target();
		virtual Type* type();

		void setName(const QString& name);
		QString name();
};

inline Model::Node* ReferenceExpression::target() { return ref()->target(); }
inline void ReferenceExpression::setName(const QString& name) {ref()->setName(name);}
inline QString ReferenceExpression::name() {return ref()->name();}

}

#endif /* REFERENCEEXPRESSION_H_ */
