#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SoundNodeWave." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SoundNodeWave." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SoundNodeWave." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SoundNodeWave : public SoundNode
	{
	public:
			ADD_VAR( ::StrProperty, SourceFileTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SourceFilePath, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Comment, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ResourceSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ResourceID, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RawPCMDataSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SampleRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumChannels, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Duration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Pitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Volume, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SpokenText, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, DecompressionType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, TTSSpeaker, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bManualWordWrap, 0x40 )
			ADD_VAR( ::BoolProperty, bMature, 0x20 )
			ADD_VAR( ::BoolProperty, bProcedural, 0x10 )
			ADD_VAR( ::BoolProperty, bUseTTS, 0x8 )
			ADD_VAR( ::BoolProperty, bDynamicResource, 0x4 )
			ADD_VAR( ::BoolProperty, bLoopingSound, 0x2 )
			ADD_VAR( ::BoolProperty, bForceRealTimeDecompression, 0x1 )
			ADD_VAR( ::IntProperty, CompressionQuality, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
