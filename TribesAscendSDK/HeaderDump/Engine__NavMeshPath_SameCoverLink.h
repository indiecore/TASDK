#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshPath_SameCoverLink." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshPath_SameCoverLink." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshPath_SameCoverLink." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshPath_SameCoverLink : public NavMeshPathConstraint
	{
	public:
			ADD_OBJECT( CoverLink, TestLink )
			void SameCoverLink( class NavigationHandle* NavHandle, class CoverLink* InLink )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshPath_SameCoverLink.SameCoverLink" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class NavigationHandle** )params = NavHandle;
				*( class CoverLink** )( params + 4 ) = InLink;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshPath_SameCoverLink.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
