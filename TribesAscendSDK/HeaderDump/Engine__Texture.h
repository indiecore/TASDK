#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Texture." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Texture." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Texture." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Texture : public Surface
	{
	public:
			ADD_VAR( ::IntProperty, InternalFormatLODBias, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustHue, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustRGBCurve, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustSaturation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustVibrance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustBrightnessCurve, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustBrightness, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SourceFileTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SourceFilePath, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumCinematicMipLevels, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CachedCombinedLODBias, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LODBias, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, MipGenSettings, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LODGroup, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Filter, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CompressionSettings, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UnpackMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UnpackMin, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseCinematicMipLevels, 0x20000 )
			ADD_VAR( ::BoolProperty, bAsyncResourceReleaseHasBeenStarted, 0x10000 )
			ADD_VAR( ::BoolProperty, bForcePVRTC4, 0x8000 )
			ADD_VAR( ::BoolProperty, bNoTiling, 0x4000 )
			ADD_VAR( ::BoolProperty, bPreserveBorderA, 0x2000 )
			ADD_VAR( ::BoolProperty, bPreserveBorderB, 0x1000 )
			ADD_VAR( ::BoolProperty, bPreserveBorderG, 0x800 )
			ADD_VAR( ::BoolProperty, bPreserveBorderR, 0x400 )
			ADD_VAR( ::BoolProperty, bDitherMipMapAlpha, 0x200 )
			ADD_VAR( ::BoolProperty, NeverStream, 0x100 )
			ADD_VAR( ::BoolProperty, DeferCompression, 0x80 )
			ADD_VAR( ::BoolProperty, CompressionFullDynamicRange, 0x40 )
			ADD_VAR( ::BoolProperty, CompressionNoMipmaps, 0x20 )
			ADD_VAR( ::BoolProperty, CompressionNone, 0x10 )
			ADD_VAR( ::BoolProperty, CompressionNoAlpha, 0x8 )
			ADD_VAR( ::BoolProperty, bIsSourceArtUncompressed, 0x4 )
			ADD_VAR( ::BoolProperty, RGBE, 0x2 )
			ADD_VAR( ::BoolProperty, SRGB, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
