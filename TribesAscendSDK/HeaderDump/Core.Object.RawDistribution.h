#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.RawDistribution." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RawDistribution
	{
	public:
		ADD_VAR(::ByteProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Op, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LookupTableNumElements, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LookupTableChunkSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookupTableTimeScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookupTableStartTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
