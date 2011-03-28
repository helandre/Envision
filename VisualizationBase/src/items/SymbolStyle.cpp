/***********************************************************************************************************************
 * SymbolStyle.cpp
 *
 *  Created on: Feb 11, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#include "items/SymbolStyle.h"

namespace Visualization {

void SymbolStyle::load(StyleLoader& sl)
{
	TextStyle::load(sl);

	sl.load("symbol", symbol_);
}

}
