#pragma once
#include "Engine.InterpTrackFloatMaterialParam.h"
#include "Engine.InterpTrackInst.h"
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
	class InterpTrackInstFloatMaterialParam : public InterpTrackInst
	{
	public:
		class FloatMaterialParamMICData
		{
		public:
			ADD_STRUCT(ScriptArray<class MaterialInstanceConstant*>, MICs, 0)
			ADD_STRUCT(ScriptArray<float>, MICResetFloats, 12)
		};
		ADD_STRUCT(ScriptArray<InterpTrackInstFloatMaterialParam::FloatMaterialParamMICData>, MICInfos, 60)
		ADD_OBJECT(InterpTrackFloatMaterialParam, InstancedTrack, 72)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
