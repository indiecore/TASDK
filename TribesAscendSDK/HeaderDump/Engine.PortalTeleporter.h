#pragma once
#include "Engine.PortalMarker.h"
#include "Engine.SceneCapturePortalActor.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.TextureRenderTarget2D.h"
#include "Engine.Projectile.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class PortalTeleporter : public SceneCapturePortalActor
	{
	public:
		ADD_BOOL(bCanTeleportVehicles, 504, 0x4)
		ADD_BOOL(bAlwaysTeleportNonPawns, 504, 0x2)
		ADD_BOOL(bMovablePortal, 504, 0x1)
		ADD_OBJECT(PortalMarker, MyMarker, 500)
		ADD_STRUCT(int, TextureResolutionY, 496)
		ADD_STRUCT(int, TextureResolutionX, 492)
		ADD_OBJECT(PortalTeleporter, SisterPortal, 488)
		bool TransformActor(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalTeleporter.TransformActor");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		Object::Vector TransformVectorDir(Object::Vector V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalTeleporter.TransformVectorDir");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		Object::Vector TransformHitLocation(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalTeleporter.TransformHitLocation");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		class TextureRenderTarget2D* CreatePortalTexture()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalTeleporter.CreatePortalTexture");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TextureRenderTarget2D**)&params[0];
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalTeleporter.StopsProjectile");
			byte params[8] = { NULL };
			*(class Projectile**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
