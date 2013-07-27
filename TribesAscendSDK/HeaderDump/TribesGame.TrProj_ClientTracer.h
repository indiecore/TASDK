#pragma once
#include "TribesGame.TrProjectile.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_ClientTracer : public TrProjectile
	{
	public:
		ADD_OBJECT(ScriptClass, m_InheritedClass, 816)
		void InitProjectile(Object::Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ClientTracer.InitProjectile");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundCue* GetExplosionSound(class PhysicalMaterial* HitMaterial, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ClientTracer.GetExplosionSound");
			byte params[12] = { NULL };
			*(class PhysicalMaterial**)&params[0] = HitMaterial;
			*(class Actor**)&params[4] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[8];
		}
		void ProcessTouch(class Actor* Other, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ClientTracer.ProcessTouch");
			byte params[28] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
