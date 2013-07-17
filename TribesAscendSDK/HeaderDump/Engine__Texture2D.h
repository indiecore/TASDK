#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Texture2D." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Texture2D." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Texture2D." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Texture2D : public Texture
	{
	public:
			ADD_VAR( ::FloatProperty, Timer, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FirstResourceMemMip, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MipTailBaseIdx, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StreamingIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ResidentMips, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RequestedMips, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, TextureFileCacheName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceMipLevelsToBeResidentTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bGlobalForceMipLevelsToBeResident, 0x10 )
			ADD_VAR( ::BoolProperty, bForceMiplevelsToBeResident, 0x8 )
			ADD_VAR( ::BoolProperty, bHasBeenLoadedFromPersistentArchive, 0x4 )
			ADD_VAR( ::BoolProperty, bHasCancelationPending, 0x2 )
			ADD_VAR( ::BoolProperty, bIsStreamable, 0x1 )
			ADD_VAR( ::ByteProperty, AddressY, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AddressX, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Format, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OriginalSizeY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OriginalSizeX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeX, 0xFFFFFFFF )
			void SetForceMipLevelsToBeResident( float Seconds, int CinematicTextureGroups )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Texture2D.SetForceMipLevelsToBeResident" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = Seconds;
				*( int* )( params + 4 ) = CinematicTextureGroups;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Texture2D* Create( int InSizeX, int InSizeY, byte InFormat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Texture2D.Create" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( int* )( params + 0 ) = InSizeX;
				*( int* )( params + 4 ) = InSizeY;
				*( byte* )( params + 8 ) = InFormat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Texture2D** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
