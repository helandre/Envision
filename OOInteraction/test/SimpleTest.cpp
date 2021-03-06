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

/***********************************************************************************************************************
 * SimpleTest.cpp
 *
 *  Created on: Jan 12, 2012
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#include "oointeraction.h"
#include "SelfTest/src/SelfTestSuite.h"

#include "expression_editor/OOExpressionBuilder.h"

#include "OOModel/src/allOOModelNodes.h"

#include "VisualizationBase/src/VisualizationManager.h"
#include "VisualizationBase/src/Scene.h"
#include "VisualizationBase/src/node_extensions/Position.h"
#include "VisualizationBase/src/items/RootItem.h"

using namespace OOModel;
using namespace Visualization;

namespace OOInteraction {

Project* addProject(Model::Model* model)
{
	Project* pr = dynamic_cast<Project*> (model->createRoot("Project"));
	model->beginModification(pr, "Adding a project");
		pr->setName("NewProject");
	model->endModification();
	return pr;
}

Class* addClass(Model::Model* model, Project* parent)
{
	Class* cl = nullptr;

	if (!parent) cl = dynamic_cast<Class*> (model->createRoot("Class"));
	model->beginModification(parent ? static_cast<Model::Node*> (parent) :cl, "Adding a hello world class.");
	if (!cl)
	{
		cl = new Class();
		parent->classes()->append(cl);
	}

	cl->setName("SomeClass");

	model->endModification();
	return cl;
}

Method* addDivBySix(Model::Model* model, Class* parent)
{
	Method* divbysix = nullptr;

	if (!parent) divbysix = dynamic_cast<Method*> (model->createRoot("Method"));
	model->beginModification(parent? static_cast<Model::Node*> (parent) : divbysix, "Adding a divBySix method.");
	if (!divbysix)
	{
		divbysix = new Method();
		parent->methods()->append(divbysix);
	}

	divbysix->setName("findDivBySix");
	FormalResult* divbysixResult = new FormalResult();
	divbysixResult->setTypeExpression(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::INT));
	divbysix->results()->append(divbysixResult);
	FormalArgument* arg = new FormalArgument();
	divbysix->arguments()->append(arg);
	arg->setName("numbers");
	ArrayTypeExpression* argType = new ArrayTypeExpression();
	argType->setTypeExpression(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::INT));
	arg->setTypeExpression(argType);

	ExpressionStatement* es = new ExpressionStatement();
	es->setExpression( new EmptyExpression());
	divbysix->items()->append(es);

	VariableDeclaration* exprtest = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest));
	exprtest->setName("exprtest");
	exprtest->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::INT));
	exprtest->setInitialValue( OOExpressionBuilder::getOOExpression("+aa++&b,*e/d-#") );

	VariableDeclaration* exprtest2 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest2));
	exprtest2->setName("exprtest2");
	exprtest2->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest2->setInitialValue( OOExpressionBuilder::getOOExpression("a*b+c/e-d++%--e*-f==g") );

	VariableDeclaration* exprtest3 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest3));
	exprtest3->setName("exprtest3");
	exprtest3->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest3->setInitialValue( OOExpressionBuilder::getOOExpression("a<b||c>d&&e<=f|g&h^~i") );

	VariableDeclaration* exprtest4 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest4));
	exprtest4->setName("exprtest4");
	exprtest4->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest4->setInitialValue( OOExpressionBuilder::getOOExpression("new value[5]") );

	VariableDeclaration* exprtest5 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest5));
	exprtest5->setName("exprtest5");
	exprtest5->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest5->setInitialValue( OOExpressionBuilder::getOOExpression("(castto)object") );

	VariableDeclaration* exprtest6 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest6));
	exprtest6->setName("exprtest6");
	exprtest6->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest6->setInitialValue( OOExpressionBuilder::getOOExpression("{a,bb,ccc}") );

	VariableDeclaration* exprtest7 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest7));
	exprtest7->setName("exprtest7");
	exprtest7->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest7->setInitialValue( OOExpressionBuilder::getOOExpression("{{123,hello},{2,b}}") );

	VariableDeclaration* exprtest8 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest8));
	exprtest8->setName("exprtest8");
	exprtest8->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest8->setInitialValue( OOExpressionBuilder::getOOExpression("a.b+c.d[i].f") );

	VariableDeclaration* exprtest9 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest9));
	exprtest9->setName("exprtest9");
	exprtest9->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest9->setInitialValue( OOExpressionBuilder::getOOExpression("a()+a.b()+a.b[i].f().g()") );

	VariableDeclaration* exprtest10 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest10));
	exprtest10->setName("exprtest10");
	exprtest10->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest10->setInitialValue( OOExpressionBuilder::getOOExpression("this.b(a,b,c,123,false)") );

	VariableDeclaration* exprtest11 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest11));
	exprtest11->setName("exprtest11");
	exprtest11->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest11->setInitialValue( OOExpressionBuilder::getOOExpression("a+\"hello world\"") );

	VariableDeclaration* exprtest12 = new VariableDeclaration();
	divbysix->items()->append(new ExpressionStatement(exprtest12));
	exprtest12->setName("exprtest12");
	exprtest12->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::VOID));
	exprtest12->setInitialValue( OOExpressionBuilder::getOOExpression("int[]") );

	auto exprtest13 = dynamic_cast<AssignmentExpression*>( OOExpressionBuilder::getOOExpression("a=b%=c>>>=d+C"));
	divbysix->items()->append(new ExpressionStatement(exprtest13));

	divbysix->items()->append(new ExpressionStatement( OOExpressionBuilder::getOOExpression("int abc")));

	divbysix->items()->append(new ExpressionStatement( OOExpressionBuilder::getOOExpression("int abc=5+3")));

	divbysix->items()->append(new ExpressionStatement( OOExpressionBuilder::getOOExpression("int cond=abc<50?42:b+c")));

	divbysix->items()->append(new ExpressionStatement( OOExpressionBuilder::getOOExpression("Generic<T,U> instance")));

	divbysix->items()->append(new ExpressionStatement( OOExpressionBuilder::getOOExpression("int a=method<T,S>(x)")));
	divbysix->items()->append(new ExpressionStatement( OOExpressionBuilder::getOOExpression("a||b||c||d-a+b+c+d")));
	divbysix->items()->append(new ExpressionStatement( OOExpressionBuilder::getOOExpression("a+b+c+d-d||a||b||c||d")));

	divbysix->items()->append(new ExpressionStatement( OOExpressionBuilder::getOOExpression("SomeClass var")));
	divbysix->items()->append(new ExpressionStatement( OOExpressionBuilder::getOOExpression("var.a")));

	divbysix->items()->append(new ExpressionStatement( OOExpressionBuilder::getOOExpression("int d=(a+b)/42")));

	VariableDeclaration* result = new VariableDeclaration();
	divbysix->items()->append( new ExpressionStatement(result) );
	result->setName("result");
	result->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::INT));
	result->setInitialValue(new IntegerLiteral(-1));

	LoopStatement* sixloop = new LoopStatement();
	divbysix->items()->append(sixloop);
	VariableDeclaration* sixLoopInit = new VariableDeclaration();
	sixloop->setInitStep(sixLoopInit);
	sixLoopInit->setName("i");
	sixLoopInit->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::INT));
	sixLoopInit->setInitialValue(new IntegerLiteral(0));
	BinaryOperation* sixLoopCond = new BinaryOperation();
	sixloop->setCondition(sixLoopCond);
	sixLoopCond->setLeft(new ReferenceExpression("i"));
	sixLoopCond->setOp(BinaryOperation::LESS);
	MethodCallExpression* sizeCall = new MethodCallExpression("size", new ReferenceExpression("numbers"));
	sixLoopCond->setRight(sizeCall);

	//TODO test the visualization without the remaining parts of this method
	AssignmentExpression* sixLoopUpdate = new AssignmentExpression();
	sixloop->setUpdateStep(sixLoopUpdate);
	sixLoopUpdate->setLeft(new ReferenceExpression("i"));
	sixLoopUpdate->setOp(AssignmentExpression::PLUS_ASSIGN);
	sixLoopUpdate->setRight(new IntegerLiteral(1));

	VariableDeclaration* n = new VariableDeclaration();
	sixloop->body()->append(new ExpressionStatement(n));
	n->setName("n");
	n->setVarType(new PrimitiveTypeExpression(PrimitiveTypeExpression::PrimitiveTypes::INT));
	BinaryOperation* item = new BinaryOperation();
	n->setInitialValue(item);
	item->setLeft(new ReferenceExpression("numbers"));
	item->setOp(BinaryOperation::ARRAY_INDEX);
	item->setRight(new ReferenceExpression("i"));

	IfStatement* ifdiv2 = new IfStatement();
	sixloop->body()->append(ifdiv2);
	BinaryOperation* eq0 = new BinaryOperation();
	ifdiv2->setCondition(eq0);
	eq0->setOp(BinaryOperation::EQUALS);
	eq0->setRight(new IntegerLiteral(0));
	BinaryOperation* div2 = new BinaryOperation();
	eq0->setLeft(div2);
	div2->setLeft(new ReferenceExpression("n"));
	div2->setOp(BinaryOperation::REMAINDER);
	div2->setRight(new IntegerLiteral(2));
	ifdiv2->elseBranch()->append(new ContinueStatement());

	IfStatement* ifdiv3 = new IfStatement();
	ifdiv2->thenBranch()->append(ifdiv3);
	eq0 = new BinaryOperation();
	ifdiv3->setCondition(eq0);
	eq0->setOp(BinaryOperation::EQUALS);
	eq0->setRight(new IntegerLiteral(0));
	BinaryOperation* div3 = new BinaryOperation();
	eq0->setLeft(div3);
	div3->setLeft(new ReferenceExpression("n"));
	div3->setOp(BinaryOperation::REMAINDER);
	div3->setRight(new IntegerLiteral(3));

	AssignmentExpression* resultFound = new AssignmentExpression();
	ifdiv3->thenBranch()->append(resultFound);
	resultFound->setLeft(new ReferenceExpression("result"));
	resultFound->setOp(AssignmentExpression::ASSIGN);
	resultFound->setRight(new ReferenceExpression("i"));
	ifdiv3->thenBranch()->append(new BreakStatement());

	ReturnStatement* divbysixReturn = new ReturnStatement();
	divbysixReturn->values()->append(new ReferenceExpression("result"));
	divbysix->items()->append(divbysixReturn);

	model->endModification();
	return divbysix;
}

TEST(OOInteraction, SimpleTest)
{
	Model::Model* model = new Model::Model();

	Project* pr = nullptr;
	pr = addProject(model);

	Class* cl = nullptr;
	cl = addClass(model, pr);

	Method* divbysix = nullptr;
	divbysix = addDivBySix(model, cl);

	Model::Node* top_level = nullptr;
	if (pr) top_level = pr;
	else if (cl) top_level = cl;
	else top_level = divbysix;


	VisualizationManager::instance().mainScene()->addTopLevelItem( new RootItem(top_level));
	VisualizationManager::instance().mainScene()->listenToModel(model);

		CHECK_CONDITION(top_level != nullptr);
}

}
