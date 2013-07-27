#pragma once
#include "Engine.FileWriter.h"
namespace UnrealScript
{
	class FileLog : public FileWriter
	{
	public:
		void OpenLog(ScriptString* LogFilename, ScriptString* extension, bool bUnique)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FileLog.OpenLog");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = LogFilename;
			*(ScriptString**)&params[12] = extension;
			*(bool*)&params[24] = bUnique;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CloseLog()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FileLog.CloseLog");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
