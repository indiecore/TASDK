#pragma once
#include "Engine.FileWriter.h"
namespace UnrealScript
{
	class FileLog : public FileWriter
	{
	public:
		void OpenLog(ScriptString* LogFilename, ScriptString* extension, bool bUnique)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15722);
			byte params[28] = { NULL };
			*(ScriptString**)params = LogFilename;
			*(ScriptString**)&params[12] = extension;
			*(bool*)&params[24] = bUnique;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CloseLog()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15726);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
