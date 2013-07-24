#pragma once
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_CallInBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_CallInBase : public TrProjectile
	{
	public:
		ADD_STRUCT(::VectorProperty, r_TargetLocation, 0xFFFFFFFF
	};
}
#undef ADD_STRUCT
