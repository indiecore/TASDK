#pragma once
#include "Core__Object.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GFxUI.GFxDataStoreSubscriber." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxUI.GFxDataStoreSubscriber." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxDataStoreSubscriber : public Object
	{
	public:
		ADD_OBJECT(GFxMoviePlayer, Movie)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIDataStorePublisher'!
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
