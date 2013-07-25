#pragma once
#include "Engine__FileWriter.h"
namespace UnrealScript
{
	class FileLog : public FileWriter
	{
	public:
		void OpenLog(ScriptArray<wchar_t> LogFilename, ScriptArray<wchar_t> extension, bool bUnique)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FileLog.OpenLog");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = LogFilename;
			*(ScriptArray<wchar_t>*)(params + 12) = extension;
			*(bool*)(params + 24) = bUnique;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CloseLog()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FileLog.CloseLog");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
