#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNotify_ViewShake." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNotify_ViewShake." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNotify_ViewShake." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNotify_ViewShake : public AnimNotify_Scripted
	{
	public:
			ADD_OBJECT( CameraShake, ShakeParams )
			ADD_VAR( ::NameProperty, BoneName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShakeRadius, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseBoneLocation, 0x2 )
			ADD_VAR( ::BoolProperty, bDoControllerVibration, 0x1 )
			ADD_VAR( ::FloatProperty, FOVFrequency, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FOVAmplitude, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LocFrequency, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LocAmplitude, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RotFrequency, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RotAmplitude, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Duration, 0xFFFFFFFF )
			void Notify( class Actor* Owner, class AnimNodeSequence* AnimSeqInstigator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNotify_ViewShake.Notify" );
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
