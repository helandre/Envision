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
 * CreateContractMethod.cpp
 *
 *  Created on: May 31, 2012
 *      Author: Dimitar Asenov
 */

#include "CreateContractMethod.h"
#include "OOInteraction/src/expression_editor/OOExpressionBuilder.h"

#include "OOModel/src/expressions/MethodCallExpression.h"

namespace ContractsLibrary {

CreateContractMethod::CreateContractMethod(const QString& name, const QString& methodToCreate,
		int expectedTypeArguments)
: name_(name), methodToCreate_(methodToCreate), expectedTypeArguments_(expectedTypeArguments)
{}

const QString& CreateContractMethod::name() const
{
	return name_;
}

OOModel::Expression* CreateContractMethod::create(const QList<OOModel::Expression*>& arguments)
{
	auto method = static_cast<OOModel::MethodCallExpression*>(
			OOInteraction::OOExpressionBuilder::getOOExpression("CodeContracts.Contract." + methodToCreate_ + "()"));

	int typeArguments = expectedTypeArguments_;
	for(auto a: arguments)
	{
		if (typeArguments > 0)
		{
			method->ref()->typeArguments()->append(a);
			--typeArguments;
		}
		else
			method->arguments()->append(a);
	}

	return method;
}

} /* namespace ContractsLibrary */
