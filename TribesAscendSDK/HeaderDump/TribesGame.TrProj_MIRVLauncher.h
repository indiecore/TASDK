#pragma once
#include "TribesGame.TrProj_Grenade.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
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
	class TrProj_MIRVLauncher : public TrProj_Grenade
	{
	public:
		ADD_STRUCT(int, m_nSecondaryExplosions, 888)
		ADD_OBJECT(ScriptClass, m_SecondaryProjectile, 884)
		Object::Rotator GetRandomSpread(Object::Rotator BaseDirection)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MIRVLauncher.GetRandomSpread");
			byte params[24] = { NULL };
			*(Object::Rotator*)&params[0] = BaseDirection;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		void SpawnSecondaryProjectile(Object::Vector Direction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MIRVLauncher.SpawnSecondaryProjectile");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MIRVLauncher.Explode");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Bounce(class Actor* Other, Object::Vector WallNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MIRVLauncher.Bounce");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = WallNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
