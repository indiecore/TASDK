#pragma once
#include "UDKBase__UDKGameObjective.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#include "Engine__TeamInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKCarriedObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKCarriedObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKCarriedObject." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKCarriedObject : public Actor
	{
	public:
		ADD_STRUCT(::VectorProperty, HUDLocation, 0xFFFFFFFF
		ADD_OBJECT(Actor, OldBaseBase)
		ADD_OBJECT(Actor, OldBase)
		ADD_STRUCT(::VectorProperty, HomeBaseOffset, 0xFFFFFFFF
		ADD_OBJECT(UDKGameObjective, HomeBase)
		ADD_VAR(::BoolProperty, bHome, 0x1)
		ADD_VAR(::FloatProperty, LastValidAnchorTime, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, LastAnchor)
		ADD_OBJECT(TeamInfo, Team)
		void SetHUDLocation(Vector NewHUDLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKCarriedObject.SetHUDLocation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotReachableBy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKCarriedObject.NotReachableBy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnBaseChainChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKCarriedObject.OnBaseChainChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKCarriedObject.GetTeamNum");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
