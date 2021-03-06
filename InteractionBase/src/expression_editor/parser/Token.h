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
 * Token.h
 *
 *  Created on: Jan 11, 2012
 *      Author: Dimitar Asenov
 */

#ifndef INTERACTIONBASE_TOKEN_H_
#define INTERACTIONBASE_TOKEN_H_

#include "../../interactionbase_api.h"

namespace Interaction {

class OperatorDescriptorList;

class INTERACTIONBASE_API Token {
	public:
		enum Type {Identifier, Literal, OperatorDelimiter, PartialLiteral};

		Token();
		Token(QString text, Type type);

		const QString& text() const;
		Type type() const;

		static QVector<Token> tokenize(QString input, const OperatorDescriptorList* ops);

	private:
		QString text_;
		Type type_;

		static bool tokenExistsInOperators(QString token, const OperatorDescriptorList* ops);
		static QStringList specialSignatureWords_;
};

inline const QString& Token::text() const { return text_; }
inline Token::Type Token::type() const { return type_; }

} /* namespace InteractionBase */
#endif /* INTERACTIONBASE_TOKEN_H_ */
