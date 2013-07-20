#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrSkeletalMeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrSkeletalMeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrSkeletalMeshComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSkeletalMeshComponent : public SkeletalMeshComponent
	{
	public:
			ADD_VAR( ::FloatProperty, m_fClearStreamingTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bForceLoadTextures, 0x1 )
			ADD_VAR( ::FloatProperty, m_fFOV, 0xFFFFFFFF )
			void PreloadTextures( bool bForcePreload, float ClearTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSkeletalMeshComponent.PreloadTextures" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bForcePreload;
				*( float* )( params + 4 ) = ClearTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFOV( float NewFOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSkeletalMeshComponent.SetFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewFOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
