#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Path_MinDistBetweenSpecsOfType." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Path_MinDistBetweenSpecsOfType." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Path_MinDistBetweenSpecsOfType." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Path_MinDistBetweenSpecsOfType : public PathConstraint
	{
	public:
			ADD_OBJECT( ScriptClass, ReachSpecClass )
			ADD_STRUCT( ::VectorProperty, InitLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinDistBetweenSpecTypes, 0xFFFFFFFF )
			bool EnforceMinDist( class Pawn* P, float InMinDist, ScriptClass* InSpecClass, Vector LastLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Path_MinDistBetweenSpecsOfType.EnforceMinDist" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Pawn** )params = P;
				*( float* )( params + 4 ) = InMinDist;
				*( ScriptClass** )( params + 8 ) = InSpecClass;
				*( Vector* )( params + 12 ) = LastLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Path_MinDistBetweenSpecsOfType.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
