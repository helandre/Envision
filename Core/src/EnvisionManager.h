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
 * EnvisionManager.h
 *
 *  Created on: Oct 29, 2010
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef ENVISIONMANAGER_H_
#define ENVISIONMANAGER_H_

#include "PluginInfo.h"

namespace Core {

/**
 * The EnvisionManager interface provides various information about the Envision system.
 *
 * An instance of an object implementing this interface is passed to each plug-in that is loaded in the system.
 */
class EnvisionManager
{
	public:

		/**
		 * Returns a list of all the plug-ins currently loaded in the system.
		 *
		 * If this method is called during the initialization phase of Envision, only the plug-ins loaded so far will be
		 * included in the list. If a list of all plug-ins is needed, make sure to call this method after Envision has
		 * been fully initialized.
		 */
		virtual QList<PluginInfo> getAllLoadedPluginsInfo() = 0;

		/**
		 * Returns the main window of the application.
		 *
		 * This can be used by visualization plug-ins to draw custom components.
		 */
		virtual QMainWindow* getMainWindow() = 0;

		virtual ~EnvisionManager() {};
};

}

#endif /* ENVISIONMANAGER_H_ */
