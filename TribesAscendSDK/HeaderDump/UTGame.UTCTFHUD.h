#pragma once
#include "UTGame.UTTeamHUD.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "UTGame.UTGameReplicationInfo.h"
#include "UTGame.UTCTFBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFHUD : public UTTeamHUD
	{
	public:
		ADD_STRUCT(UTGameReplicationInfo::EFlagState, FlagStates, 2748)
		ADD_OBJECT(UTCTFBase, FlagBases, 2740)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46103);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46105);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayTeamLogos(byte TeamIndex, Object::Vector2D pos, float DestScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46108);
			byte params[13] = { NULL };
			*params = TeamIndex;
			*(Object::Vector2D*)&params[4] = pos;
			*(float*)&params[12] = DestScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* GetDirectionalDest(byte TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46117);
			byte params[5] = { NULL };
			*params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
