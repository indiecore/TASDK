#pragma once
#include "TribesGame__TrProj_Mine.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_PrismMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_PrismMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_PrismMine." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_PrismMine : public TrProj_Mine
	{
	public:
		ADD_STRUCT(::VectorProperty, r_vRightHit, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, r_vLeftHit, 0xFFFFFFFF
		ADD_VAR(::NameProperty, m_nSocketTraceName, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, m_LaserTemplate)
		ADD_VAR(::FloatProperty, m_fTripDistance, 0xFFFFFFFF)
		ADD_OBJECT(TrTripActor, m_TripActor)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_TrTripNotifier'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
