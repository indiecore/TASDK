#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxMinimapHud.h"
#include "Engine__WorldInfo.h"
#include "UTGame__UTMapInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxMinimap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.GFxMinimap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxMinimap." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxMinimap : public GFxObject
	{
	public:
		ADD_VAR(::IntProperty, IconsFlagCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconsBlueCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconsRedCount, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, IconsFlagMC)
		ADD_OBJECT(GFxObject, IconsBlueMC)
		ADD_OBJECT(GFxObject, IconsRedMC)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'IconMatrix'!
		ADD_OBJECT(GFxObject, MapMC)
		ADD_OBJECT(GFxObject, CompassIcon)
		ADD_OBJECT(GFxObject, PlayerIcon)
		ADD_VAR(::BoolProperty, bNeedsUpdateData, 0x1)
		ADD_VAR(::IntProperty, MapTexSize, 0xFFFFFFFF)
		ADD_OBJECT(UTMapInfo, MapInfo)
		ADD_OBJECT(WorldInfo, ThisWorld)
		ADD_OBJECT(GFxMinimapHud, HUD)
		void Init(class GFxMinimapHud* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.Init");
			byte* params = (byte*)malloc(4);
			*(class GFxMinimapHud**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.UpdateData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GenFriendIcons(int N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.GenFriendIcons");
			byte* params = (byte*)malloc(16);
			*(int*)params = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GenEnemyIcons(int N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.GenEnemyIcons");
			byte* params = (byte*)malloc(16);
			*(int*)params = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GenFlagIcons(int N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.GenFlagIcons");
			byte* params = (byte*)malloc(16);
			*(int*)params = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		void UpdateIcons(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Actors, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ActorIcons, bool bIsRedIconType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.UpdateIcons");
			byte* params = (byte*)malloc(28);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Actors;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = ActorIcons;
			*(bool*)(params + 24) = bIsRedIconType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Actors = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			ActorIcons = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			free(params);
		}
		void Update(float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxMinimap.Update");
			byte* params = (byte*)malloc(4);
			*(float*)params = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
