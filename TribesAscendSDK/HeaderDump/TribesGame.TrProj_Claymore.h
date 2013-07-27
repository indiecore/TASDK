#pragma once
#include "TribesGame.TrProj_Mine.h"
#include "Core.Object.h"
#include "Engine.Texture2D.h"
#include "Engine.Pawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrProj_Claymore : public TrProj_Mine
	{
	public:
		ADD_STRUCT(float, m_fScalarAngle, 904)
		ADD_STRUCT(float, m_fDetonationAngle, 900)
		void InitProjectile(Object::Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Claymore.InitProjectile");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetExplosionEffectParameters(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* ProjExplosion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Claymore.SetExplosionEffectParameters");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = ProjExplosion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnEnteredDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Claymore.PawnEnteredDetonationArea");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Claymore.GetMarker");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)&params[0];
		}
	};
}
#undef ADD_STRUCT
