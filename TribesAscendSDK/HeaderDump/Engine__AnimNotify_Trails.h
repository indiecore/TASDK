#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNotify_Trails." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNotify_Trails." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNotify_Trails." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNotify_Trails : public AnimNotify
	{
	public:
			ADD_OBJECT( AnimNodeSequence, AnimNodeSeq )
			ADD_VAR( ::FloatProperty, TimeStep, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SamplesPerSecond, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SampleTimeStep, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EndTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastStartTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SecondEdgeSocketName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ControlPointSocketName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, FirstEdgeSocketName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bResampleRequired, 0x8 )
			ADD_VAR( ::BoolProperty, bSkipIfOwnerIsHidden, 0x4 )
			ADD_VAR( ::BoolProperty, bPreview, 0x2 )
			ADD_VAR( ::BoolProperty, bIsExtremeContent, 0x1 )
			ADD_OBJECT( ParticleSystem, PSTemplate )
			int GetNumSteps( int InLastTrailIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNotify_Trails.GetNumSteps" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = InLastTrailIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
