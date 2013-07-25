#pragma once
#include "Engine__SeqVar_Object.h"
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqVar_Player." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqVar_Player : public SeqVar_Object
	{
	public:
		ADD_VAR(::IntProperty, PlayerIdx, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAllPlayers, 0x1)
		void UpdatePlayersList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqVar_Player.UpdatePlayersList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Object* GetObjectValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqVar_Player.GetObjectValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Object**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
