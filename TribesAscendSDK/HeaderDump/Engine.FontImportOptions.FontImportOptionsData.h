#pragma once
#include "Core.Object.LinearColor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " FontImportOptions.FontImportOptionsData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty FontImportOptions.FontImportOptionsData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FontImportOptionsData
	{
	public:
		ADD_VAR(::StrProperty, FontName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Height, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableAntialiasing, 0x1)
		ADD_VAR(::BoolProperty, bEnableBold, 0x2)
		ADD_VAR(::BoolProperty, bEnableItalic, 0x4)
		ADD_VAR(::BoolProperty, bEnableUnderline, 0x8)
		ADD_VAR(::BoolProperty, bAlphaOnly, 0x10)
		ADD_VAR(::ByteProperty, CharacterSet, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Chars, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UnicodeRange, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CharsFilePath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CharsFileWildcard, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCreatePrintableOnly, 0x1)
		ADD_VAR(::BoolProperty, bIncludeASCIIRange, 0x2)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, ForegroundColor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableDropShadow, 0x1)
		ADD_VAR(::IntProperty, TexturePageWidth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TexturePageMaxHeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, XPadding, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, YPadding, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ExtendBoxTop, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ExtendBoxBottom, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ExtendBoxRight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ExtendBoxLeft, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableLegacyMode, 0x1)
		ADD_VAR(::IntProperty, Kerning, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseDistanceFieldAlpha, 0x1)
		ADD_VAR(::IntProperty, DistanceFieldScaleFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DistanceFieldScanRadiusScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
