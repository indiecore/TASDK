#pragma once
#include "Engine.PortalMarker.h"
#include "Engine.SceneCapturePortalActor.h"
#include "Engine.Actor.h"
#include "Engine.TextureRenderTarget2D.h"
#include "Engine.Projectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PortalTeleporter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PortalTeleporter." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PortalTeleporter : public SceneCapturePortalActor
	{
	public:
		ADD_VAR(::BoolProperty, bCanTeleportVehicles, 0x4)
		ADD_VAR(::BoolProperty, bAlwaysTeleportNonPawns, 0x2)
		ADD_VAR(::BoolProperty, bMovablePortal, 0x1)
		ADD_OBJECT(PortalMarker, MyMarker)
		ADD_VAR(::IntProperty, TextureResolutionY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TextureResolutionX, 0xFFFFFFFF)
		ADD_OBJECT(PortalTeleporter, SisterPortal)
		bool TransformActor(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalTeleporter.TransformActor");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		Vector TransformVectorDir(Vector V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalTeleporter.TransformVectorDir");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		Vector TransformHitLocation(Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalTeleporter.TransformHitLocation");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		class TextureRenderTarget2D* CreatePortalTexture()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalTeleporter.CreatePortalTexture");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TextureRenderTarget2D**)params;
			free(params);
			return returnVal;
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalTeleporter.StopsProjectile");
			byte* params = (byte*)malloc(8);
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
