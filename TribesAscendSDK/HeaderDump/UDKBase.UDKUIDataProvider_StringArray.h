#pragma once
#include "UDKBase.UDKUIDataProvider_SimpleElementProvider.h"
namespace UnrealScript
{
	class UDKUIDataProvider_StringArray : public UDKUIDataProvider_SimpleElementProvider
	{
	public:
		int GetElementCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataProvider_StringArray.GetElementCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
