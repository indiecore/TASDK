#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_LaserTargeter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDevice_LaserTargeter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_LaserTargeter." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_LaserTargeter : public TrDevice_ConstantFire
	{
	public:
		ADD_VAR(::ByteProperty, r_ActiveCallin, 0xFFFFFFFF)
		ADD_OBJECT(TrCallIn, r_CallIns)
		ADD_STRUCT(::VectorProperty, m_LastTargetPos, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, m_LastOwnerRot, 0xFFFFFFFF
		ADD_OBJECT(SoundCue, m_CallInConfirmation)
		ADD_VAR(::ByteProperty, m_PrevActiveCallin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCallInEndTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
