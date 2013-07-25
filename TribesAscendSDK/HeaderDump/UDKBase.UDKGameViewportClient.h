#pragma once
#include "Engine.GameViewportClient.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKGameViewportClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKGameViewportClient : public GameViewportClient
	{
	public:
		ADD_VAR(::StrProperty, HintLocFileName, 0xFFFFFFFF)
		ScriptArray<wchar_t> LoadRandomLocalizedHintMessage(ScriptArray<wchar_t> Category1Name, ScriptArray<wchar_t> Category2Name)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameViewportClient.LoadRandomLocalizedHintMessage");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = Category1Name;
			*(ScriptArray<wchar_t>*)(params + 12) = Category2Name;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
