#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKSkeletalMeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKSkeletalMeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKSkeletalMeshComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkeletalMeshComponent : public SkeletalMeshComponent
	{
	public:
			ADD_VAR( ::FloatProperty, ClearStreamingTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceLoadTextures, 0x1 )
			ADD_VAR( ::FloatProperty, FOV, 0xFFFFFFFF )
			void PreloadTextures( bool bForcePreload, float ClearTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKSkeletalMeshComponent.PreloadTextures" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bForcePreload;
				*( float* )( params + 4 ) = ClearTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFOV( float NewFOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKSkeletalMeshComponent.SetFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = NewFOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
