#pragma once
#include "Engine.Teleporter.h"
#include "Engine.TextureRenderTarget2D.h"
#include "Engine.SoundCue.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.MaterialInterface.h"
#include "Engine.Actor.h"
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
	class UDKTeleporterBase : public Teleporter
	{
	public:
		ADD_OBJECT(SoundCue, TeleportingSound, 768)
		ADD_STRUCT(ScriptName, PortalTextureParameter, 760)
		ADD_OBJECT(MaterialInstanceConstant, PortalMaterialInstance, 756)
		ADD_OBJECT(MaterialInterface, PortalMaterial, 752)
		ADD_OBJECT(Actor, PortalViewTarget, 748)
		ADD_STRUCT(int, TextureResolutionY, 744)
		ADD_STRUCT(int, TextureResolutionX, 740)
		ADD_OBJECT(TextureRenderTarget2D, TextureTarget, 736)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKTeleporterBase.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializePortalEffect(class Actor* Dest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKTeleporterBase.InitializePortalEffect");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Dest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Accept(class Actor* Incoming, class Actor* Source)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKTeleporterBase.Accept");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = Incoming;
			*(class Actor**)&params[4] = Source;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
