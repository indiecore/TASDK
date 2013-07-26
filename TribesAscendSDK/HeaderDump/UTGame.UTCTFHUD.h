#pragma once
#include "UTGame.UTTeamHUD.h"
#include "UTGame.UTCTFBase.h"
#include "Core.Object.Vector2D.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFHUD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFHUD : public UTTeamHUD
	{
	public:
		ADD_VAR(::ByteProperty, FlagStates, 0xFFFFFFFF)
		ADD_OBJECT(UTCTFBase, FlagBases)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFHUD.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFHUD.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayTeamLogos(byte TeamIndex, Vector2D pos, float DestScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFHUD.DisplayTeamLogos");
			byte* params = (byte*)malloc(13);
			*params = TeamIndex;
			*(Vector2D*)(params + 4) = pos;
			*(float*)(params + 12) = DestScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Actor* GetDirectionalDest(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFHUD.GetDirectionalDest");
			byte* params = (byte*)malloc(5);
			*params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
