#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_MotionSensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDeployable_MotionSensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployable_MotionSensor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployable_MotionSensor : public TrDeployable_Sensor
	{
	public:
		ADD_OBJECT(Texture2D, m_AlarmIcon)
		ADD_STRUCT(::VectorProperty, LastCameraPos, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastCameraDir, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastScreenLoc, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_IconAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHUDAlarmTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bDrawHUDAlarm, 0x1)
		ADD_VAR(::FloatProperty, m_fLastAlarmTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeBetweenAlarms, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMotionSenseExpireTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
