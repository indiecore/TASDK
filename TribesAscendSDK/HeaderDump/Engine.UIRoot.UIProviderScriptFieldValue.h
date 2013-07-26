#pragma once
#include "Engine.UIRoot.UIRangeData.h"
#include "Engine.UIRoot.TextureCoordinates.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.Surface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIRoot.UIProviderScriptFieldValue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UIRoot.UIProviderScriptFieldValue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UIRoot.UIProviderScriptFieldValue." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIProviderScriptFieldValue
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, AtlasCoordinates, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, NetIdValue, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UIRangeData>, RangeValue, 0xFFFFFFFF)
		ADD_OBJECT(Surface, ImageValue)
		ADD_VAR(::StrProperty, StringValue, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PropertyType, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PropertyTag, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
