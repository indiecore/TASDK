#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNotify_PlayFaceFXAnim." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNotify_PlayFaceFXAnim." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNotify_PlayFaceFXAnim." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNotify_PlayFaceFXAnim : public AnimNotify_Scripted
	{
	public:
			ADD_VAR( ::FloatProperty, PlayFrequency, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOverridePlayingAnim, 0x1 )
			ADD_OBJECT( SoundCue, SoundCueToPlay )
			ADD_VAR( ::StrProperty, AnimName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GroupName, 0xFFFFFFFF )
			ADD_OBJECT( FaceFXAnimSet, FaceFXAnimSetRef )
			void Notify( class Actor* Owner, class AnimNodeSequence* AnimSeqInstigator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNotify_PlayFaceFXAnim.Notify" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )( params + 0 ) = Owner;
				*( class AnimNodeSequence** )( params + 4 ) = AnimSeqInstigator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
