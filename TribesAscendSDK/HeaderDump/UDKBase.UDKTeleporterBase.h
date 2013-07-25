#pragma once
#include "Engine.Teleporter.h"
#include "Engine.TextureRenderTarget2D.h"
#include "Engine.SoundCue.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.MaterialInterface.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKTeleporterBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKTeleporterBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKTeleporterBase : public Teleporter
	{
	public:
		ADD_OBJECT(SoundCue, TeleportingSound)
		ADD_VAR(::NameProperty, PortalTextureParameter, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, PortalMaterialInstance)
		ADD_OBJECT(MaterialInterface, PortalMaterial)
		ADD_OBJECT(Actor, PortalViewTarget)
		ADD_VAR(::IntProperty, TextureResolutionY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TextureResolutionX, 0xFFFFFFFF)
		ADD_OBJECT(TextureRenderTarget2D, TextureTarget)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKTeleporterBase.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializePortalEffect(class Actor* Dest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKTeleporterBase.InitializePortalEffect");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Dest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Accept(class Actor* Incoming, class Actor* Source)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKTeleporterBase.Accept");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = Incoming;
			*(class Actor**)(params + 4) = Source;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
