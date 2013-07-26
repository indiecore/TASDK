#pragma once
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.UntypedBulkData_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.UntypedBulkData_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UntypedBulkData_Mirror
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BulkDataFlags, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ElementCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BulkDataOffsetInFile, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BulkDataSizeOnDisk, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SavedBulkDataFlags, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SavedElementCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SavedBulkDataOffsetInFile, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SavedBulkDataSizeOnDisk, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, BulkData, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LockStatus, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, AttachedAr, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bShouldFreeOnEmpty, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
