#pragma once
#include "Engine.InterpFilter.h"
#include "Engine.SequenceVariable.h"
#include "Engine.InterpGroup.h"
#include "Engine.InterpCurveEdSetup.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class InterpData : public SequenceVariable
	{
	public:
		class AnimSetBakeAndPruneStatus
		{
		public:
			ADD_BOOL(bSkipBakeAndPrune, 12, 0x2)
			ADD_BOOL(bReferencedButUnused, 12, 0x1)
			ADD_STRUCT(ScriptString*, AnimSetName, 0)
		};
		ADD_STRUCT(ScriptArray<class InterpGroup*>, InterpGroups, 156)
		ADD_STRUCT(ScriptArray<class InterpFilter*>, InterpFilters, 172)
		ADD_STRUCT(ScriptArray<class InterpFilter*>, DefaultFilters, 188)
		ADD_STRUCT(ScriptArray<InterpData::AnimSetBakeAndPruneStatus>, BakeAndPruneStatus, 212)
		ADD_BOOL(bShouldBakeAndPrune, 208, 0x1)
		ADD_STRUCT(float, EdSectionEnd, 204)
		ADD_STRUCT(float, EdSectionStart, 200)
		ADD_OBJECT(InterpFilter, SelectedFilter, 184)
		ADD_OBJECT(InterpCurveEdSetup, CurveEdSetup, 168)
		ADD_STRUCT(float, PathBuildTime, 152)
		ADD_STRUCT(float, InterpLength, 148)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
