#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Route." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Route." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Route." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Route : public Info
	{
	public:
			ADD_VAR( ::ByteProperty, RouteType, 0xFFFFFFFF )
			int ResolveRouteIndex( int Idx, byte RouteDirection, byte &out_bComplete, byte &out_bReverse )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Route.ResolveRouteIndex" );
				byte *params = ( byte* )( malloc( 7 ) );
				*( int* )( params + 0 ) = Idx;
				*( byte* )( params + 4 ) = RouteDirection;
				*( byte* )( params + 5 ) = out_bComplete;
				*( byte* )( params + 6 ) = out_bReverse;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_bComplete = *( byte* )( params + 5 );
				out_bReverse = *( byte* )( params + 6 );
				return *( int* )( params + function->return_val_offset() );
			}

			int MoveOntoRoutePath( class Pawn* P, byte RouteDirection, float DistFudgeFactor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Route.MoveOntoRoutePath" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( class Pawn** )( params + 0 ) = P;
				*( byte* )( params + 4 ) = RouteDirection;
				*( float* )( params + 8 ) = DistFudgeFactor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, FudgeFactor, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RouteIndexOffset, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
