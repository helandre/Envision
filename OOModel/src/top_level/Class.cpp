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
 * Class.cpp
 *
 *  Created on: Jan 27, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#include "top_level/Class.h"

namespace OOModel {

EXTENDABLENODE_DEFINE_EMPTY_CONSTRUCTORS(Class, Model::ExtendableNode)
EXTENDABLENODE_DEFINE_TYPE_REGISTRATION_METHODS(Class, Model::ExtendableNode)

REGISTER_ATTRIBUTE(Class, name, Text, false, false, true)
REGISTER_ATTRIBUTE(Class, baseClasses, TypedListOfExpression, false, false, true)
REGISTER_ATTRIBUTE(Class, typeArguments, TypedListOfFormalTypeArgument, false, false, true)
REGISTER_ATTRIBUTE(Class, fields, TypedListOfField, false, false, true)
REGISTER_ATTRIBUTE(Class, methods, TypedListOfMethod, false, false, true)
REGISTER_ATTRIBUTE(Class, visibility, Visibility, false, false, true)
REGISTER_ATTRIBUTE(Class, annotations, StatementItemList, false, false, true)

Class::Class(const QString& name)
: Model::ExtendableNode (nullptr, Class::getMetaData())
{
	setName(name);
}

Class::Class(const QString& name, Visibility::VisibilityType vis)
: Model::ExtendableNode (nullptr, Class::getMetaData())
{
	setName(name);
	setVisibility(vis);
}

bool Class::definesSymbol() const
{
	return true;
}

const QString& Class::symbolName() const
{
	return name();
}

QList<Model::Node*> Class::findSymbols(const QRegExp& symbolExp,Model::Node* source, FindSymbolMode mode,
		bool exhaustAllScopes)
{
	QList<Model::Node*> symbols;

	symbols << methods()->findAllSymbolDefinitions(symbolExp);
	symbols << fields()->findAllSymbolDefinitions(symbolExp);

	if (exhaustAllScopes || symbols.isEmpty())
		symbols << Node::findSymbols(symbolExp, source, mode, exhaustAllScopes);
	return symbols;
}

bool Class::isGeneric()
{
	return typeArguments()->size() > 0;
}

}
