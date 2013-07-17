#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKScriptedNavigationPoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKScriptedNavigationPoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKScriptedNavigationPoint." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKScriptedNavigationPoint : public NavigationPoint
	{
	public:
			ADD_VAR( ::BoolProperty, bAnchorMustBeReachable, 0x4 )
			ADD_VAR( ::BoolProperty, bScriptNotifyAnchorFindingResult, 0x2 )
			ADD_VAR( ::BoolProperty, bScriptSpecifyEndAnchor, 0x1 )
			class NavigationPoint* SpecifyEndAnchor( class Pawn* RouteFinder )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKScriptedNavigationPoint.SpecifyEndAnchor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = RouteFinder;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

			void NotifyAnchorFindingResult( class NavigationPoint* EndAnchor, class Pawn* RouteFinder )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKScriptedNavigationPoint.NotifyAnchorFindingResult" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class NavigationPoint** )( params + 0 ) = EndAnchor;
				*( class Pawn** )( params + 4 ) = RouteFinder;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
