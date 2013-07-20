#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshPath_WithinTraversalDist." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshPath_WithinTraversalDist." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshPath_WithinTraversalDist." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshPath_WithinTraversalDist : public NavMeshPathConstraint
	{
	public:
			ADD_VAR( ::FloatProperty, SoftStartPenalty, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSoft, 0x1 )
			ADD_VAR( ::FloatProperty, MaxTraversalDist, 0xFFFFFFFF )
			bool DontExceedMaxDist( class NavigationHandle* NavHandle, float InMaxTraversalDist, bool bInSoft )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshPath_WithinTraversalDist.DontExceedMaxDist" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class NavigationHandle** )params = NavHandle;
				*( float* )( params + 4 ) = InMaxTraversalDist;
				*( bool* )( params + 8 ) = bInSoft;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshPath_WithinTraversalDist.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
