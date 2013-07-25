#pragma once
#include "Engine__PhysicsVolume.h"
#include "Engine__Pawn.h"
#include "Engine__Ladder.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LadderVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LadderVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LadderVolume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LadderVolume : public PhysicsVolume
	{
	public:
		ADD_STRUCT(::VectorProperty, ClimbDir, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bAllowLadderStrafing, 0x4)
		ADD_OBJECT(Pawn, PendingClimber)
		ADD_VAR(::BoolProperty, bAutoPath, 0x2)
		ADD_VAR(::BoolProperty, bNoPhysicalLadder, 0x1)
		ADD_OBJECT(Ladder, LadderList)
		ADD_STRUCT(::VectorProperty, LookDir, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, WallDir, 0xFFFFFFFF
		bool InUse(class Pawn* Ignored)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LadderVolume.InUse");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Ignored;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LadderVolume.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnEnteredVolume(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LadderVolume.PawnEnteredVolume");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnLeavingVolume(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LadderVolume.PawnLeavingVolume");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PhysicsChangedFor(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LadderVolume.PhysicsChangedFor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
