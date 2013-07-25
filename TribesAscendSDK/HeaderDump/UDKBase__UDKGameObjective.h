#pragma once
#include "Engine__Controller.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Canvas.h"
#include "Engine__Texture2D.h"
#include "Engine__AIController.h"
#include "Engine__Actor.h"
#include "UDKBase__UDKPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKGameObjective." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKGameObjective." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKGameObjective." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKGameObjective : public NavigationPoint
	{
	public:
		ADD_VAR(::ByteProperty, DefenderTeamIndex, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoords'!
		ADD_OBJECT(Texture2D, IconHudTexture)
		ADD_STRUCT(::VectorProperty, HUDLocation, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bUnderAttack, 0x2)
		ADD_VAR(::BoolProperty, bAllowOnlyShootable, 0x1)
		void ObjectiveChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameObjective.ObjectiveChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* GetBestViewTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameObjective.GetBestViewTarget");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		bool BotNearObjective(class AIController* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameObjective.BotNearObjective");
			byte* params = (byte*)malloc(8);
			*(class AIController**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void TriggerFlagEvent(ScriptName EventType, class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameObjective.TriggerFlagEvent");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = EventType;
			*(class Controller**)(params + 8) = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHUDLocation(Vector NewHUDLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameObjective.SetHUDLocation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawIcon(class Canvas* Canvas, Vector IconLocation, float IconWidth, float IconAlpha, class UDKPlayerController* PlayerOwner, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* DrawColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameObjective.DrawIcon");
			byte* params = (byte*)malloc(44);
			*(class Canvas**)params = Canvas;
			*(Vector*)(params + 4) = IconLocation;
			*(float*)(params + 16) = IconWidth;
			*(float*)(params + 20) = IconAlpha;
			*(class UDKPlayerController**)(params + 24) = PlayerOwner;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 28) = DrawColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameObjective.GetTeamNum");
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
