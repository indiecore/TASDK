#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFBase : public UTGameObjective
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, MIC_FlagBaseColor)
		ADD_OBJECT(MaterialInstanceConstant, FlagBaseMaterial)
		ADD_VAR(::FloatProperty, BaseExitTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NearBaseRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidFieldLowZOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidFieldHighZOffset, 0xFFFFFFFF)
		ADD_OBJECT(UTCarriedObject, myFlag)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
