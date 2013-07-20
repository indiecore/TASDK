#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MorphNodeMultiPose." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MorphNodeMultiPose." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MorphNodeMultiPose." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MorphNodeMultiPose : public MorphNodeBase
	{
	public:
			bool AddMorphTarget( ScriptName MorphTargetName, float InWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MorphNodeMultiPose.AddMorphTarget" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = MorphTargetName;
				*( float* )( params + 8 ) = InWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RemoveMorphTarget( ScriptName MorphTargetName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MorphNodeMultiPose.RemoveMorphTarget" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = MorphTargetName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool UpdateMorphTarget( class MorphTarget* Target, float InWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MorphNodeMultiPose.UpdateMorphTarget" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class MorphTarget** )params = Target;
				*( float* )( params + 4 ) = InWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
