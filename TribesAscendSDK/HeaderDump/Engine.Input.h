#pragma once
#include "Engine.Interaction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Input." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Input : public Interaction
	{
	public:
		ADD_VAR(::FloatProperty, CurrentDeltaTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentDelta, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentEvent, 0xFFFFFFFF)
		void ResetInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Input.ResetInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetBind(ScriptName& Key)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Input.GetBind");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = Key;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Key = *(ScriptName*)params;
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetBindNameFromCommandScript(ScriptArray<wchar_t>& KeyCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Input.GetBindNameFromCommandScript");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = KeyCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			KeyCommand = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetBind(ScriptName& BindName, ScriptArray<wchar_t> Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Input.SetBind");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = BindName;
			*(ScriptArray<wchar_t>*)(params + 8) = Command;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			BindName = *(ScriptName*)params;
			free(params);
		}
	};
}
#undef ADD_VAR
