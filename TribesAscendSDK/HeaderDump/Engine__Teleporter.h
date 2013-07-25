#pragma once
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Teleporter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Teleporter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Teleporter : public NavigationPoint
	{
	public:
		ADD_VAR(::FloatProperty, LastFired, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetVelocity, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCanTeleportVehicles, 0x40)
		ADD_VAR(::BoolProperty, bEnabled, 0x20)
		ADD_VAR(::BoolProperty, bReversesZ, 0x10)
		ADD_VAR(::BoolProperty, bReversesY, 0x8)
		ADD_VAR(::BoolProperty, bReversesX, 0x4)
		ADD_VAR(::BoolProperty, bChangesYaw, 0x2)
		ADD_VAR(::BoolProperty, bChangesVelocity, 0x1)
		ADD_VAR(::NameProperty, ProductRequired, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URL, 0xFFFFFFFF)
		bool CanTeleport(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Teleporter.CanTeleport");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Teleporter.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Accept(class Actor* Incoming, class Actor* Source)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Teleporter.Accept");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = Incoming;
			*(class Actor**)(params + 4) = Source;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Teleporter.Touch");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostTouch(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Teleporter.PostTouch");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Actor* SpecialHandling(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Teleporter.SpecialHandling");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
