#pragma once
#include "TribesGame.TrProj_Mine.h"
#include "Engine.Texture2D.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_Claymore." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_Claymore : public TrProj_Mine
	{
	public:
		ADD_VAR(::FloatProperty, m_fScalarAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDetonationAngle, 0xFFFFFFFF)
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Claymore.InitProjectile");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Direction;
			*(ScriptClass**)(params + 12) = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetExplosionEffectParameters(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* ProjExplosion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Claymore.SetExplosionEffectParameters");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = ProjExplosion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnEnteredDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Claymore.PawnEnteredDetonationArea");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Claymore.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
