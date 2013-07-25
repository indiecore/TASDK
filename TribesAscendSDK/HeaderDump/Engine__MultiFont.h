#pragma once
#include "Engine__Font.h"
namespace UnrealScript
{
	class MultiFont : public Font
	{
	public:
		int GetResolutionTestTableIndex(float HeightTest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MultiFont.GetResolutionTestTableIndex");
			byte* params = (byte*)malloc(8);
			*(float*)params = HeightTest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
