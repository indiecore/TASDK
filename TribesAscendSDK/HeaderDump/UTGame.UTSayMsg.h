#pragma once
#include "Core.Object.Color.h"
#include "UTGame.UTLocalMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTSayMsg." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSayMsg : public UTLocalMessage
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Color>, BlueTeamColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, RedTeamColor, 0xFFFFFFFF)
		Color GetConsoleColor(class PlayerReplicationInfo* RelatedPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSayMsg.GetConsoleColor");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = RelatedPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Color*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
