/***********************************************************************************************************************
 **
 ** Copyright (c) 2011, 2012 ETH Zurich
 ** All rights reserved.
 **
 ** Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 ** following conditions are met:
 **
 **    * Redistributions of source code must retain the above copyright notice, this list of conditions and the
 **      following disclaimer.
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
 **********************************************************************************************************************/

/*
 * MemberOperatorDescriptor.cpp
 *
 *  Created on: Feb 29, 2012
 *      Author: Dimitar Asenov
 */

#include "expression_editor/operators/MemberOperatorDescriptor.h"

#include "OOModel/src/expressions/ReferenceExpression.h"
#include "OOModel/src/expressions/EmptyExpression.h"
#include "OOModel/src/expressions/CommaExpression.h"

namespace OOInteraction {

MemberOperatorDescriptor::MemberOperatorDescriptor(const QString& name, const QString& signature, int num_operands,
		int precedence, Associativity associativity)
		: OOOperatorDescriptor(name, signature, num_operands, precedence, associativity)
{}

OOModel::Expression* MemberOperatorDescriptor::create(const QList<OOModel::Expression*>& operands)
{
	Q_ASSERT(operands.size() == 2 || operands.size() == 3 );
	auto ref = dynamic_cast<OOModel::ReferenceExpression*>( operands[1]);
	Q_ASSERT(ref);

	OOModel::ReferenceExpression* r = new OOModel::ReferenceExpression( ref->name(), operands.first() );
	SAFE_DELETE(ref);

	if (operands.size() == 3)
	{
		if (auto comma = dynamic_cast<OOModel::CommaExpression*>(operands.last()))
		{
			for(auto arg : comma->allSubOperands(true))
				r->typeArguments()->append(arg);

			SAFE_DELETE(comma);
		}
		else
			if (!dynamic_cast<OOModel::EmptyExpression*>(operands.last()) )
				r->typeArguments()->append(operands.last());
	}

	return r;
}

} /* namespace OOInteraction */
