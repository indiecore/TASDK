#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrOrientedBoxComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrOrientedBoxComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrOrientedBoxComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrOrientedBoxComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::FloatProperty, BoxLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoxWidth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoxHeight, 0xFFFFFFFF )
			void SetBoxSize( float NewHeight, float NewLength, float NewWidth, bool IsRadii )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrOrientedBoxComponent.SetBoxSize" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = NewHeight;
				*( float* )( params + 4 ) = NewLength;
				*( float* )( params + 8 ) = NewWidth;
				*( bool* )( params + 12 ) = IsRadii;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
